#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/minimum-cost-to-equalize-arrays-using-swaps.h"

namespace leetcode {
namespace problem_3868 {

class MinimumCostToEqualizeArraysUsingSwapsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCostToEqualizeArraysUsingSwapsSolution solution;
};

TEST_P(MinimumCostToEqualizeArraysUsingSwapsTest, Example1) {
  std::vector<int> nums1 = {10, 20};
  std::vector<int> nums2 = {20, 10};
  EXPECT_EQ(0, solution.minCost(nums1, nums2));
}

TEST_P(MinimumCostToEqualizeArraysUsingSwapsTest, Example2) {
  std::vector<int> nums1 = {10, 10};
  std::vector<int> nums2 = {20, 20};
  EXPECT_EQ(1, solution.minCost(nums1, nums2));
}

TEST_P(MinimumCostToEqualizeArraysUsingSwapsTest, Example3) {
  std::vector<int> nums1 = {10, 20};
  std::vector<int> nums2 = {30, 40};
  EXPECT_EQ(-1, solution.minCost(nums1, nums2));
}

TEST_P(MinimumCostToEqualizeArraysUsingSwapsTest, SelfAuthoredChain) {
  std::vector<int> nums1 = {1, 1, 2, 2};
  std::vector<int> nums2 = {3, 3, 3, 3};
  EXPECT_EQ(2, solution.minCost(nums1, nums2));
}

TEST_P(MinimumCostToEqualizeArraysUsingSwapsTest, SelfAuthoredAllEqualCols) {
  std::vector<int> nums1 = {5, 5, 7, 7};
  std::vector<int> nums2 = {5, 5, 7, 7};
  EXPECT_EQ(0, solution.minCost(nums1, nums2));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumCostToEqualizeArraysUsingSwapsTestSuite,
    MinimumCostToEqualizeArraysUsingSwapsTest,
    ::testing::ValuesIn(
        MinimumCostToEqualizeArraysUsingSwapsSolution().getStrategyNames()));

}  // namespace problem_3868
}  // namespace leetcode
