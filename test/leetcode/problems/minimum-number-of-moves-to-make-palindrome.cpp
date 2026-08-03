#include <gtest/gtest.h>

#include "leetcode/problems/minimum-number-of-moves-to-make-palindrome.h"

using namespace leetcode::problem_2193;

class MinimumNumberOfMovesToMakePalindromeTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumNumberOfMovesToMakePalindromeSolution solution;
};

TEST_P(MinimumNumberOfMovesToMakePalindromeTest, Examples) {
  EXPECT_EQ(solution.minMovesToMakePalindrome("aabb"), 2);
  EXPECT_EQ(solution.minMovesToMakePalindrome("letelt"), 2);
}

TEST_P(MinimumNumberOfMovesToMakePalindromeTest, SelfAuthored) {
  // Single character is already a palindrome
  EXPECT_EQ(solution.minMovesToMakePalindrome("a"), 0);
  // Already a palindrome
  EXPECT_EQ(solution.minMovesToMakePalindrome("racecar"), 0);
  // Two characters, already palindrome
  EXPECT_EQ(solution.minMovesToMakePalindrome("aa"), 0);
  // Two different characters (guaranteed convertible: needs to be "aa" or "bb"? No,
  // for length 2 both must be same to form palindrome)
  // "ab" can't be palindrome, but problem guarantees convertibility.
  // Odd length: one odd character, others paired but scrambled
  EXPECT_EQ(solution.minMovesToMakePalindrome("baa"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    MinimumNumberOfMovesToMakePalindromeTest,
    testing::ValuesIn(MinimumNumberOfMovesToMakePalindromeSolution().getStrategyNames()));
