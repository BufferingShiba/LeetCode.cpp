#include "leetcode/problems/get-equal-substrings-within-budget.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1208 {

class GetEqualSubstringsWithinBudgetTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  GetEqualSubstringsWithinBudgetSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "abcd", t = "bcdf", maxCost = 3
// Output: 3
TEST_P(GetEqualSubstringsWithinBudgetTest, OfficialExample1) {
  EXPECT_EQ(3, solution.equalSubstring("abcd", "bcdf", 3));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "abcd", t = "cdef", maxCost = 3
// Output: 1
TEST_P(GetEqualSubstringsWithinBudgetTest, OfficialExample2) {
  EXPECT_EQ(1, solution.equalSubstring("abcd", "cdef", 3));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  s = "abcd", t = "acde", maxCost = 0
// Output: 1
TEST_P(GetEqualSubstringsWithinBudgetTest, OfficialExample3) {
  EXPECT_EQ(1, solution.equalSubstring("abcd", "acde", 0));
}

// ===== Edge Case: identical strings (zero total cost) =====
TEST_P(GetEqualSubstringsWithinBudgetTest, IdenticalStrings) {
  EXPECT_EQ(4, solution.equalSubstring("abcd", "abcd", 0));
}

// ===== Edge Case: nothing affordable (each char cost exceeds maxCost) =====
TEST_P(GetEqualSubstringsWithinBudgetTest, NothingAffordable) {
  EXPECT_EQ(0, solution.equalSubstring("kz", "za", 3));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, GetEqualSubstringsWithinBudgetTest,
    ::testing::ValuesIn(GetEqualSubstringsWithinBudgetSolution().getStrategyNames()));

}  // namespace problem_1208
}  // namespace leetcode
