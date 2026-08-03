#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import unittest

from script.leetcode.ai.prompts import get_system_prompt


class TestSystemPromptBuilder(unittest.TestCase):
    def test_easy_prompt_is_compact_and_contains_key_rules(self) -> None:
        prompt = get_system_prompt("Easy")
        self.assertLess(len(prompt), 5000)
        self.assertIn("Easy 快路径", prompt)
        self.assertIn("首次 create_or_update_file", prompt)
        self.assertIn("默认只写一个最优 Accepted 策略", prompt)
        self.assertIn("SelfAuthored 测试必须满足题目约束", prompt)
        self.assertIn("slug（文件名是连字符", prompt)
        self.assertIn("source 的 include 只出现一个 `.h` 后缀", prompt)
        self.assertIn("自由函数名必须与 Solution 类的公开方法名不同", prompt)
        self.assertIn("SolutionBase` 的模板参数必须是精确签名的 `std::function", prompt)
        self.assertIn("header 的 public 区域声明题目原方法", prompt)
        self.assertIn("test 通过该公开方法调用", prompt)
        self.assertIn("`<gtest/gtest.h>`", prompt)
        self.assertIn("constructTree` 有多个重载", prompt)
        self.assertIn("constructTree({1, 2, 3})", prompt)
        self.assertIn("`levelOrderTraversal` 和 `levelOrder` 返回紧凑结果", prompt)
        self.assertIn("设计类题直接实现题目类，不使用 SolutionBase；但测试仍必须使用 `TEST_P`", prompt)

    def test_standard_prompt_adds_medium_hard_guidance(self) -> None:
        prompt = get_system_prompt("Hard")
        self.assertIn("Medium/Hard 标准路径", prompt)
        self.assertIn("贪心必须", prompt)
        self.assertNotIn("Easy 快路径", prompt)

    def test_scaffold_prompt_adds_scaffold_rules(self) -> None:
        prompt = get_system_prompt("Medium", scaffold_mode=True)
        self.assertIn("Scaffold 模式补充", prompt)
        self.assertIn("不能只提交测试文件", prompt)
        self.assertIn("不得残留 `/* Code here */`", prompt)

    def test_multi_strategy_prompt_is_explicit_opt_in(self) -> None:
        normal = get_system_prompt("Hard")
        multi = get_system_prompt("Hard", prefer_multiple_strategies=True)
        self.assertNotIn("多策略验证模式", normal)
        self.assertIn("多策略验证模式", multi)
        self.assertIn("2 个算法范式不同", multi)


if __name__ == "__main__":
    unittest.main()
