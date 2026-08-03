#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
import os
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from script.leetcode.submit.rate_limit import (
    should_pause_submission_queue,
    submission_rate_limit,
)


class TestSubmissionRateLimit(unittest.TestCase):
    def test_queue_pauses_for_uncertain_transport_result(self) -> None:
        result = type(
            "Result",
            (),
            {"status": "Error", "status_code": -1, "error_type": "network_error"},
        )()
        self.assertTrue(should_pause_submission_queue(result))

    def test_queue_can_continue_after_deterministic_verdict(self) -> None:
        result = type(
            "Result",
            (),
            {"status": "Wrong Answer", "status_code": 11, "error_type": None},
        )()
        self.assertFalse(should_pause_submission_queue(result))

    def test_configured_lock_records_last_submission_time(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            lock_path = Path(temp_dir) / "submit.lock"
            with patch.dict(
                os.environ,
                {
                    "AI_SOLVER_SUBMIT_LOCK": str(lock_path),
                    "AI_SOLVER_SUBMIT_INTERVAL": "0",
                    "LEETCODE_COOKIE": "test-cookie",
                },
                clear=False,
            ):
                with submission_rate_limit():
                    pass

            state = json.loads(lock_path.read_text(encoding="utf-8"))
            self.assertGreater(state["last_submission"], 0)
            self.assertEqual(state["rate_limit_streak"], 0)

    def test_429_increases_shared_exponential_cooldown(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            lock_path = Path(temp_dir) / "submit.lock"
            with patch.dict(
                os.environ,
                {
                    "AI_SOLVER_SUBMIT_LOCK": str(lock_path),
                    "AI_SOLVER_SUBMIT_INTERVAL": "0",
                    "AI_SOLVER_SUBMIT_BACKOFF_BASE": "30",
                    "AI_SOLVER_SUBMIT_BACKOFF_MAX": "300",
                    "LEETCODE_COOKIE": "test-cookie",
                },
                clear=False,
            ):
                with patch("script.leetcode.submit.rate_limit.time.sleep") as sleep:
                    with submission_rate_limit() as permit:
                        permit.mark_rate_limited()
                    with submission_rate_limit() as permit:
                        permit.mark_rate_limited(retry_after=45)

            state = json.loads(lock_path.read_text(encoding="utf-8"))
            self.assertEqual(state["rate_limit_streak"], 2)
            self.assertGreaterEqual(
                state["cooldown_until"] - state["last_submission"], 45
            )
            self.assertTrue(sleep.called)

    def test_nested_gate_and_submitter_share_one_permit(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            lock_path = Path(temp_dir) / "submit.lock"
            with patch.dict(
                os.environ,
                {
                    "AI_SOLVER_SUBMIT_LOCK": str(lock_path),
                    "AI_SOLVER_SUBMIT_INTERVAL": "0",
                    "LEETCODE_COOKIE": "test-cookie",
                },
                clear=False,
            ):
                with submission_rate_limit() as outer:
                    with submission_rate_limit() as inner:
                        self.assertIs(outer, inner)
                        inner.mark_rate_limited()

            state = json.loads(lock_path.read_text(encoding="utf-8"))
            self.assertEqual(state["rate_limit_streak"], 1)

    def test_long_cooldown_is_deferred_instead_of_sleeping_worker(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            lock_path = Path(temp_dir) / "submit.lock"
            with patch.dict(
                os.environ,
                {
                    "AI_SOLVER_SUBMIT_LOCK": str(lock_path),
                    "AI_SOLVER_SUBMIT_INTERVAL": "0",
                    "AI_SOLVER_SUBMIT_BACKOFF_BASE": "300",
                    "AI_SOLVER_SUBMIT_DEFER_AFTER": "1",
                    "LEETCODE_COOKIE": "test-cookie",
                },
                clear=False,
            ):
                with submission_rate_limit() as permit:
                    permit.mark_rate_limited()
                with patch("script.leetcode.submit.rate_limit.time.sleep") as sleep:
                    with submission_rate_limit() as permit:
                        self.assertTrue(permit.deferred)
                    sleep.assert_not_called()

    def test_without_lock_configuration_is_a_noop(self) -> None:
        with patch.dict(
            os.environ,
            {"AI_SOLVER_SUBMIT_LOCK": "", "LEETCODE_COOKIE": ""},
            clear=False,
        ):
            with submission_rate_limit():
                pass


if __name__ == "__main__":
    unittest.main()
