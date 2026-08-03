#include <gtest/gtest.h>
#include <string>

#include "leetcode/problems/break-a-palindrome.h"

namespace leetcode {
namespace problem_1328 {

class BreakAPalindromeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  BreakAPalindromeSolution solution_;
};

TEST_P(BreakAPalindromeTest, Example1) {
  EXPECT_EQ(solution_.breakPalindrome("abccba"), "aaccba");
}

TEST_P(BreakAPalindromeTest, Example2) {
  EXPECT_EQ(solution_.breakPalindrome("a"), "");
}

TEST_P(BreakAPalindromeTest, AllA) {
  EXPECT_EQ(solution_.breakPalindrome("aaaa"), "aaab");
}

TEST_P(BreakAPalindromeTest, FirstHalfAllA) {
  EXPECT_EQ(solution_.breakPalindrome("aaabaaa"), "aaabaab");
}

TEST_P(BreakAPalindromeTest, TwoCharsAllA) {
  EXPECT_EQ(solution_.breakPalindrome("aa"), "ab");
}

INSTANTIATE_TEST_SUITE_P(
    BreakAPalindromeSuite, BreakAPalindromeTest,
    ::testing::ValuesIn(BreakAPalindromeSolution().getStrategyNames()));

}  // namespace problem_1328
}  // namespace leetcode
