#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/longest-common-subsequence.h"

namespace leetcode::problem_1143 {

class LongestCommonSubsequenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestCommonSubsequenceSolution solution;
};

TEST_P(LongestCommonSubsequenceTest, Example1) {
  EXPECT_EQ(solution.longestCommonSubsequence("abcde", "ace"), 3);
}

TEST_P(LongestCommonSubsequenceTest, Example2) {
  EXPECT_EQ(solution.longestCommonSubsequence("abc", "abc"), 3);
}

TEST_P(LongestCommonSubsequenceTest, Example3) {
  EXPECT_EQ(solution.longestCommonSubsequence("abc", "def"), 0);
}

TEST_P(LongestCommonSubsequenceTest, SelfAuthoredEmptySubsequence) {
  EXPECT_EQ(solution.longestCommonSubsequence("abc", "defg"), 0);
}

TEST_P(LongestCommonSubsequenceTest, SelfAuthoredSingleCharMatch) {
  EXPECT_EQ(solution.longestCommonSubsequence("a", "a"), 1);
}

TEST_P(LongestCommonSubsequenceTest, SelfAuthoredSingleCharNoMatch) {
  EXPECT_EQ(solution.longestCommonSubsequence("a", "b"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    LongestCommonSubsequenceTestSuite, LongestCommonSubsequenceTest,
    ::testing::ValuesIn(LongestCommonSubsequenceSolution().getStrategyNames()));

}  // namespace leetcode::problem_1143
