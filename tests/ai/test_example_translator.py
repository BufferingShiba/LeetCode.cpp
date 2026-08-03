import json
import unittest

from script.leetcode.ai.scaffold import _has_intact_parameterized_registration
from script.leetcode.ai.tools.example_translator import _parse_llm_output


class TestExampleTranslator(unittest.TestCase):
    def test_parse_rejects_a_complete_test_wrapper_as_body(self) -> None:
        payload = json.dumps({"1": "TEST_P(FooTest, Example1) { EXPECT_EQ(1, 1); }"})

        self.assertEqual(_parse_llm_output(payload, {1}), {})

    def test_parse_accepts_a_plain_test_body(self) -> None:
        payload = json.dumps({"1": "EXPECT_EQ(1, solution.answer(1));"})

        self.assertEqual(
            _parse_llm_output(payload, {1}),
            {1: "EXPECT_EQ(1, solution.answer(1));\n"},
        )

    def test_registration_guard_rejects_a_split_macro(self) -> None:
        valid = """
INSTANTIATE_TEST_SUITE_P(
    LeetCode, FooTest,
    ::testing::ValuesIn(FooSolution().getStrategyNames()));
"""

        self.assertTrue(_has_intact_parameterized_registration(valid))
        self.assertFalse(
            _has_intact_parameterized_registration(valid.replace("::testing", "::te"))
        )


if __name__ == "__main__":
    unittest.main()
