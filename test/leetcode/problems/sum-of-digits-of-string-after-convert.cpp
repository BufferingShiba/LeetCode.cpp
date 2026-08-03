#include <gtest/gtest.h>

#include "leetcode/problems/sum-of-digits-of-string-after-convert.h"

using leetcode::problem_1945::SumOfDigitsOfStringAfterConvertSolution;

class SumOfDigitsOfStringAfterConvertTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SumOfDigitsOfStringAfterConvertSolution solution;
};

TEST_P(SumOfDigitsOfStringAfterConvertTest, Example1) {
  EXPECT_EQ(solution.getLucky("iiii", 1), 36);
}

TEST_P(SumOfDigitsOfStringAfterConvertTest, Example2) {
  EXPECT_EQ(solution.getLucky("leetcode", 2), 6);
}

TEST_P(SumOfDigitsOfStringAfterConvertTest, Example3) {
  EXPECT_EQ(solution.getLucky("zbax", 2), 8);
}

TEST_P(SumOfDigitsOfStringAfterConvertTest, SelfAuthoredSingleLetterWithK1) {
  // 'z' -> 26, digit sum once -> 2 + 6 = 8
  EXPECT_EQ(solution.getLucky("z", 1), 8);
}

TEST_P(SumOfDigitsOfStringAfterConvertTest, SelfAuthoredMultipleTransforms) {
  // "abc" -> 123, transform once -> 6, then still 6
  EXPECT_EQ(solution.getLucky("abc", 3), 6);
}

INSTANTIATE_TEST_SUITE_P(
    SumOfDigitsOfStringAfterConvertTestSuite,
    SumOfDigitsOfStringAfterConvertTest,
    ::testing::ValuesIn(
        SumOfDigitsOfStringAfterConvertSolution().getStrategyNames()));
