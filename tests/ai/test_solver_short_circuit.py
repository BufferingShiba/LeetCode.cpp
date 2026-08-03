#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""compile_and_test 成功后的短路逻辑单测（迁到 tool_round 模块后的版本）。"""

import unittest

from script.leetcode.ai.tool_round import should_short_circuit, update_summary


class TestShouldShortCircuit(unittest.TestCase):
    def test_short_circuit_when_compile_passed(self) -> None:
        summary = {"file_mutated": True, "error_signatures": [], "compile_passed": True}
        self.assertTrue(should_short_circuit(summary))

    def test_no_short_circuit_when_compile_failed(self) -> None:
        summary = {"file_mutated": True, "error_signatures": ["..."], "compile_passed": False}
        self.assertFalse(should_short_circuit(summary))

    def test_no_short_circuit_when_compile_not_called(self) -> None:
        summary = {"file_mutated": True, "error_signatures": []}
        self.assertFalse(should_short_circuit(summary))

    def test_no_short_circuit_when_validation_is_stale(self) -> None:
        summary = {
            "file_mutated": True,
            "error_signatures": [],
            "compile_passed": True,
            "mutation_version": 1,
            "compile_passed_version": 0,
        }
        self.assertFalse(should_short_circuit(summary))


class TestCompilePassedTracking(unittest.TestCase):
    def test_compile_and_test_success_sets_flag(self) -> None:
        summary = {"file_mutated": False, "error_signatures": []}
        update_summary(summary, "compile_and_test", {"is_successful": True, "message": "所有测试通过"})
        self.assertTrue(summary.get("compile_passed"))

    def test_compile_and_test_failure_leaves_flag_unset_or_false(self) -> None:
        summary = {"file_mutated": False, "error_signatures": []}
        update_summary(summary, "compile_and_test", {"is_successful": False, "error_type": "编译错误"})
        self.assertFalse(summary.get("compile_passed", False))

    def test_create_or_update_file_does_not_set_compile_flag(self) -> None:
        summary = {"file_mutated": False, "error_signatures": []}
        update_summary(summary, "create_or_update_file", {"is_successful": True})
        self.assertFalse(summary.get("compile_passed", False))

    def test_compile_failure_exhaustion_is_recorded(self) -> None:
        from unittest.mock import patch

        from script.leetcode.ai.messages import ToolCall
        from script.leetcode.ai.tool_round import ToolRoundProcessor
        from script.leetcode.config import AIConfig

        class _Executor:
            def execute(self, name, args):
                return {"is_successful": False, "error_type": "编译错误", "error_message": "boom"}

        processor = ToolRoundProcessor(_Executor())
        calls = [
            ToolCall(
                id="call_1",
                type="function",
                function_name="compile_and_test",
                function_arguments="{}",
            ),
            ToolCall(
                id="call_2",
                type="function",
                function_name="compile_and_test",
                function_arguments="{}",
            ),
        ]
        with patch.object(AIConfig, "MAX_COMPILE_FIX_ATTEMPTS", 2):
            summary = processor.run(calls, problem_id=42, messages=[])

        self.assertTrue(summary.get("compile_fix_exhausted"))

    def test_compile_before_mutation_does_not_validate_new_files(self) -> None:
        from script.leetcode.ai.messages import ToolCall
        from script.leetcode.ai.tool_round import ToolRoundProcessor, should_short_circuit

        class _Executor:
            def execute(self, name, args):
                if name == "compile_and_test":
                    return {"is_successful": True, "message": "old files passed"}
                return {"is_successful": True, "message": "files updated"}

        processor = ToolRoundProcessor(_Executor())
        summary = processor.run(
            [
                ToolCall(
                    id="call_1",
                    type="function",
                    function_name="compile_and_test",
                    function_arguments="{}",
                ),
                ToolCall(
                    id="call_2",
                    type="function",
                    function_name="create_or_update_file",
                    function_arguments="{}",
                ),
            ],
            problem_id=42,
            messages=[],
        )

        self.assertFalse(should_short_circuit(summary))
        self.assertEqual(summary.get("mutation_version"), 1)
        self.assertEqual(summary.get("compile_passed_version"), 0)

    def test_problem_id_is_injected_for_file_tools(self) -> None:
        from script.leetcode.ai.messages import ToolCall
        from script.leetcode.ai.tool_round import ToolRoundProcessor

        class _Executor:
            def __init__(self):
                self.calls = []

            def execute(self, name, args):
                self.calls.append((name, args))
                return {"is_successful": True, "message": "staged"}

        executor = _Executor()
        processor = ToolRoundProcessor(executor)
        processor.run(
            [
                ToolCall(
                    id="call_1",
                    type="function",
                    function_name="create_or_update_file",
                    function_arguments='{"files": []}',
                )
            ],
            problem_id=928,
            messages=[],
        )

        assert executor.calls == [("create_or_update_file", {"files": [], "problem_id": 928})]


if __name__ == "__main__":
    unittest.main()
