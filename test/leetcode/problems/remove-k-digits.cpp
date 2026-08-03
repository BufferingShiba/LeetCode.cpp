#include <gtest/gtest.h>

#include "leetcode/problems/remove-k-digits.h"

using namespace leetcode::problem_402;

class RemoveKDigitsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  RemoveKDigitsSolution solution;
};

TEST_P(RemoveKDigitsTest, Example1) {
  EXPECT_EQ(solution.removeKdigits("1432219", 3), "1219");
}

TEST_P(RemoveKDigitsTest, Example2) {
  EXPECT_EQ(solution.removeKdigits("10200", 1), "200");
}

TEST_P(RemoveKDigitsTest, Example3) {
  EXPECT_EQ(solution.removeKdigits("10", 2), "0");
}

TEST_P(RemoveKDigitsTest, SelfAuthoredRemoveAllDigits) {
  EXPECT_EQ(solution.removeKdigits("12345", 5), "0");
}

TEST_P(RemoveKDigitsTest, SelfAuthoredLeadingZeroResult) {
  // "100" + k=1 → 移除 '1' 得 "00" → 去前导零 → "0"
  EXPECT_EQ(solution.removeKdigits("100", 1), "0");
}

TEST_P(RemoveKDigitsTest, SelfAuthoredNoPopNeeded) {
  // 单调递增序列，只需从末尾删除
  EXPECT_EQ(solution.removeKdigits("12345", 2), "123");
}

TEST_P(RemoveKDigitsTest, SelfAuthoredAllEqualDigits) {
  EXPECT_EQ(solution.removeKdigits("1111", 2), "11");
}

INSTANTIATE_TEST_SUITE_P(Strategies,
                         RemoveKDigitsTest,
                         ::testing::ValuesIn(RemoveKDigitsSolution()
                                                 .getStrategyNames()));
