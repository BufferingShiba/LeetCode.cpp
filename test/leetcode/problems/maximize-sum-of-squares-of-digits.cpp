#include "leetcode/problems/maximize-sum-of-squares-of-digits.h"
#include <gtest/gtest.h>

#include <string>

using leetcode::problem_3723::MaximizeSumOfSquaresOfDigitsSolution;

class MaximizeSumOfSquaresOfDigitsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximizeSumOfSquaresOfDigitsSolution solution_;
};

TEST_P(MaximizeSumOfSquaresOfDigitsTest, Example1) {
  EXPECT_EQ("30", solution_.maxSumOfSquares(2, 3));
}

TEST_P(MaximizeSumOfSquaresOfDigitsTest, Example2) {
  EXPECT_EQ("98", solution_.maxSumOfSquares(2, 17));
}

TEST_P(MaximizeSumOfSquaresOfDigitsTest, Example3) {
  EXPECT_EQ("", solution_.maxSumOfSquares(1, 10));
}

TEST_P(MaximizeSumOfSquaresOfDigitsTest, SelfAuthoredSingleDigitExact) {
  EXPECT_EQ("9", solution_.maxSumOfSquares(1, 9));
}

TEST_P(MaximizeSumOfSquaresOfDigitsTest, SelfAuthoredManyZerosTailing) {
  // sum=5 num=4 -> digits {5,0,0,0} -> "5000"
  EXPECT_EQ("5000", solution_.maxSumOfSquares(4, 5));
}

TEST_P(MaximizeSumOfSquaresOfDigitsTest, SelfAuthoredMultipleNines) {
  // sum=20 num=5 -> {9,9,2,0,0} -> "99200"
  EXPECT_EQ("99200", solution_.maxSumOfSquares(5, 20));
}

INSTANTIATE_TEST_SUITE_P(
    MaximizeSumOfSquaresOfDigitsStrategies, MaximizeSumOfSquaresOfDigitsTest,
    ::testing::ValuesIn(MaximizeSumOfSquaresOfDigitsSolution().getStrategyNames()));
