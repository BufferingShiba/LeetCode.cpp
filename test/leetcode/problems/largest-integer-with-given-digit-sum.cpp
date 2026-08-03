#include <gtest/gtest.h>

#include "leetcode/problems/largest-integer-with-given-digit-sum.h"

using namespace leetcode::problem_4000;

class LargestIntegerWithGivenDigitSumTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  LargestIntegerWithGivenDigitSumSolution solution;
};

TEST_P(LargestIntegerWithGivenDigitSumTest, Example1) {
  EXPECT_EQ(solution.largestInteger(2, 9), 90);
}

TEST_P(LargestIntegerWithGivenDigitSumTest, Example2) {
  EXPECT_EQ(solution.largestInteger(2, 19), -1);
}

TEST_P(LargestIntegerWithGivenDigitSumTest, Example3) {
  EXPECT_EQ(solution.largestInteger(5, 0), 0);
}

TEST_P(LargestIntegerWithGivenDigitSumTest, SelfAuthoredSingleDigitMax) {
  EXPECT_EQ(solution.largestInteger(1, 9), 9);
}

TEST_P(LargestIntegerWithGivenDigitSumTest, SelfAuthoredAllNines) {
  EXPECT_EQ(solution.largestInteger(3, 27), 999);
}

TEST_P(LargestIntegerWithGivenDigitSumTest, SelfAuthoredLeadingZeroPossible) {
  // n=3, s=5: largest is 500 (3 digits, not 50)
  EXPECT_EQ(solution.largestInteger(3, 5), 500);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    LargestIntegerWithGivenDigitSumTest,
    ::testing::ValuesIn(
        LargestIntegerWithGivenDigitSumSolution().getStrategyNames()));
