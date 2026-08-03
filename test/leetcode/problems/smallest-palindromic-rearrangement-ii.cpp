#include <gtest/gtest.h>
#include "leetcode/problems/smallest-palindromic-rearrangement-ii.h"

using namespace leetcode::problem_3518;

class SmallestPalindromicRearrangementIiTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  SmallestPalindromicRearrangementIiSolution solution;
};

TEST_P(SmallestPalindromicRearrangementIiTest, Example1) {
  EXPECT_EQ(solution.smallestPalindrome("abba", 2), "baab");
}

TEST_P(SmallestPalindromicRearrangementIiTest, Example2) {
  EXPECT_EQ(solution.smallestPalindrome("aa", 2), "");
}

TEST_P(SmallestPalindromicRearrangementIiTest, Example3) {
  EXPECT_EQ(solution.smallestPalindrome("bacab", 1), "abcba");
}

TEST_P(SmallestPalindromicRearrangementIiTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution.smallestPalindrome("a", 1), "a");
  EXPECT_EQ(solution.smallestPalindrome("z", 2), "");
}

TEST_P(SmallestPalindromicRearrangementIiTest, SelfAuthoredAllSameEven) {
  // "aaaa" – only "aaaa"
  EXPECT_EQ(solution.smallestPalindrome("aaaa", 1), "aaaa");
  EXPECT_EQ(solution.smallestPalindrome("aaaa", 2), "");
}

TEST_P(SmallestPalindromicRearrangementIiTest, SelfAuthoredAllSameOdd) {
  // "aaa" – only "aaa"
  EXPECT_EQ(solution.smallestPalindrome("aaa", 1), "aaa");
  EXPECT_EQ(solution.smallestPalindrome("aaa", 2), "");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SmallestPalindromicRearrangementIiTest,
    testing::ValuesIn(
        SmallestPalindromicRearrangementIiSolution().getStrategyNames()));
