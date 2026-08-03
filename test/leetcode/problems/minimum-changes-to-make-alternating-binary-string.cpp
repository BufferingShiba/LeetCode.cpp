#include <gtest/gtest.h>
#include "leetcode/problems/minimum-changes-to-make-alternating-binary-string.h"

using namespace leetcode::problem_1758;

class MinimumChangesToMakeAlternatingBinaryStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumChangesToMakeAlternatingBinaryStringSolution solution;
};

TEST_P(MinimumChangesToMakeAlternatingBinaryStringTest, Example1) {
  EXPECT_EQ(solution.minOperations("0100"), 1);
}

TEST_P(MinimumChangesToMakeAlternatingBinaryStringTest, Example2) {
  EXPECT_EQ(solution.minOperations("10"), 0);
}

TEST_P(MinimumChangesToMakeAlternatingBinaryStringTest, Example3) {
  EXPECT_EQ(solution.minOperations("1111"), 2);
}

TEST_P(MinimumChangesToMakeAlternatingBinaryStringTest, SelfAuthored) {
  EXPECT_EQ(solution.minOperations("0"), 0);
  EXPECT_EQ(solution.minOperations("1"), 0);
  EXPECT_EQ(solution.minOperations("01"), 0);
  EXPECT_EQ(solution.minOperations("00"), 1);
  EXPECT_EQ(solution.minOperations("01010"), 0);
  EXPECT_EQ(solution.minOperations("10101"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    MinimumChangesToMakeAlternatingBinaryStringTest,
    ::testing::ValuesIn(MinimumChangesToMakeAlternatingBinaryStringSolution().getStrategyNames()));
