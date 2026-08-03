#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import unittest
from pathlib import Path
from tempfile import TemporaryDirectory
from unittest.mock import patch

from script.leetcode.ai.auto_solver import AutoSolver
from script.leetcode.submit import pending_queue


class _FakeProcess:
    def __init__(self, stdout_lines, returncode=1):
        self.stdout_text = "".join(stdout_lines)
        self.stderr_text = ""
        self.returncode = returncode

    def communicate(self, timeout=None):
        return self.stdout_text, self.stderr_text

    def kill(self):
        pass


class TestAutoSolverLongRun(unittest.TestCase):
    def test_preserved_online_infra_failure_is_recovered_by_serial_submit(self) -> None:
        solver = AutoSolver(
            max_retries=1,
            retry_delay=0,
            require_leetcode=True,
            workers=2,
        )
        result = {
            "success": False,
            "error": "leetcode_infra_error",
            "files_preserved": True,
            "metrics": {"success": True, "leetcode_passed": None},
            "output": "local success\n",
        }
        completed = type(
            "Completed",
            (),
            {"returncode": 0, "stdout": "✅ Accepted!\n", "stderr": ""},
        )()

        with patch(
            "script.leetcode.ai.auto_solver.subprocess.run",
            return_value=completed,
        ) as run:
            recovered = solver._retry_preserved_leetcode_submission(123, result)

        self.assertTrue(recovered["success"])
        self.assertIsNone(recovered["error"])
        self.assertTrue(recovered["metrics"]["infra_recovered"])
        run.assert_called_once()
        self.assertEqual(run.call_args.args[0][-1], "123")

    def test_rate_limited_preserved_submission_is_queued_without_retry(self) -> None:
        with TemporaryDirectory() as temp_dir:
            queue_file = Path(temp_dir) / "queue.jsonl"
            solver = AutoSolver(
                max_retries=1,
                retry_delay=0,
                require_leetcode=True,
                workers=2,
            )
            result = {
                "success": False,
                "error": "leetcode_infra_error",
                "files_preserved": True,
                "metrics": {"success": True, "leetcode_passed": None},
                "output": "http_429: HTTP 429\n",
            }

            with patch.dict(
                "os.environ", {"AI_SOLVER_SUBMIT_QUEUE": str(queue_file)}, clear=False
            ):
                with patch("script.leetcode.ai.auto_solver.subprocess.run") as run:
                    queued = solver._retry_preserved_leetcode_submission(123, result)

                self.assertEqual(pending_queue.pending_problem_ids(), [123])

            run.assert_not_called()
            self.assertTrue(queued["queued_for_submission"])

    def test_code_failure_is_not_retried_as_online_infra(self) -> None:
        solver = AutoSolver(require_leetcode=True, workers=2)
        result = {
            "success": False,
            "error": "leetcode_rejected",
            "files_preserved": True,
        }

        with patch("script.leetcode.ai.auto_solver.subprocess.run") as run:
            unchanged = solver._retry_preserved_leetcode_submission(123, result)

        self.assertIs(unchanged, result)
        run.assert_not_called()

    def test_failed_problem_is_skipped_for_current_run(self) -> None:
        solver = AutoSolver(max_retries=1, retry_delay=0)
        solver._pick_problem = lambda: 123

        with patch.object(AutoSolver, "_get_solved_count", return_value=10):
            with patch(
                "script.leetcode.ai.auto_solver.subprocess.Popen",
                return_value=_FakeProcess(["error: boom\n"]),
            ):
                success, error = solver.run_once()

        self.assertFalse(success)
        self.assertEqual(error, "compile_error")
        self.assertEqual(solver.failed_problem_ids, {123})

    def test_pick_problem_passes_session_failures_to_pool(self) -> None:
        class _Pool:
            def get_random(self, exclude_ids):
                self.exclude_ids = exclude_ids
                return 456

        pool = _Pool()
        solver = AutoSolver()
        solver.failed_problem_ids = {123}

        with patch("script.leetcode.problem_pool.ProblemPool", return_value=pool):
            self.assertEqual(solver._pick_problem(), 456)

        self.assertEqual(pool.exclude_ids, {123})

    def test_explicit_base_url_is_forwarded_without_exposing_api_key(self) -> None:
        solver = AutoSolver(
            api_key="secret-key",
            base_url="https://example.invalid/v1",
            require_leetcode=False,
        )
        command = solver._build_solve_cmd(42)
        self.assertIn("--base-url", command)
        self.assertIn("https://example.invalid/v1", command)
        self.assertNotIn("secret-key", command)

    def test_failed_child_is_not_success_when_files_were_created(self) -> None:
        solver = AutoSolver(max_retries=1, retry_delay=0)
        solver._pick_problem = lambda: 123

        with patch.object(AutoSolver, "_get_solved_count", side_effect=[10, 11]):
            with patch(
                "script.leetcode.ai.auto_solver.subprocess.Popen",
                return_value=_FakeProcess(["error: boom\n"]),
            ):
                success, error = solver.run_once()

        self.assertFalse(success)
        self.assertEqual(error, "compile_error")
        self.assertEqual(solver.failed_problem_ids, {123})

    def test_exhausted_after_failures_is_not_reported_as_all_solved(self) -> None:
        solver = AutoSolver()
        solver.failed_problem_ids = {123}
        solver._pick_problem = lambda: None

        success, error = solver.run_once()

        self.assertFalse(success)
        self.assertEqual(error, "EXHAUSTED_AFTER_FAILURE")

    def test_online_infra_metrics_are_not_counted_as_success(self) -> None:
        solver = AutoSolver(max_retries=1, retry_delay=0, require_leetcode=True)
        solver._pick_problem = lambda: 123

        with patch.object(AutoSolver, "_get_solved_count", side_effect=[10, 11]):
            with patch.object(
                AutoSolver,
                "_read_problem_metrics",
                return_value={"success": True, "leetcode_passed": None},
            ):
                with patch.object(AutoSolver, "_record_batch_result"):
                    with patch(
                        "script.leetcode.ai.auto_solver.subprocess.Popen",
                        return_value=_FakeProcess(["local success\n"], returncode=0),
                    ):
                        success, error = solver.run_once()

        self.assertFalse(success)
        self.assertEqual(error, "leetcode_infra_error")
        self.assertEqual(solver.failed_problem_ids, {123})

    def test_missing_online_metrics_are_not_counted_as_success(self) -> None:
        solver = AutoSolver(max_retries=1, retry_delay=0, require_leetcode=True)
        solver._pick_problem = lambda: 123

        with patch.object(AutoSolver, "_get_solved_count", side_effect=[10, 11]):
            with patch.object(AutoSolver, "_read_problem_metrics", return_value=None):
                with patch.object(AutoSolver, "_record_batch_result"):
                    with patch(
                        "script.leetcode.ai.auto_solver.subprocess.Popen",
                        return_value=_FakeProcess(["local success\n"], returncode=0),
                    ):
                        success, error = solver.run_once()

        self.assertFalse(success)
        self.assertEqual(error, "leetcode_infra_error")

    def test_online_accepted_metrics_are_required_for_online_success(self) -> None:
        solver = AutoSolver(max_retries=1, retry_delay=0, require_leetcode=True)
        solver._pick_problem = lambda: 123

        with patch.object(AutoSolver, "_get_solved_count", side_effect=[10, 11]):
            with patch.object(
                AutoSolver,
                "_read_problem_metrics",
                return_value={"success": True, "leetcode_passed": True},
            ):
                with patch.object(AutoSolver, "_record_batch_result"):
                    with patch(
                        "script.leetcode.ai.auto_solver.subprocess.Popen",
                        return_value=_FakeProcess(["online success\n"], returncode=0),
                    ):
                        success, error = solver.run_once()

        self.assertTrue(success)
        self.assertIsNone(error)

    def test_nonzero_child_prefers_metrics_failure_reason(self) -> None:
        solver = AutoSolver(max_retries=1, retry_delay=0)
        solver._pick_problem = lambda: 123

        with patch.object(AutoSolver, "_get_solved_count", return_value=10):
            with patch.object(
                AutoSolver,
                "_read_problem_metrics",
                return_value={"success": False, "failure_reason": "token_budget_exhausted"},
            ):
                with patch(
                    "script.leetcode.ai.auto_solver.subprocess.Popen",
                    return_value=_FakeProcess(["solver failed\n"]),
                ):
                    success, error = solver.run_once()

        self.assertFalse(success)
        self.assertEqual(error, "token_budget_exhausted")

    def test_worker_environment_uses_shared_absolute_submission_lock(self) -> None:
        with TemporaryDirectory() as metrics_dir:
            solver = AutoSolver(
                require_leetcode=True,
                workers=2,
                metrics_dir=metrics_dir,
            )
            child_env = solver._build_child_env(Path(metrics_dir) / "worker")

        self.assertEqual(child_env["AI_SOLVER_SUBMIT_INTERVAL"], "6")
        self.assertTrue(Path(child_env["AI_SOLVER_SUBMIT_LOCK"]).is_absolute())
        self.assertTrue(Path(child_env["AI_SOLVER_METRICS_DIR"]).is_absolute())

    def test_new_problem_files_only_accepts_problem_tree_additions(self) -> None:
        with TemporaryDirectory() as workspace_name:
            workspace = Path(workspace_name)
            for directory in (
                "include/leetcode/problems",
                "src/leetcode/problems",
                "test/leetcode/problems",
            ):
                (workspace / directory).mkdir(parents=True)
            baseline = AutoSolver._project_file_state(workspace)
            (workspace / "include/leetcode/problems/demo.h").write_text("h")
            (workspace / "src/leetcode/problems/demo.cpp").write_text("s")
            (workspace / "test/leetcode/problems/demo.cpp").write_text("t")

            files, modified = AutoSolver._new_problem_files(workspace, baseline)

        self.assertEqual(len(files), 3)
        self.assertEqual(modified, [])

    def test_isolated_online_infra_failure_preserves_local_solution_files(self) -> None:
        with TemporaryDirectory() as metrics_dir:
            solver = AutoSolver(
                max_retries=1,
                retry_delay=0,
                require_leetcode=True,
                workers=2,
                metrics_dir=metrics_dir,
            )

            def fake_copy(workspace: Path) -> None:
                for directory in (
                    "include/leetcode/problems",
                    "src/leetcode/problems",
                    "test/leetcode/problems",
                ):
                    (workspace / directory).mkdir(parents=True, exist_ok=True)

            def fake_popen(*args, **kwargs):
                workspace = Path(kwargs["cwd"])
                (workspace / "include/leetcode/problems/demo.h").write_text("h")
                (workspace / "src/leetcode/problems/demo.cpp").write_text("s")
                (workspace / "test/leetcode/problems/demo.cpp").write_text("t")
                return _FakeProcess(["local success\n"], returncode=0)

            metrics = {"success": True, "leetcode_passed": None}
            with patch.object(AutoSolver, "_copy_isolated_project", side_effect=fake_copy):
                with patch(
                    "script.leetcode.ai.auto_solver.subprocess.Popen",
                    side_effect=fake_popen,
                ):
                    with patch.object(
                        AutoSolver, "_read_metrics_from_dir", return_value=metrics
                    ):
                        with patch.object(
                            AutoSolver, "_merge_isolated_files", return_value=None
                        ) as merge_files:
                            result = solver._run_isolated_attempt(123, 1)

            self.assertFalse(result["success"])
            self.assertEqual(result["error"], "leetcode_infra_error")
            self.assertTrue(result["files_preserved"])
            merge_files.assert_called_once()
            self.assertEqual(len(merge_files.call_args.args[1]), 3)


if __name__ == "__main__":
    unittest.main()
