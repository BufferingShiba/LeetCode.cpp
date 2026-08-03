#include <gtest/gtest.h>

#include "leetcode/problems/longest-palindrome.h"

namespace leetcode {
namespace problem_409 {
namespace {

class LongestPalindromeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestPalindromeSolution solution;
};

TEST_P(LongestPalindromeTest, Example1) {
  EXPECT_EQ(solution.longestPalindrome("abccccdd"), 7);
}

TEST_P(LongestPalindromeTest, Example2) {
  EXPECT_EQ(solution.longestPalindrome("a"), 1);
}

TEST_P(LongestPalindromeTest, AllEven) {
  EXPECT_EQ(solution.longestPalindrome("aabb"), 4);
}

TEST_P(LongestPalindromeTest, MultipleOddUsesSingleCenter) {
  EXPECT_EQ(solution.longestPalindrome("aaabbbcc"), 7);
}

INSTANTIATE_TEST_SUITE_P(
    LongestPalindromeTestCases, LongestPalindromeTest,
    ::testing::ValuesIn(LongestPalindromeSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_409
}  // namespace leetcode
