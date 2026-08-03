#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""LeetCode submission gate for AISolver completion."""

from typing import Callable, Optional

from script.leetcode.submit import feedback as leetcode_feedback
from script.leetcode.submit.classifier import SubmissionClassifier
from script.leetcode.submit.rate_limit import submission_rate_limit


class LeetCodeGate:
    """Convert LeetCode submission outcomes into solver control signals."""

    def __init__(self, classifier: Optional[SubmissionClassifier] = None):
        self.classifier = classifier or SubmissionClassifier()

    def submit(
        self,
        problem_id: Optional[int],
        *,
        verify_all_strategies: bool,
        self_authored_tests_locally_passed: Callable[[], bool],
    ) -> tuple[bool, Optional[bool], Optional[str], Optional[str]]:
        """Return (should_continue, accepted, feedback, skip_reason)."""
        # Multiple isolated workers may solve locally at the same time, but all
        # submissions still belong to one LeetCode account.  The lock is a
        # no-op for the ordinary single-process CLI path.
        with submission_rate_limit() as permit:
            if verify_all_strategies:
                outcome = self.classifier.submit_all_and_classify(problem_id)
            else:
                outcome = self.classifier.submit_and_classify(problem_id)
            if getattr(outcome, "rate_limited", False):
                permit.mark_rate_limited()
        if outcome.should_continue:
            return True, outcome.accepted, None, outcome.skip_reason
        if outcome.error_message:
            return False, outcome.accepted, outcome.error_message, outcome.skip_reason
        if outcome.result is not None:
            feedback = leetcode_feedback.build(
                outcome.result,
                self_authored_tests_locally_passed=self_authored_tests_locally_passed(),
            )
            return False, outcome.accepted, feedback, outcome.skip_reason
        return False, outcome.accepted, "LeetCode 提交失败", outcome.skip_reason
