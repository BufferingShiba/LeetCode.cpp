#include "leetcode/problems/maximum-width-ramp.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_962 {

class MaximumWidthRampTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumWidthRampSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumWidthRampTest,
    ::testing::ValuesIn(MaximumWidthRampSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [6,0,8,2,1,5]
// Output: 4
TEST_P(MaximumWidthRampTest, OfficialExample1) {
  vector<int> nums = {6, 0, 8, 2, 1, 5};
  int result = solution.maxWidthRamp(nums);
  EXPECT_EQ(4, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [9,8,1,0,1,9,4,0,4,1]
// Output: 7
TEST_P(MaximumWidthRampTest, OfficialExample2) {
  vector<int> nums = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
  int result = solution.maxWidthRamp(nums);
  EXPECT_EQ(7, result);
}

// ===== SelfAuthored edge case: strictly decreasing array (no ramp) =====
TEST_P(MaximumWidthRampTest, NoRampDecreasing) {
  vector<int> nums = {5, 4, 3, 2, 1};
  int result = solution.maxWidthRamp(nums);
  EXPECT_EQ(0, result);
}

// ===== SelfAuthored edge case: strictly increasing array (full-width ramp) =====
TEST_P(MaximumWidthRampTest, IncreasingArray) {
  vector<int> nums = {1, 2, 3, 4, 5};
  int result = solution.maxWidthRamp(nums);
  EXPECT_EQ(4, result);
}

}  // namespace problem_962
}  // namespace leetcode
