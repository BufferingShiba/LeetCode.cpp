#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
AI 自动解题循环模式
持续运行 AI Solve 直到完善所有题解

用法:
    python -m script.leetcode.ai.auto_solver
    python -m script.leetcode.ai.auto_solver --report  # 生成解题报告
    python -m script.leetcode.ai.auto_solver --max-retries 5  # 最大重试次数
"""

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import threading
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime
from pathlib import Path
from typing import Any, Dict, List, Optional, Set

from script.leetcode.utils import ColorCode, color_text


def _merge_process_output(first: object, second: object) -> str:
    """合并正常/超时路径的 subprocess 输出，兼容 str 和 bytes。"""
    def to_text(value: object) -> str:
        if value is None:
            return ""
        if isinstance(value, bytes):
            return value.decode("utf-8", errors="replace")
        return str(value)

    return to_text(first) + to_text(second)


class AutoSolver:
    """自动解题循环器"""
    
    def __init__(
        self,
        report: bool = False,
        max_retries: int = 3,
        retry_delay: int = 60,
        fail_streak_limit: int = 3,
        fail_streak_pause: int = 60,
        api_key: Optional[str] = None,
        base_url: Optional[str] = None,
        require_leetcode: Optional[bool] = None,
        max_problems: Optional[int] = None,
        submit_delay: int = 6,
        metrics_dir: Optional[str] = None,
        workers: int = 1,
    ):
        from script.leetcode.ai import settings

        settings.load_project_env()
        self.start_time = datetime.now()
        self.report = report
        if max_retries < 1:
            raise ValueError("max_retries 必须大于等于 1")
        self.max_retries = max_retries
        self.retry_delay = retry_delay
        self.fail_streak_limit = fail_streak_limit
        self.fail_streak_pause = fail_streak_pause
        self.api_key = api_key
        self.base_url = base_url
        self.require_leetcode = settings.resolve_bool_flag(
            require_leetcode, "LEETCODE_SUBMIT_ENABLED", default=True
        )
        self.max_problems = max_problems
        self.submit_delay = max(0, submit_delay)
        if workers < 1 or workers > 4:
            raise ValueError("workers 必须在 1 到 4 之间")
        self.workers = workers
        configured_metrics_dir = metrics_dir or os.getenv("AI_SOLVER_METRICS_DIR")
        self.metrics_dir = Path(
            configured_metrics_dir
            or f".ai-run-logs/auto-{self.start_time.strftime('%Y%m%d-%H%M%S')}"
        ).resolve()
        self.batch_results_path = self.metrics_dir / "batch_results.jsonl"
        configured_submit_lock = os.getenv("AI_SOLVER_SUBMIT_LOCK")
        self.submit_lock_path = Path(
            configured_submit_lock or ".ai-run-logs/leetcode-submit.lock"
        ).resolve()
        self._merge_lock = threading.Lock()
        
        # 统计信息
        self.total_attempts = 0
        self.success_count = 0
        self.fail_streak = 0
        self.success_streak = 0
        self.failed_problem_ids: Set[int] = set()
        self._last_metrics: Optional[dict] = None
    
    @staticmethod
    def _log(message: str, level: str = "INFO"):
        """打印带时间戳的日志"""
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        level_colors = {
            "INFO": ColorCode.CYAN.value,
            "SUCCESS": ColorCode.GREEN.value,
            "WARNING": ColorCode.YELLOW.value,
            "ERROR": ColorCode.RED.value,
        }
        color = level_colors.get(level, ColorCode.RESET.value)
        level_tag = color_text(f"[{level}]", color)
        print(f"[{timestamp}] {level_tag} {message}")
    
    @staticmethod
    def _get_solved_count() -> int:
        """获取已解决的题目数量"""
        try:
            source_dir = Path("src/leetcode/problems")
            if not source_dir.exists():
                return 0
            return len(list(source_dir.glob("*.cpp")))
        except Exception:
            return 0
    
    def _analyze_failure(self, output: str) -> str:
        """分析失败原因（按优先级顺序匹配）"""
        patterns = [
            ("no_problem", r"No unsolved problems found|没有未解决的题目"),
            ("leetcode_failed", r"LeetCode 验证未通过|Wrong Answer|Runtime Error|Time Limit Exceeded"),
            ("compile_ambiguous", r"ambiguous|call of overloaded"),
            ("compile_error", r"编译失败|error:"),
            ("test_fail", r"测试失败|FAILED"),
            ("api_error", r"API 调用错误|Authentication"),
            ("timeout", r"timeout|超时"),
            ("max_iteration", r"达到最大迭代次数"),
        ]
        
        for fail_type, pattern in patterns:
            if re.search(pattern, output, re.I):
                return fail_type
        return "unknown"
    
    def _build_solve_cmd(self, problem_id: int) -> list:
        """构建解题命令"""
        # 直接使用 Python 调用，避免 just 的缓冲问题
        import sys
        python_exe = sys.executable
        cmd = [python_exe, "-m", "script.leetcode.ai.solver", str(problem_id)]
        if self.report:
            cmd.append("--report")
        if self.base_url:
            cmd.extend(["--base-url", self.base_url])
        if self.require_leetcode is True:
            cmd.append("--require-leetcode")
        elif self.require_leetcode is False:
            cmd.append("--no-leetcode")
        return cmd

    def _retry_preserved_leetcode_submission(
        self, problem_id: int, result: Dict[str, Any]
    ) -> Dict[str, Any]:
        """为本地已通过但在线无结果的题目补一次串行提交。

        隔离 worker 会在这种情况下把三份题解文件汇入主工作区。直接把题目
        标成失败会浪费已经完成的 AI/编译工作，因此只对明确的基础设施错误
        做一次轻量重试；WA/CE/TLE 等代码错误仍保持原失败结果。
        """
        if (
            not self.require_leetcode
            or result.get("success")
            or result.get("error") != "leetcode_infra_error"
            or not result.get("files_preserved")
        ):
            return result

        if self._is_rate_limited_result(result):
            return self._queue_preserved_submission(problem_id, result)

        self._log(
            f"🔁 题目 {problem_id} 本地验证已通过但在线无结果，主工作区重试提交",
            "WARNING",
        )
        command = [sys.executable, "-m", "script.leetcode.submit", str(problem_id)]
        try:
            completed = subprocess.run(
                command,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                timeout=240,
                env=self._build_child_env(),
                check=False,
            )
            retry_output = (completed.stdout or "") + (completed.stderr or "")
            if retry_output:
                print(retry_output, end="")
            if completed.returncode == 0 and re.search(r"Accepted", retry_output, re.I):
                recovered_metrics = dict(result.get("metrics") or {})
                recovered_metrics.update(
                    {
                        "success": True,
                        "leetcode_passed": True,
                        "infra_recovered": True,
                    }
                )
                self._log(f"✅ 题目 {problem_id} 在线提交重试通过", "SUCCESS")
                return {
                    **result,
                    "success": True,
                    "error": None,
                    "metrics": recovered_metrics,
                    "output": result.get("output", "") + retry_output,
                    "recovered": True,
                }
            if self._is_rate_limited_output(retry_output):
                return self._queue_preserved_submission(problem_id, result)
            self._log(
                f"⚠️ 题目 {problem_id} 在线提交重试仍未通过（返回码 {completed.returncode}）",
                "WARNING",
            )
        except subprocess.TimeoutExpired:
            self._log(f"⚠️ 题目 {problem_id} 在线提交重试超时", "WARNING")
        except OSError as exc:
            self._log(f"⚠️ 题目 {problem_id} 在线提交重试启动失败: {exc}", "WARNING")
        return result

    @staticmethod
    def _is_rate_limited_output(output: str) -> bool:
        return bool(
            re.search(
                r"(?:http[_ ](?:429|503|529)|HTTP\s+(?:429|503|529)|限流|rate[ -]?limit)",
                output or "",
                re.IGNORECASE,
            )
        )

    @classmethod
    def _is_rate_limited_result(cls, result: Dict[str, Any]) -> bool:
        metrics = result.get("metrics") or {}
        return metrics.get("skip_reason") == "rate_limited" or cls._is_rate_limited_output(
            str(result.get("output") or "")
        )

    def _queue_preserved_submission(
        self, problem_id: int, result: Dict[str, Any]
    ) -> Dict[str, Any]:
        from script.leetcode.submit import pending_queue

        try:
            queue_file = pending_queue.enqueue(problem_id)
            self._log(
                f"⏸️ 题目 {problem_id} 遇到限流，已加入待提交队列: {queue_file}",
                "WARNING",
            )
            return {
                **result,
                "queued_for_submission": True,
                "submit_queue": str(queue_file),
            }
        except OSError as exc:
            self._log(f"⚠️ 待提交队列写入失败: {exc}", "WARNING")
            return result

    def _build_child_env(self, metrics_dir: Optional[Path] = None) -> dict:
        """构造子进程环境，避免把 API key 放进命令行参数和日志。"""
        env = os.environ.copy()
        env["PYTHONUNBUFFERED"] = "1"
        if self.api_key:
            env["AI_API_KEY"] = self.api_key
            provider_key = {
                "deepseek": "DEEPSEEK_API_KEY",
                "moonshot": "MOONSHOT_API_KEY",
            }.get(env.get("AI_PROVIDER", "moonshot").lower())
            if provider_key:
                env[provider_key] = self.api_key
        env["AI_SOLVER_METRICS_DIR"] = str((metrics_dir or self.metrics_dir).resolve())
        if self.require_leetcode:
            # 即使只有一个 worker，后续手动队列消费也可能共享此账号；
            # 所有自动提交统一经过同一绝对路径做互斥、节流和退避。
            env["AI_SOLVER_SUBMIT_LOCK"] = str(self.submit_lock_path.resolve())
            env["AI_SOLVER_SUBMIT_INTERVAL"] = str(self.submit_delay)
        return env

    def _read_problem_metrics(
        self, problem_id: int, *, newer_than: Optional[float] = None
    ) -> Optional[dict]:
        """读取子进程本题最新 metrics，作为退出码之外的事实来源。"""
        return self._read_metrics_from_dir(
            self.metrics_dir, problem_id, newer_than=newer_than
        )

    @staticmethod
    def _read_metrics_from_dir(
        metrics_dir: Path,
        problem_id: int,
        *,
        newer_than: Optional[float] = None,
    ) -> Optional[dict]:
        """从指定工作区读取本题 metrics。"""
        candidates = []
        for item in metrics_dir.glob(f"metrics_p{problem_id}_*.json"):
            try:
                modified_at = item.stat().st_mtime
            except OSError:
                continue
            if newer_than is not None and modified_at + 0.001 < newer_than:
                continue
            candidates.append((modified_at, item))
        candidates.sort(key=lambda pair: pair[0])
        if not candidates:
            return None
        try:
            return json.loads(candidates[-1][1].read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            return None

    @staticmethod
    def _project_file_state(workspace: Path) -> Dict[Path, tuple[int, int]]:
        """记录题解树文件的大小和 mtime，用于发现 worker 越界改动。"""
        state: Dict[Path, tuple[int, int]] = {}
        for root_name in ("include", "src", "test"):
            root = workspace / root_name
            if not root.exists():
                continue
            for item in root.rglob("*"):
                if not item.is_file():
                    continue
                stat = item.stat()
                state[item.relative_to(workspace)] = (stat.st_size, stat.st_mtime_ns)
        return state

    @staticmethod
    def _copy_isolated_project(workspace: Path) -> None:
        """复制运行 AI 解题所需的最小项目树，不复制 .env / build。"""
        ignore = shutil.ignore_patterns("__pycache__", "*.pyc", ".pytest_cache")
        for directory in ("include", "src", "test", "script"):
            shutil.copytree(directory, workspace / directory, ignore=ignore)
        for filename in ("CMakeLists.txt", "justfile"):
            shutil.copy2(filename, workspace / filename)
        if Path(".leetcode-cache").exists():
            shutil.copytree(
                ".leetcode-cache",
                workspace / ".leetcode-cache",
                ignore=shutil.ignore_patterns("failed-runs"),
            )

    def _persist_worker_metrics(
        self, problem_id: int, attempt: int, metrics: Optional[dict]
    ) -> None:
        """把隔离 worker 的单题指标复制到批次目录，供 aggregate_metrics 使用。"""
        if not metrics:
            return
        try:
            output_path = self.metrics_dir / f"metrics_p{problem_id}_worker{attempt}.json"
            output_path.write_text(
                json.dumps(metrics, ensure_ascii=False, indent=2), encoding="utf-8"
            )
        except OSError as exc:
            self._log(f"⚠️ worker metrics 写入失败: {exc}", "WARNING")

    @staticmethod
    def _new_problem_files(
        workspace: Path, baseline: Dict[Path, tuple[int, int]]
    ) -> tuple[List[Path], List[Path]]:
        current = AutoSolver._project_file_state(workspace)
        added = [item for item in current if item not in baseline]
        modified = [
            item
            for item, state in current.items()
            if item in baseline and baseline[item] != state
        ]
        problem_roots = (
            Path("include/leetcode/problems"),
            Path("src/leetcode/problems"),
            Path("test/leetcode/problems"),
        )
        problem_files = [
            item
            for item in added
            if any(root in item.parents for root in problem_roots)
        ]
        return sorted(problem_files), sorted(modified)

    def _merge_isolated_files(self, workspace: Path, files: List[Path]) -> Optional[str]:
        """把 worker 新增的三份题解原子地汇入主工作区。"""
        categories = {
            Path("include/leetcode/problems"),
            Path("src/leetcode/problems"),
            Path("test/leetcode/problems"),
        }
        file_categories = {
            next((root for root in categories if root in item.parents), None)
            for item in files
        }
        if len(files) != 3 or file_categories != categories:
            return f"expected exactly 3 problem files, got {len(files)}"
        if len({item.stem for item in files}) != 1:
            return "problem files have inconsistent slugs"

        with self._merge_lock:
            for item in files:
                destination = Path(item)
                if destination.exists():
                    return f"merge conflict: {destination} already exists"
            for item in files:
                destination = Path(item)
                destination.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(workspace / item, destination)
        return None

    def _run_isolated_attempt(self, problem_id: int, attempt: int) -> Dict[str, Any]:
        """在临时项目副本中执行一次指定题目，成功后只汇入三份新文件。"""
        workspaces_root = self.metrics_dir / "workspaces"
        workspaces_root.mkdir(parents=True, exist_ok=True)
        workspace = Path(
            tempfile.mkdtemp(prefix=f"p{problem_id}-a{attempt}-", dir=workspaces_root)
        )
        started = time.time()
        process_returncode: Optional[int] = None
        stdout_output = ""
        stderr_output = ""
        try:
            self._copy_isolated_project(workspace)
            baseline = self._project_file_state(workspace)
            worker_metrics_dir = workspace / ".ai-run-logs"
            process = subprocess.Popen(
                self._build_solve_cmd(problem_id),
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                bufsize=1,
                universal_newlines=True,
                cwd=workspace,
                env={
                    **self._build_child_env(worker_metrics_dir),
                    # 防止父进程的 PYTHONPATH 把主仓库代码带入 worker。
                    "PYTHONPATH": str(workspace),
                },
            )
            timed_out = False
            try:
                stdout_output, stderr_output = process.communicate(timeout=600)
            except subprocess.TimeoutExpired as exc:
                timed_out = True
                process.kill()
                remaining_stdout, remaining_stderr = process.communicate()
                stdout_output = _merge_process_output(exc.stdout, remaining_stdout)
                stderr_output = _merge_process_output(exc.stderr, remaining_stderr)
            process_returncode = process.returncode
            stdout_output = stdout_output or ""
            stderr_output = stderr_output or ""

            if timed_out:
                return {
                    "success": False,
                    "error": "timeout",
                    "metrics": None,
                    "process_returncode": process_returncode,
                    "elapsed_seconds": time.time() - started,
                    "output": stdout_output + stderr_output,
                }

            metrics = self._read_metrics_from_dir(worker_metrics_dir, problem_id)
            self._persist_worker_metrics(problem_id, attempt, metrics)
            metrics_failure = self._metrics_failure(metrics)
            if process_returncode == 0 and self.require_leetcode and metrics is None:
                metrics_failure = "leetcode_infra_error"
            files, modified = self._new_problem_files(workspace, baseline)
            preserved_files = False

            # 本地编译/测试已经通过，但在线提交可能因为网络超时、403 或
            # 判题服务无响应而没有拿到结果。此时仍保留已验证的三文件，避免
            # 隔离 worker 在 finally 中清理后丢失成果；代码不会被计为成功，
            # 后续仍可单独重试 LeetCode 提交。
            if (
                process_returncode == 0
                and metrics_failure == "leetcode_infra_error"
                and metrics
                and metrics.get("success")
                and not modified
            ):
                preserve_error = self._merge_isolated_files(workspace, files)
                if preserve_error is None:
                    preserved_files = True
                    self._log(
                        f"⚠️ LeetCode 在线验证无结果，但已保留题目 {problem_id} 的本地验证文件",
                        "WARNING",
                    )

            if process_returncode == 0 and metrics and not metrics_failure:
                if modified:
                    return {
                        "success": False,
                        "error": "workspace_mutation_detected",
                        "metrics": metrics,
                        "process_returncode": process_returncode,
                        "elapsed_seconds": time.time() - started,
                        "output": stdout_output + stderr_output,
                    }
                merge_error = self._merge_isolated_files(workspace, files)
                if merge_error is None:
                    return {
                        "success": True,
                        "error": None,
                        "metrics": metrics,
                        "process_returncode": process_returncode,
                        "elapsed_seconds": time.time() - started,
                        "output": stdout_output + stderr_output,
                    }
                failure = merge_error
            elif metrics_failure:
                failure = metrics_failure
            else:
                failure = self._analyze_failure(stdout_output + stderr_output)
            return {
                "success": False,
                "error": failure,
                "metrics": metrics,
                "process_returncode": process_returncode,
                "elapsed_seconds": time.time() - started,
                "output": stdout_output + stderr_output,
                "files_preserved": preserved_files,
            }
        except Exception as exc:
            return {
                "success": False,
                "error": f"exception:{type(exc).__name__}",
                "metrics": None,
                "process_returncode": process_returncode,
                "elapsed_seconds": time.time() - started,
                "output": f"{exc}\n",
            }
        finally:
            shutil.rmtree(workspace, ignore_errors=True)

    def _run_isolated_problem(self, problem_id: int) -> Dict[str, Any]:
        """在独立副本中执行本题，失败时从主工作区重新取干净副本重试。"""
        outputs: List[str] = []
        for attempt in range(1, self.max_retries + 1):
            result = self._run_isolated_attempt(problem_id, attempt)
            if result.get("output"):
                outputs.append(result["output"])
            if result["success"]:
                result["attempt"] = attempt
                result["output"] = "".join(outputs)
                return result
            if attempt < self.max_retries:
                time.sleep(self.retry_delay)
        result["attempt"] = self.max_retries
        result["output"] = "".join(outputs)
        return result

    def _run_concurrent(self) -> None:
        """受控并发：AI/本地编译并行，文件汇入和 LeetCode 提交受锁保护。"""
        self._log(f"🧵 并发 worker: {self.workers}（每个 worker 使用独立工作区）")
        while True:
            if self.max_problems is not None:
                remaining = self.max_problems - self.total_attempts
                if remaining <= 0:
                    self._log("达到本次 max_problems，停止批次", "SUCCESS")
                    break
                wave_size = min(self.workers, remaining)
            else:
                wave_size = self.workers

            selected: List[int] = []
            excluded = set(self.failed_problem_ids)
            while len(selected) < wave_size:
                problem_id = self._pick_problem(excluded)
                if problem_id is None or problem_id in excluded:
                    break
                selected.append(problem_id)
                excluded.add(problem_id)
            if not selected:
                if self.failed_problem_ids:
                    self._log("本轮没有可继续的题目", "WARNING")
                else:
                    self._log("🎉 所有题目都已解决！", "SUCCESS")
                break

            self.total_attempts += len(selected)
            self._log(f"🚦 启动并发批次: {selected}", "INFO")
            with ThreadPoolExecutor(max_workers=len(selected)) as executor:
                futures = {
                    executor.submit(self._run_isolated_problem, problem_id): problem_id
                    for problem_id in selected
                }
                for future in as_completed(futures):
                    problem_id = futures[future]
                    try:
                        result = future.result()
                    except Exception as exc:  # defensive: a worker must not stop the wave
                        result = {
                            "success": False,
                            "error": f"exception:{type(exc).__name__}",
                            "metrics": None,
                            "process_returncode": None,
                            "elapsed_seconds": 0.0,
                            "attempt": self.max_retries,
                            "output": f"{exc}\n",
                        }
                    result = self._retry_preserved_leetcode_submission(problem_id, result)
                    if result.get("output"):
                        print(f"\n===== isolated worker {problem_id} =====")
                        print(result["output"], end="")
                        print(f"===== end worker {problem_id} =====\n")
                    outcome = "success" if result["success"] else result["error"]
                    self._record_batch_result(
                        problem_id=problem_id,
                        attempt=result.get("attempt", self.max_retries),
                        process_returncode=result.get("process_returncode"),
                        outcome=outcome,
                        metrics=result.get("metrics"),
                        elapsed_seconds=result.get("elapsed_seconds", 0.0),
                    )
                    if result["success"]:
                        self.success_count += 1
                        self.success_streak += 1
                        self.fail_streak = 0
                        self._log(f"✅ 并发题目 {problem_id} 完成", "SUCCESS")
                    else:
                        self.failed_problem_ids.add(problem_id)
                        self.fail_streak += 1
                        self.success_streak = 0
                        self._log(
                            f"❌ 并发题目 {problem_id} 失败（{result['error']}），后续跳过",
                            "WARNING",
                        )

            if self.fail_streak >= self.fail_streak_limit:
                self._log(
                    f"连续失败 {self.fail_streak_limit} 次，暂停 {self.fail_streak_pause} 秒...",
                    "WARNING",
                )
                time.sleep(self.fail_streak_pause)
                self.fail_streak = 0

    def _record_batch_result(
        self,
        *,
        problem_id: int,
        attempt: int,
        process_returncode: Optional[int],
        outcome: str,
        metrics: Optional[dict],
        elapsed_seconds: float,
    ) -> None:
        """追加一条不含密钥的批次记录，支持中断后审计与续跑。"""
        record = {
            "timestamp": datetime.now().isoformat(timespec="seconds"),
            "problem_id": problem_id,
            "attempt": attempt,
            "process_returncode": process_returncode,
            "outcome": outcome,
            "elapsed_seconds": round(elapsed_seconds, 3),
            "metrics": metrics,
        }
        try:
            self.metrics_dir.mkdir(parents=True, exist_ok=True)
            with self.batch_results_path.open("a", encoding="utf-8") as handle:
                handle.write(json.dumps(record, ensure_ascii=False) + "\n")
        except OSError as exc:
            self._log(f"⚠️ 批次记录写入失败: {exc}", "WARNING")

    def _metrics_failure(self, metrics: Optional[dict]) -> Optional[str]:
        """把子进程 metrics 转成批量调度能理解的失败类型。"""
        if not metrics:
            return None
        if not metrics.get("success"):
            return metrics.get("failure_reason") or "solver_metrics_failed"
        if self.require_leetcode and metrics.get("leetcode_passed") is not True:
            if metrics.get("leetcode_passed") is None:
                return "leetcode_infra_error"
            return "leetcode_rejected"
        return None

    def _pick_problem(self, extra_exclude: Optional[Set[int]] = None) -> Optional[int]:
        """选择一个本轮尚未失败过的未解决题目。"""
        from script.leetcode.problem_pool import ProblemPool

        excluded = set(self.failed_problem_ids)
        if extra_exclude:
            excluded.update(extra_exclude)
        return ProblemPool().get_random(exclude_ids=excluded)

    def _mark_problem_failed(
        self, problem_id: int, error_type: str
    ) -> tuple[bool, str]:
        self.failed_problem_ids.add(problem_id)
        self._log(
            f"⏭️ 题目 {problem_id} 本轮失败（{error_type}），后续跳过并继续下一题",
            "WARNING",
        )
        return False, error_type
    
    def run_once(self) -> tuple[bool, Optional[str]]:
        """
        运行一次 AI Solve
        
        Returns:
            (success, error_type): 是否成功，错误类型（None表示成功）
        """
        problem_id = self._pick_problem()
        if problem_id is None:
            if self.failed_problem_ids:
                self._log(
                    f"本轮剩余未解决题目都已失败并跳过（{len(self.failed_problem_ids)} 题）",
                    "WARNING",
                )
                return False, "EXHAUSTED_AFTER_FAILURE"
            else:
                self._log("没有未解决的题目", "SUCCESS")
            return True, "ALL_SOLVED"

        cmd = self._build_solve_cmd(problem_id)
        start_count = self._get_solved_count()
        
        for attempt in range(self.max_retries):
            attempt_started = time.time()
            self._log(
                f"开始执行题目 {problem_id}: {' '.join(cmd)} "
                f"(尝试 {attempt + 1}/{self.max_retries})"
            )
            print("-" * 60)
            self._log("⏳ 正在启动 AI 解题流程，首次启动可能需要 10-20 秒...")
            self._log("💡 提示: AI 解题平均需要 1-3 分钟，请耐心等待，不要中断")
            
            try:
                # 使用 communicate 同时消费 stdout/stderr，避免双管道死锁；
                # timeout 也能覆盖整个子进程生命周期，而不是等 stdout EOF 后才开始计时。
                process = subprocess.Popen(
                    cmd,
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                    bufsize=1,  # 行缓冲
                    universal_newlines=True,
                    env=self._build_child_env(),
                )

                timed_out = False
                try:
                    stdout_output, stderr_output = process.communicate(timeout=600)
                except subprocess.TimeoutExpired as exc:
                    timed_out = True
                    process.kill()
                    remaining_stdout, remaining_stderr = process.communicate()
                    stdout_output = _merge_process_output(exc.stdout, remaining_stdout)
                    stderr_output = _merge_process_output(exc.stderr, remaining_stderr)

                stdout_output = stdout_output or ""
                stderr_output = stderr_output or ""
                if stdout_output:
                    print(stdout_output, end='')
                if stderr_output:
                    print(stderr_output, file=sys.stderr, end='')
                print("-" * 60)

                if timed_out:
                    self._log("⏱️ 执行超时（10分钟）", "ERROR")
                    self._record_batch_result(
                        problem_id=problem_id,
                        attempt=attempt + 1,
                        process_returncode=process.returncode,
                        outcome="timeout",
                        metrics=None,
                        elapsed_seconds=time.time() - attempt_started,
                    )
                    if attempt < self.max_retries - 1:
                        time.sleep(self.retry_delay)
                        continue
                    return self._mark_problem_failed(problem_id, "timeout")

                end_count = self._get_solved_count()
                metrics = self._read_problem_metrics(
                    problem_id, newer_than=attempt_started
                )
                self._last_metrics = metrics
                metrics_failure = self._metrics_failure(metrics)
                if process.returncode == 0 and self.require_leetcode and metrics is None:
                    metrics_failure = "leetcode_infra_error"

                # 检查是否因为 LeetCode 修复次数耗尽而失败
                leetcode_fix_exhausted = "达到 LeetCode 验证失败最大修复次数" in stdout_output

                if end_count > start_count and leetcode_fix_exhausted:
                    # 文件创建了但 LeetCode 验证最终未能通过（已尝试修复但次数耗尽）
                    self._log("⚠️ 本地文件已生成，但 LeetCode 验证最终未能通过（已尝试多次修复）", "WARNING")
                    self._record_batch_result(
                        problem_id=problem_id,
                        attempt=attempt + 1,
                        process_returncode=process.returncode,
                        outcome="leetcode_verification_failed_after_retries",
                        metrics=metrics,
                        elapsed_seconds=time.time() - attempt_started,
                    )
                    return self._mark_problem_failed(
                        problem_id, "leetcode_verification_failed_after_retries"
                    )

                if process.returncode == 0 and end_count > start_count and not metrics_failure:
                    self._record_batch_result(
                        problem_id=problem_id,
                        attempt=attempt + 1,
                        process_returncode=process.returncode,
                        outcome="success",
                        metrics=metrics,
                        elapsed_seconds=time.time() - attempt_started,
                    )
                    self._log("✅ 解题完成，新增题目", "SUCCESS")
                    return True, None

                if process.returncode == 0 and metrics_failure:
                    self._record_batch_result(
                        problem_id=problem_id,
                        attempt=attempt + 1,
                        process_returncode=process.returncode,
                        outcome=metrics_failure,
                        metrics=metrics,
                        elapsed_seconds=time.time() - attempt_started,
                    )
                    self._log(
                        f"❌ metrics 判定未完成（{metrics_failure}），不把退出码 0 当作成功",
                        "WARNING",
                    )
                    return self._mark_problem_failed(problem_id, metrics_failure)

                # 分析失败原因
                output = stdout_output + stderr_output
                fail_type = metrics_failure or self._analyze_failure(output)
                
                if fail_type == "no_problem":
                    self._log("🎉 所有题目都已解决！", "SUCCESS")
                    return True, "ALL_SOLVED"
                
                self._log(f"❌ 解题失败（类型: {fail_type}，返回码: {process.returncode}）", "WARNING")
                self._record_batch_result(
                    problem_id=problem_id,
                    attempt=attempt + 1,
                    process_returncode=process.returncode,
                    outcome=fail_type,
                    metrics=metrics,
                    elapsed_seconds=time.time() - attempt_started,
                )
                
                if attempt < self.max_retries - 1:
                    self._log(f"等待 {self.retry_delay} 秒后重试...", "INFO")
                    time.sleep(self.retry_delay)
                else:
                    return self._mark_problem_failed(problem_id, fail_type)
                    
            except Exception as e:
                self._log(f"💥 异常: {e}", "ERROR")
                self._record_batch_result(
                    problem_id=problem_id,
                    attempt=attempt + 1,
                    process_returncode=None,
                    outcome=f"exception:{type(e).__name__}",
                    metrics=None,
                    elapsed_seconds=time.time() - attempt_started,
                )
                if attempt < self.max_retries - 1:
                    time.sleep(self.retry_delay)

        return self._mark_problem_failed(problem_id, "max_retries_exceeded")
    
    def run(self):
        """主循环"""
        solved_count_start = self._get_solved_count()
        
        self._log("=" * 60)
        self._log("🚀 启动 AI Solve 自动模式")
        self._log(f"📊 当前已解决题目: {solved_count_start}")
        self._log(f"📝 生成报告: {'是' if self.report else '否'}")
        self._log(f"🔄 最大重试: {self.max_retries} 次")
        self._log("🔁 失败策略: 单题失败后本轮跳过，继续下一题")
        self._log(f"⏸️  连续失败{self.fail_streak_limit}次后暂停: {self.fail_streak_pause} 秒")
        if self.workers > 1:
            self._log(f"🧵 并发 worker: {self.workers}（独立工作区，LeetCode 提交跨进程节流）")
        self._log(f"🧾 批次记录: {self.batch_results_path}")
        if self.max_problems is not None:
            self._log(f"🎯 本次最多处理题目: {self.max_problems}")
        self._log("=" * 60)
        self._log("按 Ctrl+C 停止")
        print()

        if self.workers > 1:
            try:
                self._run_concurrent()
            except KeyboardInterrupt:
                print()
                self._log("👋 用户中断", "WARNING")
            self._print_final_stats(solved_count_start)
            return
        
        try:
            while True:
                if self.max_problems is not None and self.total_attempts >= self.max_problems:
                    self._log("达到本次 max_problems，停止批次", "SUCCESS")
                    break

                self.total_attempts += 1
                
                # 运行一次解题
                success, error = self.run_once()
                
                if error in {"ALL_SOLVED", "EXHAUSTED_AFTER_FAILURE"}:
                    break
                
                if success:
                    self.success_count += 1
                    self.success_streak += 1
                    self.fail_streak = 0
                    current_solved = self._get_solved_count()
                    self._log(f"✅ 成功！已解决题目: {current_solved}", "SUCCESS")
                else:
                    self.fail_streak += 1
                    self.success_streak = 0
                    self._log(f"❌ 失败: {error}", "ERROR")
                    
                    # 连续失败检测
                    if self.fail_streak >= self.fail_streak_limit:
                        self._log(f"连续失败 {self.fail_streak_limit} 次，暂停 {self.fail_streak_pause} 秒...", "WARNING")
                        time.sleep(self.fail_streak_pause)
                        self.fail_streak = 0
                
                # 统计信息
                elapsed = datetime.now() - self.start_time
                self._log(f"📈 统计: 尝试 {self.total_attempts} 次, 成功 {self.success_count} 次, 运行时间 {elapsed}")
                print()
                
                # 短暂休息，避免 API 限流
                if self.submit_delay and self.require_leetcode:
                    self._log(f"⏸️ 在线提交节流，等待 {self.submit_delay} 秒")
                    time.sleep(self.submit_delay)
                
        except KeyboardInterrupt:
            print()
            self._log("👋 用户中断", "WARNING")
        
        # 最终统计
        self._print_final_stats(solved_count_start)
    
    def _print_final_stats(self, solved_count_start: int):
        """打印最终统计"""
        elapsed = datetime.now() - self.start_time
        final_solved = self._get_solved_count()
        
        self._log("=" * 60)
        self._log("📊 最终统计")
        self._log("=" * 60)
        self._log(f"⏱  运行时间: {elapsed}")
        self._log(f"🎯 尝试次数: {self.total_attempts}")
        self._log(f"✅ 成功次数: {self.success_count}")
        self._log(f"❌ 失败次数: {self.total_attempts - self.success_count}")
        self._log(f"⏭️  本轮跳过失败题目: {len(self.failed_problem_ids)}")
        self._log(f"📚 新增题目: {final_solved - solved_count_start}")
        self._log(f"📦 总题目数: {final_solved}")
        self._log("=" * 60)


def main():
    """主函数"""
    parser = argparse.ArgumentParser(
        description="AI 自动解题循环模式",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
示例:
  # 基础用法（不生成报告，节省 token）
  python -m script.leetcode.ai.auto_solver
  
  # 生成解题报告（消耗更多 token）
  python -m script.leetcode.ai.auto_solver --report
  
  # 自定义重试次数和间隔
  python -m script.leetcode.ai.auto_solver --max-retries 5 --retry-delay 30
  
  # 自定义连续失败限制
  python -m script.leetcode.ai.auto_solver --fail-streak-limit 5 --fail-streak-pause 120
        """
    )
    parser.add_argument(
        "--report",
        action="store_true",
        help="生成解题报告（默认关闭以节省 token）"
    )
    parser.add_argument(
        "--max-retries",
        type=int,
        default=3,
        help="每次执行的最大重试次数（默认: 3）"
    )
    parser.add_argument(
        "--retry-delay",
        type=int,
        default=60,
        help="重试间隔秒数（默认: 60）"
    )
    parser.add_argument(
        "--fail-streak-limit",
        type=int,
        default=3,
        help="连续失败多少次后暂停（默认: 3）"
    )
    parser.add_argument(
        "--fail-streak-pause",
        type=int,
        default=60,
        help="连续失败后的暂停秒数（默认: 60）"
    )
    parser.add_argument(
        "--max-problems",
        type=int,
        help="本次最多处理题目数；不传则持续运行直到题池耗尽",
    )
    parser.add_argument(
        "--submit-delay",
        type=int,
        default=6,
        help="在线提交成功后的节流等待秒数（默认 6）",
    )
    parser.add_argument(
        "--workers",
        type=int,
        default=1,
        help="并发 worker 数（默认 1；>1 时每题使用独立工作区）",
    )
    leetcode_group = parser.add_mutually_exclusive_group()
    leetcode_group.add_argument(
        "--no-leetcode", dest="require_leetcode", action="store_false", default=None
    )
    leetcode_group.add_argument(
        "--require-leetcode", dest="require_leetcode", action="store_true", default=None
    )
    parser.add_argument("--metrics-dir", help="批次 metrics 与 batch_results.jsonl 输出目录")
    parser.add_argument(
        "--api-key",
        help="API Key"
    )
    parser.add_argument(
        "--base-url",
        help="API 基础 URL"
    )
    
    args = parser.parse_args()
    
    solver = AutoSolver(
        report=args.report,
        max_retries=args.max_retries,
        retry_delay=args.retry_delay,
        fail_streak_limit=args.fail_streak_limit,
        fail_streak_pause=args.fail_streak_pause,
        api_key=args.api_key,
        base_url=args.base_url,
        require_leetcode=args.require_leetcode,
        max_problems=args.max_problems,
        submit_delay=args.submit_delay,
        metrics_dir=args.metrics_dir,
        workers=args.workers,
    )
    
    try:
        solver.run()
    except KeyboardInterrupt:
        print()
        sys.exit(130)


if __name__ == "__main__":
    main()
