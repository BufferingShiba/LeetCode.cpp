#include "leetcode/problems/maximum-product-subarray.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_152 {

class MaximumProductSubarrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumProductSubarraySolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumProductSubarrayTest,
    ::testing::ValuesIn(MaximumProductSubarraySolution().getStrategyNames()));

typedef MaximumProductSubarrayTest MaximumProductSubarrayParamTest;

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [2,3,-2,4]
// Output: 6
TEST_P(MaximumProductSubarrayTest, OfficialExample1) {
  vector<int> nums = {2, 3, -2, 4};
  int r = solution.maxProduct(nums);
  EXPECT_EQ(6, r);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [-2,0,-1]
// Output: 0
TEST_P(MaximumProductSubarrayTest, OfficialExample2) {
  vector<int> nums = {-2, 0, -1};
  int r = solution.maxProduct(nums);
  EXPECT_EQ(0, r);
}

// Single element
TEST_P(MaximumProductSubarrayTest, SingleElement) {
  vector<int> nums = {-3};
  int r = solution.maxProduct(nums);
  EXPECT_EQ(-3, r);
}

// All negative, two elements
TEST_P(MaximumProductSubarrayTest, TwoNegatives) {
  vector<int> nums = {-2, -3};
  int r = solution.maxProduct(nums);
  EXPECT_EQ(6, r);
}

// Contains zero in the middle
TEST_P(MaximumProductSubarrayTest, ZeroInMiddle) {
  vector<int> nums = {2, -5, -2, -4, 3};
  int r = solution.maxProduct(nums);
  EXPECT_EQ(24, r);
}

}  // namespace problem_152
}  // namespace leetcode
