#include <gtest/gtest.h>

#include "leetcode/problems/next-special-palindrome-number.h"

using namespace leetcode::problem_3646;

class NextSpecialPalindromeNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  NextSpecialPalindromeNumberSolution solution;
};

TEST_P(NextSpecialPalindromeNumberTest, Example1) {
  EXPECT_EQ(solution.specialPalindrome(2), 22);
}

TEST_P(NextSpecialPalindromeNumberTest, Example2) {
  EXPECT_EQ(solution.specialPalindrome(33), 212);
}

TEST_P(NextSpecialPalindromeNumberTest, SelfAuthoredSmall) {
  // n = 0  -> smallest special > 0 is 1 (digit 1 appears once, palindrome)
  EXPECT_EQ(solution.specialPalindrome(0), 1);
  // n = 1  -> next is 22
  EXPECT_EQ(solution.specialPalindrome(1), 22);
  // n = 21 -> next is 22
  EXPECT_EQ(solution.specialPalindrome(21), 22);
  // n = 22 -> next is 212 (22 itself is special, need strictly greater)
  EXPECT_EQ(solution.specialPalindrome(22), 212);
}

INSTANTIATE_TEST_SUITE_P(Strategies, NextSpecialPalindromeNumberTest,
                         ::testing::ValuesIn(NextSpecialPalindromeNumberSolution()
                                                 .getStrategyNames()));
