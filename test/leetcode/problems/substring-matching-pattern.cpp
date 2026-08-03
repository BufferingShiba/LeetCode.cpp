#include "leetcode/problems/substring-matching-pattern.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3407 {

class SubstringMatchingPatternTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SubstringMatchingPatternSolution solution;
};

TEST_P(SubstringMatchingPatternTest, Example1) {
  EXPECT_TRUE(solution.hasMatch("leetcode", "ee*e"));
}

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "leetcode", p = "ee*e"
// Output: true
TEST_P(SubstringMatchingPatternTest, OfficialExample1) {
  EXPECT_EQ(true, solution.hasMatch("leetcode", "ee*e"));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "car", p = "c*v"
// Output: false
TEST_P(SubstringMatchingPatternTest, OfficialExample2) {
  EXPECT_EQ(false, solution.hasMatch("car", "c*v"));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  s = "luck", p = "u*"
// Output: true
TEST_P(SubstringMatchingPatternTest, OfficialExample3) {
  EXPECT_EQ(true, solution.hasMatch("luck", "u*"));
}

// ===== Additional edge cases =====
TEST_P(SubstringMatchingPatternTest, StarReplacesZeroCharacters) {
  EXPECT_TRUE(solution.hasMatch("ab", "a*b"));
  EXPECT_TRUE(solution.hasMatch("xyz", "*"));
  EXPECT_TRUE(solution.hasMatch("abc", "*abc"));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SubstringMatchingPatternTest,
    ::testing::ValuesIn(SubstringMatchingPatternSolution().getStrategyNames()));

}  // namespace problem_3407
}  // namespace leetcode
