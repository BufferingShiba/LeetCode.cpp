#include "leetcode/problems/smallest-palindromic-rearrangement-i.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3517 {

class SmallestPalindromicRearrangementITest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SmallestPalindromicRearrangementISolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "z"
// Output: "z"
TEST_P(SmallestPalindromicRearrangementITest, OfficialExample1) {
  EXPECT_EQ(solution.smallestPalindrome("z"), "z");
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "babab"
// Output: "abbba"
TEST_P(SmallestPalindromicRearrangementITest, OfficialExample2) {
  EXPECT_EQ(solution.smallestPalindrome("babab"), "abbba");
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  s = "daccad"
// Output: "acddca"
TEST_P(SmallestPalindromicRearrangementITest, OfficialExample3) {
  EXPECT_EQ(solution.smallestPalindrome("daccad"), "acddca");
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SmallestPalindromicRearrangementITest,
    ::testing::ValuesIn(SmallestPalindromicRearrangementISolution().getStrategyNames()));

}  // namespace problem_3517
}  // namespace leetcode
