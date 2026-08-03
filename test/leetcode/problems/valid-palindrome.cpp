#include <gtest/gtest.h>

#include "leetcode/problems/valid-palindrome.h"

using namespace leetcode::problem_125;

class ValidPalindromeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ValidPalindromeSolution solution;
};

TEST_P(ValidPalindromeTest, OfficialExample1) {
  EXPECT_TRUE(solution.isPalindrome("A man, a plan, a canal: Panama"));
}

TEST_P(ValidPalindromeTest, OfficialExample2) {
  EXPECT_FALSE(solution.isPalindrome("race a car"));
}

TEST_P(ValidPalindromeTest, OfficialExample3) {
  EXPECT_TRUE(solution.isPalindrome(" "));
}

TEST_P(ValidPalindromeTest, SelfAuthoredSingleChar) {
  EXPECT_TRUE(solution.isPalindrome("a"));
}

TEST_P(ValidPalindromeTest, SelfAuthoredNumbersOnly) {
  EXPECT_TRUE(solution.isPalindrome("12321"));
  EXPECT_FALSE(solution.isPalindrome("12345"));
}

TEST_P(ValidPalindromeTest, SelfAuthoredMixedAlphanumeric) {
  EXPECT_TRUE(solution.isPalindrome("A1b2B1a"));
}

INSTANTIATE_TEST_SUITE_P(AllStrategies,
                         ValidPalindromeTest,
                         ::testing::ValuesIn(
                             ValidPalindromeSolution().getStrategyNames()));
