#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""`python -m script.leetcode.submit` 的命令行入口。"""

import argparse
import os
import sys
from pathlib import Path

from script.leetcode.submit import http_api, pending_queue
from script.leetcode.submit.rate_limit import should_pause_submission_queue
from script.leetcode.submit.submitter import LeetCodeSubmitter
from script.leetcode.utils import ColorCode, color_text, log_with_time


def main() -> None:
    parser = argparse.ArgumentParser(
        description="将本地代码转换为 LeetCode 格式并提交验证",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
示例:
  # 转换并提交题目 1
  python -m script.leetcode.submit 1

  # 使用第2个解法
  python -m script.leetcode.submit 1 --solution 2

  # 所有策略都提交一遍（走翻译缓存 + 6s 节流）
  python -m script.leetcode.submit 1 --all

  # 只交指定策略
  python -m script.leetcode.submit 1 --strategies 2,3
        """,
    )
    parser.add_argument("id", type=int, nargs="?", help="题目 ID")
    parser.add_argument(
        "--queue",
        action="store_true",
        help="按共享退避策略消费待提交队列，遇到 429 自动停止",
    )
    parser.add_argument(
        "--solution", "-n",
        type=int, default=0,
        help="使用第 n 个 registerStrategy;默认 0 表示最后一个 = 按项目约定的最优解",
    )
    parser.add_argument(
        "--all",
        action="store_true",
        help="把源文件里每个 registerStrategy 都翻译并提交一遍",
    )
    parser.add_argument(
        "--strategies",
        type=lambda s: [int(x.strip()) for x in s.split(",") if x.strip()],
        default=None,
        help="逗号分隔的 1-indexed 策略列表，例如 --strategies 2,3；与 --all 配合使用表示'仅提交这些'",
    )

    args = parser.parse_args()
    if args.queue:
        if args.id is not None:
            parser.error("--queue 不能和题目 ID 同时使用")
        os.environ.setdefault(
            "AI_SOLVER_SUBMIT_LOCK",
            str(Path(".ai-run-logs/leetcode-submit.lock").resolve()),
        )
        os.environ.setdefault("AI_SOLVER_SUBMIT_INTERVAL", "60")
        sys.exit(0 if _run_queue() else 1)
    if args.id is None:
        parser.error("需要题目 ID，或使用 --queue")
    try:
        submitter = LeetCodeSubmitter()
        if args.all or args.strategies:
            _run_multi(submitter, args)
            return
        success = submitter.submit_problem(args.id, args.solution)
        sys.exit(0 if success else 1)
    except Exception as e:
        print(color_text(f"❌ 错误: {e}", ColorCode.RED.value))
        sys.exit(1)


def _run_multi(submitter: LeetCodeSubmitter, args: argparse.Namespace) -> None:
    results = submitter.submit_all_solutions(args.id, strategies=args.strategies)
    print()
    log_with_time("━━━ 全策略提交汇总 ━━━", ColorCode.MAGENTA)
    bad = 0
    for n, r, expected in results:
        match = r.status == expected
        mark = "✅" if match else "❌"
        note = "" if expected == "Accepted" else f" [预期 {expected}]"
        extra = (
            f" ({r.passed_test_cases}/{r.total_test_cases})"
            if r.status == "Wrong Answer"
            else ""
        )
        log_with_time(f"  解 {n}: {mark} {r.status}{note}{extra}", ColorCode.CYAN)
        if not match:
            bad += 1
    sys.exit(1 if bad else 0)


def _run_queue() -> bool:
    all_ids = pending_queue.pending_problem_ids()
    if not all_ids:
        print("✅ 待提交队列为空")
        return True
    ids = pending_queue.eligible_problem_ids()
    if not ids:
        print(f"⏸️ 待提交队列全部处于不确定结果隔离窗口（{len(all_ids)} 题）")
        return True

    held_count = len(all_ids) - len(ids)
    held_note = f"，另有 {held_count} 题处于隔离窗口" if held_count else ""
    print(f"📦 待提交队列: {len(ids)} 题（共享限流器串行消费{held_note}）")
    submitter = LeetCodeSubmitter()
    all_accepted = True
    for problem_id in ids:
        log_with_time(f"━━━ 队列提交题目 {problem_id} ━━━", ColorCode.MAGENTA)
        result = submitter.submit_problem_with_result(problem_id)
        accepted = http_api.print_verdict(result)
        if accepted:
            pending_queue.remove(problem_id)
            continue

        all_accepted = False
        if should_pause_submission_queue(result):
            if result.status == "Error" and result.error_type == "network_error":
                reason = "网络请求结果不确定"
                machine_reason = "uncertain_network"
            elif result.status == "Timeout" or result.error_type == "poll_timeout":
                reason = "判题结果不确定"
                machine_reason = "uncertain_poll"
            elif result.error_type == "submit_response_missing_id":
                reason = "提交响应不完整"
                machine_reason = "uncertain_submit_response"
            elif result.error_type == "unexpected_error":
                reason = "提交过程异常"
                machine_reason = "uncertain_submit_error"
            else:
                reason = "再次触发限流"
                machine_reason = "rate_limited"
            if machine_reason.startswith("uncertain_"):
                hold_seconds = pending_queue.uncertain_hold_seconds()
                pending_queue.defer(
                    problem_id,
                    reason=machine_reason,
                    delay_seconds=hold_seconds,
                )
                log_with_time(
                    f"🛡️ 已隔离题目 {problem_id} {hold_seconds / 60:.0f} 分钟，避免不确定结果导致重复提交",
                    ColorCode.YELLOW,
                )
            log_with_time(f"⏸️ {reason}，保留剩余队列并停止", ColorCode.YELLOW)
            break
    return all_accepted


if __name__ == "__main__":
    main()
