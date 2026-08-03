#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""LeetCode 提交编排器。

把"读本地代码 → 选策略 → AI 翻译 → HTTP 提交 → 判题"串起来。
底层 HTTP 走 `http_api`，翻译走 `translator`（带缓存），多解批量走
`submit_all_solutions`。
"""

import os
import re
import time
from pathlib import Path
from typing import List, Optional, Tuple

from dotenv import load_dotenv
from openai import OpenAI

from script.leetcode.api.repository import ProblemRepository
from script.leetcode.config import AIConfig, AIProvider
from script.leetcode.cookie import prepare_cookie
from script.leetcode.models import ProblemData
from script.leetcode.submit import cache, expected_verdicts, http_api, translator
from script.leetcode.submit.http_api import LeetCodeHttpClient
from script.leetcode.submit.rate_limit import is_rate_limited_result, submission_rate_limit
from script.leetcode.submit.result import SubmissionResult
from script.leetcode.utils import ColorCode, color_text, log_with_time

_CACHE_DIR = Path(".leetcode-cache/submit")


class LeetCodeSubmitter:
    def __init__(self):
        load_dotenv()
        self.repo = ProblemRepository()
        raw_cookie = os.getenv("LEETCODE_COOKIE")
        self.cookie, self.csrf_token = (
            prepare_cookie(raw_cookie) if raw_cookie else (None, None)
        )
        self._init_ai_client()

        if not self.cookie:
            print(color_text("⚠️  未设置 LEETCODE_COOKIE 环境变量", ColorCode.YELLOW.value))
            print("提交功能需要 Cookie，但转换功能可用\n")
            self.cookie_valid = False
            self._http: Optional[LeetCodeHttpClient] = None
            return

        self.cookie_valid = http_api.validate_cookie(self.cookie, self.csrf_token)
        if not self.cookie_valid:
            print(color_text("⚠️  Cookie 验证失败，但仍将尝试提交", ColorCode.YELLOW.value))
            print("如果提交失败，请检查网络连接或重新登录 LeetCode\n")
            # 验证失败不阻止提交，让提交本身来说话
            self.cookie_valid = True
        self._http = LeetCodeHttpClient(self.cookie, self.csrf_token)

    def _init_ai_client(self) -> None:
        self.provider = AIProvider.from_env()
        env_var = self.provider.api_key_env()
        api_key = os.getenv(env_var) or os.getenv("AI_API_KEY")
        if not api_key:
            raise ValueError(f"请设置 {env_var} 或 AI_API_KEY")
        # Translation is part of the durable submission queue.  Give the SDK
        # a hard socket timeout so one stalled conversion cannot hold the
        # queue forever; the solver API client uses the same guard.
        self.ai_client = OpenAI(
            api_key=api_key,
            base_url=self.provider.base_url,
            timeout=AIConfig.STREAM_TIMEOUT_SECONDS,
        )
        self.ai_model = self.provider.model

    # ---- public entries ----

    def submit_problem(self, problem_id: int, solution_num: int = 0) -> bool:
        """命令行入口：翻译 + 提交 + 打印结果。返回是否 Accepted。"""
        try:
            problem_data = self.repo.get_detail_by_id(problem_id, include_code=True)
            print(f"📋 题目: [{problem_id}] {problem_data.title}")
            print(f"🔗 https://leetcode.com/problems/{problem_data.slug}/")
            print()
        except Exception as e:
            print(color_text(f"❌ 获取题目信息失败: {e}", ColorCode.RED.value))
            return False

        code = self._translate_local(problem_data, solution_num)
        if code is None:
            return False

        if not self._http:
            self._print_missing_cookie_hint()
            return True

        log_with_time("🤖 AI 转换中...")
        question_id = self._get_question_id(problem_id)
        if not question_id:
            log_with_time("❌ 无法获取题目内部 ID", ColorCode.RED)
            return False

        result = self._submit_http(problem_data.slug, question_id, code)
        return http_api.print_verdict(result)

    def submit_problem_with_result(self, problem_id: int, solution_num: int = 0) -> SubmissionResult:
        """AI 修复循环入口：返回 SubmissionResult 而非打印。"""
        try:
            problem_data = self.repo.get_detail_by_id(problem_id, include_code=True)
        except Exception as e:
            return SubmissionResult(status="Error", status_code=-1, error_message=str(e))

        code = self._translate_local(problem_data, solution_num)
        if code is None:
            return SubmissionResult(
                status="Error", status_code=-1, error_message="无法读取源代码或翻译失败",
            )

        if not self._http:
            return SubmissionResult(
                status="Error",
                status_code=-1,
                error_message="未设置 LEETCODE_COOKIE" if not self.cookie else "LEETCODE_COOKIE 无效或已过期",
            )

        question_id = self._get_question_id(problem_id)
        if not question_id:
            return SubmissionResult(
                status="Error", status_code=-1, error_message="无法获取题目内部 ID",
            )
        return self._submit_http(problem_data.slug, question_id, code)

    def submit_all_solutions(
        self, problem_id: int, strategies: Optional[list] = None
    ) -> List[Tuple[int, SubmissionResult, str]]:
        """遍历 registerStrategy 批量提交。

        `strategies=None` 提交全部；列出则只交这些 1-indexed 索引。
        返回 `[(n, SubmissionResult, expected_status), ...]`。Compile Error 自动
        失效翻译缓存重试一次；明确的 429/503 不在当前进程内重试，而是交给
        共享退避队列，避免把一次限流放大成连续请求。
        """
        try:
            problem_data = self.repo.get_detail_by_id(problem_id, include_code=True)
        except Exception as e:
            return [(0, SubmissionResult(status="Error", status_code=-1, error_message=str(e)), "Accepted")]

        _, source_code = self._read_local_code(problem_data.slug)
        if not source_code:
            return [(0, SubmissionResult(status="Error", status_code=-1, error_message="无法读取源代码"), "Accepted")]

        count = len(re.findall(r"\bregisterStrategy\s*\(", source_code))
        expected_map = expected_verdicts.parse_expected_verdicts(source_code)

        if count == 0:
            expected = expected_verdicts.resolve_expected(expected_map, 1)
            return [(1, self.submit_problem_with_result(problem_id, 1), expected)]

        requested = (
            set(range(1, count + 1))
            if strategies is None
            else {n for n in strategies if 1 <= n <= count}
        )
        if not requested:
            log_with_time(
                f"⚠️ --strategies 过滤后没有可提交的解（源文件有 {count} 个策略）",
                ColorCode.YELLOW,
            )
            return []

        results: List[Tuple[int, SubmissionResult, str]] = []
        first = True
        for n in sorted(requested):
            print()
            expected = expected_verdicts.resolve_expected(expected_map, n)
            tag = f"策略 {n}/{count}"
            if expected != "Accepted":
                tag += f"（期望 {expected}）"
            log_with_time(f"━━━ {tag} ━━━", ColorCode.MAGENTA)
            # 命中缓存时两次提交间隔极短，LeetCode 每用户限流约 5-6s
            if not first:
                time.sleep(6)
            first = False
            result = self.submit_problem_with_result(problem_id, n)
            if result.status == "Compile Error":
                log_with_time("🔄 Compile Error → 清除翻译缓存后重试", ColorCode.YELLOW)
                cache.invalidate(problem_data.slug, n, source_code)
                time.sleep(6)
                result = self.submit_problem_with_result(problem_id, n)
                if is_rate_limited_result(result):
                    log_with_time(
                        "⏸️ 重试请求被远端限流，本轮停止后续策略，交给共享队列退避",
                        ColorCode.YELLOW,
                    )
                    results.append((n, result, expected))
                    break
            elif result.status == "Error" and is_rate_limited_result(result):
                log_with_time(
                    "⏸️ 提交被远端限流，本轮停止后续策略，交给共享队列退避",
                    ColorCode.YELLOW,
                )
                results.append((n, result, expected))
                break
            elif result.status == "Error":
                log_with_time("🔄 提交 Error（疑似限流）→ 等 15s 重试", ColorCode.YELLOW)
                time.sleep(15)
                result = self.submit_problem_with_result(problem_id, n)
            results.append((n, result, expected))
        return results

    # ---- private helpers ----

    def _submit_http(
        self, slug: str, question_id: str, code: str
    ) -> SubmissionResult:
        """Submit through the shared scheduler (re-entrant under LeetCodeGate)."""
        with submission_rate_limit() as permit:
            if permit.deferred:
                return SubmissionResult(
                    status="Error",
                    status_code=429,
                    error_message="提交队列仍在冷却窗口，已延期到队列",
                    error_type="rate_limited_deferred",
                )
            result = self._http.submit(slug, question_id, code)  # type: ignore[union-attr]
            if is_rate_limited_result(result):
                permit.mark_rate_limited(result.retry_after)
            return result

    def _translate_local(self, problem_data: ProblemData, solution_num: int) -> Optional[str]:
        """读本地 header+source → 解析 solution_num → 走 translator.translate。"""
        header_code, source_code = self._read_local_code(problem_data.slug)
        if not source_code:
            return None
        solution_num = _resolve_solution_num(source_code, solution_num)

        code = translator.translate(
            problem_data, header_code, source_code, solution_num,
            client=self.ai_client, provider=self.provider, model=self.ai_model,
        )
        if code is None:
            return None

        _CACHE_DIR.mkdir(parents=True, exist_ok=True)
        display_path = _CACHE_DIR / f"{problem_data.slug}_leetcode.cpp"
        display_path.write_text(code, encoding="utf-8")
        log_with_time(f"💾 转换后的代码已保存: {display_path}")
        return code

    def _read_local_code(self, slug: str) -> Tuple[Optional[str], Optional[str]]:
        header_path = Path(f"include/leetcode/problems/{slug}.h")
        source_path = Path(f"src/leetcode/problems/{slug}.cpp")

        header_code = header_path.read_text(encoding="utf-8") if header_path.exists() else None
        if not source_path.exists():
            print(color_text(f"❌ 源文件不存在: {source_path}", ColorCode.RED.value))
            return None, None
        return header_code, source_path.read_text(encoding="utf-8")

    def _get_question_id(self, problem_id: int) -> Optional[str]:
        try:
            return str(self.repo.get_detail_by_id(problem_id).question_id)
        except Exception:
            return None

    def _print_missing_cookie_hint(self) -> None:
        if not self.cookie:
            print(color_text("💡 提示: 设置 LEETCODE_COOKIE 后可自动提交到 LeetCode", ColorCode.CYAN.value))
            print("   export LEETCODE_COOKIE='csrftoken=xxx; LEETCODE_SESSION=xxx'")
        else:
            print(color_text("❌ LEETCODE_COOKIE 无效或已过期", ColorCode.RED.value))
            print("   请重新登录 LeetCode 并从浏览器复制新的 Cookie")


def _resolve_solution_num(source_code: str, requested: int) -> int:
    """requested=0 / 负数 → 最后一个 registerStrategy（项目约定的最优解）。"""
    if requested > 0:
        return requested
    count = len(re.findall(r"\bregisterStrategy\s*\(", source_code))
    return count if count > 0 else 1
