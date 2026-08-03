#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/find-the-longest-balanced-substring-of-a-binary-string.h"

namespace leetcode::problem_2609 {

class FindTheLongestBalancedSubstringOfABinaryStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheLongestBalancedSubstringOfABinaryStringSolution solution_;
};

TEST_P(FindTheLongestBalancedSubstringOfABinaryStringTest, Example1) {
  EXPECT_EQ(6, solution_.findTheLongestBalancedSubstring("01000111"));
}

TEST_P(FindTheLongestBalancedSubstringOfABinaryStringTest, Example2) {
  EXPECT_EQ(4, solution_.findTheLongestBalancedSubstring("00111"));
}

TEST_P(FindTheLongestBalancedSubstringOfABinaryStringTest, Example3) {
  EXPECT_EQ(0, solution_.findTheLongestBalancedSubstring("111"));
}

TEST_P(FindTheLongestBalancedSubstringOfABinaryStringTest, SelfAuthoredSingleBalanced) {
  EXPECT_EQ(2, solution_.findTheLongestBalancedSubstring("01"));
}

TEST_P(FindTheLongestBalancedSubstringOfABinaryStringTest, SelfAuthoredAllZeroes) {
  EXPECT_EQ(0, solution_.findTheLongestBalancedSubstring("000"));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheLongestBalancedSubstringOfABinaryStringTest,
    FindTheLongestBalancedSubstringOfABinaryStringTest,
    ::testing::ValuesIn(
        FindTheLongestBalancedSubstringOfABinaryStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_2609
