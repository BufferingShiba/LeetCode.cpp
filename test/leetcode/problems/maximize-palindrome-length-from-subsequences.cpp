#include "leetcode/problems/maximize-palindrome-length-from-subsequences.h"

#include <gtest/gtest.h>

#include <string>

namespace leetcode::problem_1771 {

using MaxPalSolution = MaximizePalindromeLengthFromSubsequencesSolution;

class MaximizePalindromeLengthFromSubsequencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaxPalSolution solution_;
};

TEST_P(MaximizePalindromeLengthFromSubsequencesTest, Example1) {
  EXPECT_EQ(solution_.longestPalindrome("cacb", "cbba"), 5);
}

TEST_P(MaximizePalindromeLengthFromSubsequencesTest, Example2) {
  EXPECT_EQ(solution_.longestPalindrome("ab", "ab"), 3);
}

TEST_P(MaximizePalindromeLengthFromSubsequencesTest, Example3) {
  EXPECT_EQ(solution_.longestPalindrome("aa", "bb"), 0);
}

TEST_P(MaximizePalindromeLengthFromSubsequencesTest, SelfAuthoredSingleCharEach) {
  EXPECT_EQ(solution_.longestPalindrome("a", "a"), 2);
  EXPECT_EQ(solution_.longestPalindrome("a", "b"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MaximizePalindromeLengthFromSubsequencesTestSuite,
    MaximizePalindromeLengthFromSubsequencesTest,
    ::testing::ValuesIn(MaxPalSolution().getStrategyNames()));

}  // namespace leetcode::problem_1771
