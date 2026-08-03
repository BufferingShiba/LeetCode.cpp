#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "leetcode/problems/valid-palindrome-ii.h"

namespace leetcode {
namespace problem_680 {

class ValidPalindromeIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ValidPalindromeIiSolution solution;
};

TEST_P(ValidPalindromeIiTest, Example1) {
  EXPECT_TRUE(solution.validPalindrome("aba"));
}

TEST_P(ValidPalindromeIiTest, Example2) {
  EXPECT_TRUE(solution.validPalindrome("abca"));
}

TEST_P(ValidPalindromeIiTest, Example3) {
  EXPECT_FALSE(solution.validPalindrome("abc"));
}

TEST_P(ValidPalindromeIiTest, SingleChar) {
  EXPECT_TRUE(solution.validPalindrome("a"));
}

TEST_P(ValidPalindromeIiTest, AlreadyPalindrome) {
  EXPECT_TRUE(solution.validPalindrome("racecar"));
}

TEST_P(ValidPalindromeIiTest, DeleteFirstChar) {
  EXPECT_TRUE(solution.validPalindrome("deeee"));
}

TEST_P(ValidPalindromeIiTest, TwoCharSame) {
  EXPECT_TRUE(solution.validPalindrome("aa"));
}

INSTANTIATE_TEST_SUITE_P(
    ValidPalindromeIiStrategies,
    ValidPalindromeIiTest,
    ::testing::ValuesIn(ValidPalindromeIiSolution().getStrategyNames()));

}  // namespace problem_680
}  // namespace leetcode
