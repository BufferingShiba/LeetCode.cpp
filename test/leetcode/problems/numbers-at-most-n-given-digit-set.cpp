#include <gtest/gtest.h>

#include "leetcode/problems/numbers-at-most-n-given-digit-set.h"

using namespace leetcode::problem_902;

class NumbersAtMostNGivenDigitSetTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  NumbersAtMostNGivenDigitSetSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(NumbersAtMostNGivenDigitSetTest, Example1) {
  std::vector<std::string> digits = {"1", "3", "5", "7"};
  int n = 100;
  ASSERT_EQ(solution.atMostNGivenDigitSet(digits, n), 20);
}

TEST_P(NumbersAtMostNGivenDigitSetTest, Example2) {
  std::vector<std::string> digits = {"1", "4", "9"};
  int n = 1000000000;
  ASSERT_EQ(solution.atMostNGivenDigitSet(digits, n), 29523);
}

TEST_P(NumbersAtMostNGivenDigitSetTest, Example3) {
  std::vector<std::string> digits = {"7"};
  int n = 8;
  ASSERT_EQ(solution.atMostNGivenDigitSet(digits, n), 1);
}

TEST_P(NumbersAtMostNGivenDigitSetTest, SelfAuthoredNSmallerThanAllDigits) {
  std::vector<std::string> digits = {"5", "7"};
  int n = 3;
  ASSERT_EQ(solution.atMostNGivenDigitSet(digits, n), 0);
}

TEST_P(NumbersAtMostNGivenDigitSetTest, SelfAuthoredSingleDigitExactMatch) {
  std::vector<std::string> digits = {"5"};
  int n = 5;
  ASSERT_EQ(solution.atMostNGivenDigitSet(digits, n), 1);
}

TEST_P(NumbersAtMostNGivenDigitSetTest, SelfAuthoredAllDigitsOneToNine) {
  std::vector<std::string> digits = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
  int n = 100;
  // 1-digit: 9, 2-digit: 9^2=81, total=90; no 3-digit since n=100, only "1"+"0"+"0" cannot match '0'
  ASSERT_EQ(solution.atMostNGivenDigitSet(digits, n), 90);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, NumbersAtMostNGivenDigitSetTest,
    ::testing::ValuesIn(
        NumbersAtMostNGivenDigitSetSolution().getStrategyNames()));
