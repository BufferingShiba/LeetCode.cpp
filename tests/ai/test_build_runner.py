#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import types
import unittest
from unittest.mock import patch

from script.leetcode.ai.tools.build_runner import BuildRunner


class TestBuildRunnerClassification(unittest.TestCase):
    def test_gtest_failure_is_not_reported_as_compile_failure(self) -> None:
        fake = types.SimpleNamespace(
            returncode=1,
            stdout=(
                "[==========] Running 1 test\n"
                "[ RUN      ] Example\n"
                "Expected equality of these values\n"
                "[  FAILED  ] Example\n"
            ),
            stderr="",
        )
        with patch(
            "script.leetcode.ai.tools.build_runner._run_command",
            return_value=fake,
        ):
            result = BuildRunner().compile_and_test(42)

        self.assertFalse(result["is_successful"])
        self.assertEqual(result["error_type"], "结果错误")
        self.assertIn("测试失败", result["error_message"])

    def test_compile_failure_still_uses_compile_classifier(self) -> None:
        fake = types.SimpleNamespace(
            returncode=1,
            stdout="fatal error: leetcode/core.h: No such file or directory\n",
            stderr="",
        )
        with patch(
            "script.leetcode.ai.tools.build_runner._run_command",
            return_value=fake,
        ):
            result = BuildRunner().compile_and_test(42)

        self.assertFalse(result["is_successful"])
        self.assertEqual(result["error_type"], "头文件错误")
        self.assertEqual(result["error_message"], "编译失败")


if __name__ == "__main__":
    unittest.main()
