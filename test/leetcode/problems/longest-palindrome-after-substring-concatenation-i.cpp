#include <gtest/gtest.h>

#include "leetcode/problems/longest-palindrome-after-substring-concatenation-i.h"

namespace leetcode {
namespace problem_3503 {

class LongestPalindromeAfterSubstringConcatenationITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LongestPalindromeAfterSubstringConcatenationISolution solution_;
};

TEST_P(LongestPalindromeAfterSubstringConcatenationITest, Example1) {
  EXPECT_EQ(solution_.longestPalindrome("a", "a"), 2);
}

TEST_P(LongestPalindromeAfterSubstringConcatenationITest, Example2) {
  EXPECT_EQ(solution_.longestPalindrome("abc", "def"), 1);
}

TEST_P(LongestPalindromeAfterSubstringConcatenationITest, Example3) {
  EXPECT_EQ(solution_.longestPalindrome("b", "aaaa"), 4);
}

TEST_P(LongestPalindromeAfterSubstringConcatenationITest, Example4) {
  EXPECT_EQ(solution_.longestPalindrome("abcde", "ecdba"), 5);
}

TEST_P(LongestPalindromeAfterSubstringConcatenationITest, SelfAuthored) {
  // Single character each
  EXPECT_EQ(solution_.longestPalindrome("x", "y"), 1);
  // Both strings identical single char
  EXPECT_EQ(solution_.longestPalindrome("z", "z"), 2);
  // s is palindrome, t empty contribution
  EXPECT_EQ(solution_.longestPalindrome("aba", "x"), 3);
  // t is palindrome, s empty contribution
  EXPECT_EQ(solution_.longestPalindrome("x", "aba"), 3);
  // Cross palindrome with leftover in s
  EXPECT_EQ(solution_.longestPalindrome("ab", "a"), 3);  // "aba"
  // Cross palindrome with leftover in t
  EXPECT_EQ(solution_.longestPalindrome("a", "ba"), 3);  // "aba"
  // Full cross match
  EXPECT_EQ(solution_.longestPalindrome("ab", "ba"), 4);  // "abba"
  // Longer cross with palindrome center in s
  EXPECT_EQ(solution_.longestPalindrome("abc", "ba"), 5);  // "abcba"
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    LongestPalindromeAfterSubstringConcatenationITest,
    ::testing::ValuesIn(
        LongestPalindromeAfterSubstringConcatenationISolution()
            .getStrategyNames()));

}  // namespace problem_3503
}  // namespace leetcode
