#include <gtest/gtest.h>

#include "leetcode/problems/shortest-matching-substring.h"

using leetcode::problem_3455::ShortestMatchingSubstringSolution;

class ShortestMatchingSubstringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  ShortestMatchingSubstringSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ShortestMatchingSubstringTest, Example1) {
  EXPECT_EQ(solution.shortestMatchingSubstring("abaacbaecebce", "ba*c*ce"),
            8);
}

TEST_P(ShortestMatchingSubstringTest, Example2) {
  EXPECT_EQ(solution.shortestMatchingSubstring("baccbaadbc", "cc*baa*adb"),
            -1);
}

TEST_P(ShortestMatchingSubstringTest, Example3) {
  EXPECT_EQ(solution.shortestMatchingSubstring("a", "**"), 0);
}

TEST_P(ShortestMatchingSubstringTest, Example4) {
  EXPECT_EQ(solution.shortestMatchingSubstring("madlogic", "*adlogi*"), 6);
}

INSTANTIATE_TEST_SUITE_P(
    ShortestMatchingSubstringTestSuite, ShortestMatchingSubstringTest,
    ::testing::ValuesIn(ShortestMatchingSubstringSolution().getStrategyNames()));
