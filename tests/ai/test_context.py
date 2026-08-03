#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
import unittest

from script.leetcode.ai import result_utils
from script.leetcode.ai.context import compact_messages, estimate_chars


class TestToolResultCompaction(unittest.TestCase):
    def test_metadata_drops_duplicate_example_projects(self) -> None:
        compacted = result_utils.compact(
            {
                "is_successful": True,
                "tool_name": "fetch_problem_metadata",
                "title": "A problem",
                "description": "d" * 12_000,
                "examples": [{"input": "x", "output": "y"}],
                "framework_apis": {"solution_base": "s" * 10_000},
                "example_ordinary": {"source": "two sum"},
                "example_design": {"source": "lru cache"},
            }
        )

        self.assertNotIn("example_ordinary", compacted)
        self.assertNotIn("example_design", compacted)
        self.assertLess(len(compacted["description"]), 12_000)
        self.assertLess(len(compacted["framework_apis"]["solution_base"]), 10_000)
        self.assertIn("context_note", compacted)


class TestConversationCompaction(unittest.TestCase):
    def test_compaction_preserves_initial_request_and_valid_tail_boundary(self) -> None:
        messages = [
            {"role": "system", "content": "system"},
            {"role": "user", "content": "initial request"},
            {"role": "assistant", "content": "old reasoning" * 100},
            {
                "role": "tool",
                "tool_call_id": "metadata-1",
                "content": json.dumps(
                    {
                        "tool_name": "fetch_problem_metadata",
                        "is_successful": True,
                        "title": "Important problem",
                        "function_signature": "vector<int> solve(...)",
                        "description": "find the invariant",
                    }
                ),
            },
            {"role": "assistant", "content": "more old reasoning" * 100},
            {
                "role": "user",
                "content": "系统已在文件修改后自动执行 compile_and_test，结果如下。",
            },
            {
                "role": "assistant",
                "content": "",
                "tool_calls": [
                    {
                        "id": "compile-1",
                        "type": "function",
                        "function": {"name": "compile_and_test", "arguments": "{}"},
                    }
                ],
            },
            {
                "role": "tool",
                "tool_call_id": "compile-1",
                "content": json.dumps(
                    {
                        "tool_name": "compile_and_test",
                        "is_successful": True,
                        "message": "通过",
                    }
                ),
            },
            {"role": "user", "content": "继续完成并提交。"},
        ]

        compacted, dropped = compact_messages(
            messages, max_chars=700, keep_messages=4, summary_max_chars=600
        )

        self.assertGreater(dropped, 0)
        self.assertEqual(compacted[0], messages[0])
        self.assertEqual(compacted[1], messages[1])
        self.assertEqual(compacted[2]["role"], "user")
        self.assertIn("Important problem", compacted[2]["content"])
        self.assertNotEqual(compacted[3].get("role"), "tool")
        self.assertLessEqual(estimate_chars(compacted), estimate_chars(messages))


if __name__ == "__main__":
    unittest.main()
