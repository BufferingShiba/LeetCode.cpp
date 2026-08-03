#include <gtest/gtest.h>

#include "leetcode/problems/next-greater-numerically-balanced-number.h"

namespace leetcode::problem_2048 {

class NextGreaterNumericallyBalancedNumberTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  NextGreaterNumericallyBalancedNumberSolution solution;
};

TEST_P(NextGreaterNumericallyBalancedNumberTest, Example1) {
  EXPECT_EQ(solution.nextBeautifulNumber(1), 22);
}

TEST_P(NextGreaterNumericallyBalancedNumberTest, Example2) {
  EXPECT_EQ(solution.nextBeautifulNumber(1000), 1333);
}

TEST_P(NextGreaterNumericallyBalancedNumberTest, Example3) {
  EXPECT_EQ(solution.nextBeautifulNumber(3000), 3133);
}

TEST_P(NextGreaterNumericallyBalancedNumberTest, SelfAuthored) {
  // n = 0 → 1 is the smallest numerically balanced number (1 appears once)
  EXPECT_EQ(solution.nextBeautifulNumber(0), 1);
  // n = 21 → 22
  EXPECT_EQ(solution.nextBeautifulNumber(21), 22);
  // n = 22 → 122 (next strictly greater than 22 itself)
  EXPECT_EQ(solution.nextBeautifulNumber(22), 122);
  // n = 221 → 333 (221 is the largest permutation of {1,2,2}; next is 333)
  EXPECT_EQ(solution.nextBeautifulNumber(221), 333);
  // n = 1,000,000 → 1,224,444 (smallest 7-digit balanced number > 10^6)
  EXPECT_EQ(solution.nextBeautifulNumber(1000000), 1224444);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NextGreaterNumericallyBalancedNumberTest,
    testing::ValuesIn(
        NextGreaterNumericallyBalancedNumberSolution().getStrategyNames()));

}  // namespace leetcode::problem_2048
