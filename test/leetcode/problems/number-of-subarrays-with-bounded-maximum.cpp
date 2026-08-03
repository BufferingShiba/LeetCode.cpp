#include "leetcode/problems/number-of-subarrays-with-bounded-maximum.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_795 {

class NumberOfSubarraysWithBoundedMaximumTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfSubarraysWithBoundedMaximumSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [2,1,4,3], left = 2, right = 3
// Output: 3
TEST_P(NumberOfSubarraysWithBoundedMaximumTest, OfficialExample1) {
  std::vector<int> nums = {2, 1, 4, 3};
  EXPECT_EQ(3, solution.numSubarrayBoundedMax(nums, 2, 3));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [2,9,2,5,6], left = 2, right = 8
// Output: 7
TEST_P(NumberOfSubarraysWithBoundedMaximumTest, OfficialExample2) {
  std::vector<int> nums = {2, 9, 2, 5, 6};
  EXPECT_EQ(7, solution.numSubarrayBoundedMax(nums, 2, 8));
}

// ===== SelfAuthored: Single element inside range =====
TEST_P(NumberOfSubarraysWithBoundedMaximumTest, SingleElementInsideRange) {
  std::vector<int> nums = {5};
  EXPECT_EQ(1, solution.numSubarrayBoundedMax(nums, 2, 8));
}

// ===== SelfAuthored: Single element below range =====
TEST_P(NumberOfSubarraysWithBoundedMaximumTest, SingleElementBelowRange) {
  std::vector<int> nums = {1};
  EXPECT_EQ(0, solution.numSubarrayBoundedMax(nums, 2, 8));
}

// ===== SelfAuthored: All elements below range =====
TEST_P(NumberOfSubarraysWithBoundedMaximumTest, AllBelowRange) {
  std::vector<int> nums = {1, 1, 1};
  EXPECT_EQ(0, solution.numSubarrayBoundedMax(nums, 5, 8));
}

// ===== SelfAuthored: All elements above range =====
TEST_P(NumberOfSubarraysWithBoundedMaximumTest, AllAboveRange) {
  std::vector<int> nums = {9, 9};
  EXPECT_EQ(0, solution.numSubarrayBoundedMax(nums, 2, 8));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, NumberOfSubarraysWithBoundedMaximumTest,
    ::testing::ValuesIn(NumberOfSubarraysWithBoundedMaximumSolution().getStrategyNames()));

}  // namespace problem_795
}  // namespace leetcode
