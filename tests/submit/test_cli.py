import os
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from script.leetcode.submit import cli, pending_queue
from script.leetcode.submit.result import SubmissionResult


class TestSubmissionQueueCli(unittest.TestCase):
    def test_uncertain_item_isolated_while_other_items_continue(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            queue_file = Path(temp_dir) / "queue.jsonl"
            with patch.dict(
                os.environ,
                {"AI_SOLVER_SUBMIT_QUEUE": str(queue_file)},
                clear=False,
            ):
                pending_queue.enqueue(123)
                pending_queue.enqueue(456)

                class FakeSubmitter:
                    def __init__(self) -> None:
                        self.calls: list[int] = []

                    def submit_problem_with_result(self, problem_id: int) -> SubmissionResult:
                        self.calls.append(problem_id)
                        if problem_id == 123:
                            return SubmissionResult(
                                status="Error",
                                status_code=-1,
                                error_type="network_error",
                            )
                        return SubmissionResult(status="Accepted", status_code=10)

                submitter = FakeSubmitter()
                with patch.object(cli, "LeetCodeSubmitter", return_value=submitter):
                    with patch.object(
                        cli.http_api,
                        "print_verdict",
                        side_effect=lambda result: result.status == "Accepted",
                    ):
                        self.assertFalse(cli._run_queue())

                self.assertEqual(submitter.calls, [123, 456])
                self.assertEqual(pending_queue.pending_problem_ids(), [123])
                self.assertEqual(pending_queue.eligible_problem_ids(), [])


if __name__ == "__main__":
    unittest.main()
