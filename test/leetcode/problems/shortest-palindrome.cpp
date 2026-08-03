#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/shortest-palindrome.h"

namespace leetcode::problem_214 {

class ShortestPalindromeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ShortestPalindromeSolution solution_;
};

TEST_P(ShortestPalindromeTest, Example1) {
  EXPECT_EQ(solution_.shortestPalindrome("aacecaaa"), "aaacecaaa");
}

TEST_P(ShortestPalindromeTest, Example2) {
  EXPECT_EQ(solution_.shortestPalindrome("abcd"), "dcbabcd");
}

TEST_P(ShortestPalindromeTest, SelfAuthoredAlreadyPalindrome) {
  EXPECT_EQ(solution_.shortestPalindrome("aba"), "aba");
}

TEST_P(ShortestPalindromeTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution_.shortestPalindrome("a"), "a");
}

TEST_P(ShortestPalindromeTest, SelfAuthoredEmptyString) {
  EXPECT_EQ(solution_.shortestPalindrome(""), "");
}

TEST_P(ShortestPalindromeTest, SelfAuthoredAllSameChars) {
  EXPECT_EQ(solution_.shortestPalindrome("aaaa"), "aaaa");
}

INSTANTIATE_TEST_SUITE_P(
    ShortestPalindromeTestSuite, ShortestPalindromeTest,
    ::testing::ValuesIn(ShortestPalindromeSolution().getStrategyNames()));

}  // namespace leetcode::problem_214
