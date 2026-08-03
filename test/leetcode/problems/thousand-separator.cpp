#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/thousand-separator.h"

namespace leetcode::problem_1556 {

class ThousandSeparatorTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ThousandSeparatorSolution solution;
};

TEST_P(ThousandSeparatorTest, Example1) {
  EXPECT_EQ(solution.thousandSeparator(987), "987");
}

TEST_P(ThousandSeparatorTest, Example2) {
  EXPECT_EQ(solution.thousandSeparator(1234), "1.234");
}

TEST_P(ThousandSeparatorTest, SelfAuthoredLargerNumber) {
  EXPECT_EQ(solution.thousandSeparator(1234567), "1.234.567");
}

TEST_P(ThousandSeparatorTest, SelfAuthoredZero) {
  EXPECT_EQ(solution.thousandSeparator(0), "0");
}

INSTANTIATE_TEST_SUITE_P(
    ThousandSeparatorStrategies, ThousandSeparatorTest,
    ::testing::ValuesIn(ThousandSeparatorSolution().getStrategyNames()));

}  // namespace leetcode::problem_1556
