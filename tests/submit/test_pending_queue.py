#!/usr/bin/env python3

import os
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from script.leetcode.submit import pending_queue


class TestPendingSubmissionQueue(unittest.TestCase):
    def test_enqueue_deduplicates_and_remove_is_durable(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            queue_file = Path(temp_dir) / "queue.jsonl"
            with patch.dict(os.environ, {"AI_SOLVER_SUBMIT_QUEUE": str(queue_file)}, clear=False):
                pending_queue.enqueue(123)
                pending_queue.enqueue(123, reason="still_rate_limited")
                pending_queue.enqueue(456)

                self.assertEqual(pending_queue.pending_problem_ids(), [123, 456])
                pending_queue.remove(123)
                self.assertEqual(pending_queue.pending_problem_ids(), [456])

    def test_uncertain_item_is_quarantined_without_blocking_other_items(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            queue_file = Path(temp_dir) / "queue.jsonl"
            with patch.dict(
                os.environ,
                {"AI_SOLVER_SUBMIT_QUEUE": str(queue_file)},
                clear=False,
            ):
                pending_queue.enqueue(123)
                pending_queue.enqueue(456)
                with patch(
                    "script.leetcode.submit.pending_queue.time.time",
                    return_value=1000,
                ):
                    pending_queue.defer(
                        123,
                        reason="uncertain_network",
                        delay_seconds=60,
                    )

                self.assertEqual(pending_queue.pending_problem_ids(), [123, 456])
                self.assertEqual(
                    pending_queue.eligible_problem_ids(now=1000),
                    [456],
                )
                self.assertEqual(
                    pending_queue.eligible_problem_ids(now=1060),
                    [123, 456],
                )


if __name__ == "__main__":
    unittest.main()
