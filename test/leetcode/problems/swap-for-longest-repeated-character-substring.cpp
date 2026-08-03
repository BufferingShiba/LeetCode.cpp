#include "leetcode/problems/swap-for-longest-repeated-character-substring.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1156 {

class SwapForLongestRepeatedCharacterSubstringTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SwapForLongestRepeatedCharacterSubstringSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  text = "ababa"
// Output: 3
TEST_P(SwapForLongestRepeatedCharacterSubstringTest, OfficialExample1) {
  string text = "ababa";
  EXPECT_EQ(3, solution.maxRepOpt1(text));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  text = "aaabaaa"
// Output: 6
TEST_P(SwapForLongestRepeatedCharacterSubstringTest, OfficialExample2) {
  string text = "aaabaaa";
  EXPECT_EQ(6, solution.maxRepOpt1(text));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  text = "aaaaa"
// Output: 5
TEST_P(SwapForLongestRepeatedCharacterSubstringTest, OfficialExample3) {
  string text = "aaaaa";
  EXPECT_EQ(5, solution.maxRepOpt1(text));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, SwapForLongestRepeatedCharacterSubstringTest,
    ::testing::ValuesIn(SwapForLongestRepeatedCharacterSubstringSolution().getStrategyNames()));

}  // namespace problem_1156
}  // namespace leetcode
