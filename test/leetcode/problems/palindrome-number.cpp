#include <gtest/gtest.h>
#include "leetcode/problems/palindrome-number.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_9 {
namespace {

class PalindromeNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PalindromeNumberSolution solution;
};

TEST_P(PalindromeNumberTest, Example1) {
  EXPECT_TRUE(solution.isPalindrome(121));
}

TEST_P(PalindromeNumberTest, Example2) {
  EXPECT_FALSE(solution.isPalindrome(-121));
}

TEST_P(PalindromeNumberTest, Example3) {
  EXPECT_FALSE(solution.isPalindrome(10));
}

TEST_P(PalindromeNumberTest, SelfAuthoredNegativeNumber) {
  EXPECT_FALSE(solution.isPalindrome(-1));
}

TEST_P(PalindromeNumberTest, SelfAuthoredSingleDigit) {
  EXPECT_TRUE(solution.isPalindrome(7));
}

TEST_P(PalindromeNumberTest, SelfAuthoredEvenLengthPalindrome) {
  EXPECT_TRUE(solution.isPalindrome(1221));
}

INSTANTIATE_TEST_SUITE_P(
    PalindromeNumberTestCases, PalindromeNumberTest,
    ::testing::ValuesIn(PalindromeNumberSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_9
}  // namespace leetcode
