#include <gtest/gtest.h>

#include "leetcode/problems/alternating-digit-sum.h"

using leetcode::problem_2544::AlternatingDigitSumSolution;

class AlternatingDigitSumTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  AlternatingDigitSumSolution solution_;
};

TEST_P(AlternatingDigitSumTest, Example1) {
  EXPECT_EQ(4, solution_.alternateDigitSum(521));
}

TEST_P(AlternatingDigitSumTest, Example2) {
  EXPECT_EQ(1, solution_.alternateDigitSum(111));
}

TEST_P(AlternatingDigitSumTest, Example3) {
  EXPECT_EQ(0, solution_.alternateDigitSum(886996));
}

TEST_P(AlternatingDigitSumTest, SelfAuthoredSingleDigit) {
  EXPECT_EQ(7, solution_.alternateDigitSum(7));
}

TEST_P(AlternatingDigitSumTest, SelfAuthoredEvenLength) {
  // n = 12 -> (+1)+(-2) = -1
  EXPECT_EQ(-1, solution_.alternateDigitSum(12));
}

INSTANTIATE_TEST_SUITE_P(
    AlternatingDigitSumTestSuite, AlternatingDigitSumTest,
    ::testing::ValuesIn(AlternatingDigitSumSolution().getStrategyNames()));
