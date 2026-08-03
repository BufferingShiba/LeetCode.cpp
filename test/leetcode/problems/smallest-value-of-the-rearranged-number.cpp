#include <gtest/gtest.h>

#include "leetcode/problems/smallest-value-of-the-rearranged-number.h"

using namespace leetcode::problem_2165;

class SmallestValueOfTheRearrangedNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  SmallestValueOfTheRearrangedNumberSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(SmallestValueOfTheRearrangedNumberTest, Example1) {
  EXPECT_EQ(solution.smallestNumber(310), 103);
}

TEST_P(SmallestValueOfTheRearrangedNumberTest, Example2) {
  EXPECT_EQ(solution.smallestNumber(-7605), -7650);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SmallestValueOfTheRearrangedNumberTest,
    ::testing::ValuesIn(
        SmallestValueOfTheRearrangedNumberSolution().getStrategyNames()));
