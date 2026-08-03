#include "leetcode/problems/minimum-operations-to-make-the-integer-zero.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2749 {

class MinimumOperationsToMakeTheIntegerZeroTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumOperationsToMakeTheIntegerZeroSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  num1 = 3, num2 = -2
// Output: 3
TEST_P(MinimumOperationsToMakeTheIntegerZeroTest, OfficialExample1) {
  int result = solution.makeTheIntegerZero(3, -2);
  EXPECT_EQ(3, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  num1 = 5, num2 = 7
// Output: -1
TEST_P(MinimumOperationsToMakeTheIntegerZeroTest, OfficialExample2) {
  int result = solution.makeTheIntegerZero(5, 7);
  EXPECT_EQ(-1, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumOperationsToMakeTheIntegerZeroTest,
    ::testing::ValuesIn(MinimumOperationsToMakeTheIntegerZeroSolution().getStrategyNames()));

}  // namespace problem_2749
}  // namespace leetcode
