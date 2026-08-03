#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/lexicographically-smallest-palindrome.h"

namespace leetcode::problem_2697 {

class LexicographicallySmallestPalindromeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LexicographicallySmallestPalindromeSolution solution_;
};

TEST_P(LexicographicallySmallestPalindromeTest, Example1) {
  EXPECT_EQ(solution_.makeSmallestPalindrome("egcfe"), "efcfe");
}

TEST_P(LexicographicallySmallestPalindromeTest, Example2) {
  EXPECT_EQ(solution_.makeSmallestPalindrome("abcd"), "abba");
}

TEST_P(LexicographicallySmallestPalindromeTest, Example3) {
  EXPECT_EQ(solution_.makeSmallestPalindrome("seven"), "neven");
}

TEST_P(LexicographicallySmallestPalindromeTest, SelfAuthoredAlreadyPalindrome) {
  EXPECT_EQ(solution_.makeSmallestPalindrome("abcba"), "abcba");
}

TEST_P(LexicographicallySmallestPalindromeTest, SelfAuthoredSingleCharacter) {
  EXPECT_EQ(solution_.makeSmallestPalindrome("a"), "a");
}

TEST_P(LexicographicallySmallestPalindromeTest, SelfAuthoredAllSameCharacters) {
  EXPECT_EQ(solution_.makeSmallestPalindrome("zzzz"), "zzzz");
}

INSTANTIATE_TEST_SUITE_P(
    LexicographicallySmallestPalindromeTestSuite,
    LexicographicallySmallestPalindromeTest,
    ::testing::ValuesIn(
        LexicographicallySmallestPalindromeSolution().getStrategyNames()));

}  // namespace leetcode::problem_2697
