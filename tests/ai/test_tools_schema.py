#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import unittest
from unittest.mock import patch

from script.leetcode.ai import result_utils
from script.leetcode.ai.tools import ToolExecutor


class DummyRepository:
    pass


class TestToolResultSchema(unittest.TestCase):
    def setUp(self) -> None:
        self.executor = ToolExecutor(DummyRepository())

    def test_unknown_tool_is_normalized(self) -> None:
        result = self.executor.execute("not_exists_tool", {})
        self.assertEqual(result.get("status"), "error")
        self.assertFalse(result.get("is_successful"))
        self.assertEqual(result.get("error_type"), "tool_not_found")
        self.assertIn("message", result)
        self.assertIn("retryable", result)
        self.assertIn("artifacts", result)

    def test_generated_files_are_mapped_to_artifacts(self) -> None:
        normalized = result_utils.normalize(
            {
                "is_successful": True,
                "status_message": "ok",
                "generated_files": [
                    {"file_category": "source", "file_path": "src/a.cpp"},
                    {"file_category": "header", "file_path": "include/a.h"},
                ],
            },
            tool_name="create_or_update_file",
        )
        self.assertEqual(normalized.get("status"), "success")
        self.assertEqual(normalized.get("message"), "ok")
        artifacts = normalized.get("artifacts", [])
        self.assertEqual(len(artifacts), 2)
        self.assertEqual(artifacts[0].get("type"), "file")
        self.assertEqual(artifacts[0].get("category"), "source")
        self.assertEqual(artifacts[0].get("path"), "src/a.cpp")

    def test_string_problem_id_is_normalized_before_dispatch(self) -> None:
        with patch.object(
            self.executor._metadata,
            "fetch",
            return_value={"is_successful": True, "problem_id": 42},
        ) as fetch:
            result = self.executor.execute(
                "fetch_problem_metadata", {"problem_id": "42"}
            )

        fetch.assert_called_once_with(problem_id=42)
        self.assertTrue(result["is_successful"])

    def test_single_file_update_shorthand_is_wrapped_as_files(self) -> None:
        with patch.object(
            self.executor._files,
            "create_or_update",
            return_value={"is_successful": True, "status_message": "ok"},
        ) as update:
            result = self.executor.execute(
                "create_or_update_file",
                {
                    "problem_id": "42",
                    "file_category": "source",
                    "content": "int answer = 42;",
                    "overwrite_existing": True,
                },
            )

        update.assert_called_once_with(
            problem_id=42,
            files=[{"file_category": "source", "content": "int answer = 42;"}],
            overwrite_existing=True,
        )
        self.assertTrue(result["is_successful"])

    def test_file_content_alias_is_normalized_inside_files(self) -> None:
        with patch.object(
            self.executor._files,
            "create_or_update",
            return_value={"is_successful": True, "status_message": "ok"},
        ) as update:
            result = self.executor.execute(
                "create_or_update_file",
                {
                    "problem_id": 42,
                    "files": [
                        {"file_category": "header", "file_content": "#pragma once"},
                        {"file_category": "test", "content": "TEST_P(XTest, Example1) {}"},
                    ],
                },
            )

        update.assert_called_once_with(
            problem_id=42,
            files=[
                {"file_category": "header", "content": "#pragma once"},
                {"file_category": "test", "content": "TEST_P(XTest, Example1) {}"},
            ],
        )
        self.assertTrue(result["is_successful"])

    def test_file_content_alias_is_normalized_for_top_level_shorthand(self) -> None:
        with patch.object(
            self.executor._files,
            "create_or_update",
            return_value={"is_successful": True, "status_message": "ok"},
        ) as update:
            result = self.executor.execute(
                "create_or_update_file",
                {
                    "problem_id": 42,
                    "file_category": "source",
                    "file_content": "int answer = 42;",
                    "overwrite_existing": True,
                },
            )

        update.assert_called_once_with(
            problem_id=42,
            files=[{"file_category": "source", "content": "int answer = 42;"}],
            overwrite_existing=True,
        )
        self.assertTrue(result["is_successful"])

    def test_nested_arguments_wrapper_is_unwrapped(self) -> None:
        with patch.object(
            self.executor._files,
            "create_or_update",
            return_value={"is_successful": True, "status_message": "ok"},
        ) as update:
            result = self.executor.execute(
                "create_or_update_file",
                {
                    "arguments": {
                        "problem_id": 42,
                        "files": [{"file_category": "source", "content": "int answer = 42;"}],
                    }
                },
            )

        update.assert_called_once_with(
            problem_id=42,
            files=[{"file_category": "source", "content": "int answer = 42;"}],
        )
        self.assertTrue(result["is_successful"])


if __name__ == "__main__":
    unittest.main()
