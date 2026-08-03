#include "leetcode/problems/longest-almost-palindromic-substring.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3844 {

class LongestAlmostPalindromicSubstringTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestAlmostPalindromicSubstringSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "abca"
// Output: 4
TEST_P(LongestAlmostPalindromicSubstringTest, OfficialExample1) {
  EXPECT_EQ(4, solution.almostPalindromic("abca"));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "abba"
// Output: 4
TEST_P(LongestAlmostPalindromicSubstringTest, OfficialExample2) {
  EXPECT_EQ(4, solution.almostPalindromic("abba"));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  s = "zzabba"
// Output: 5
TEST_P(LongestAlmostPalindromicSubstringTest, OfficialExample3) {
  EXPECT_EQ(5, solution.almostPalindromic("zzabba"));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, LongestAlmostPalindromicSubstringTest,
    ::testing::ValuesIn(LongestAlmostPalindromicSubstringSolution().getStrategyNames()));

}  // namespace problem_3844
}  // namespace leetcode
