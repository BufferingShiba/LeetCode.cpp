#include <gtest/gtest.h>

#include "leetcode/problems/minimum-operations-to-transform-array.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3724 {
namespace {

using leetcode::problem_3724::MinimumOperationsToTransformArraySolution;

}  // namespace

class MinimumOperationsToTransformArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumOperationsToTransformArraySolution solution;
};

TEST_P(MinimumOperationsToTransformArrayTest, Example1) {
  std::vector<int> nums1 = {2, 8};
  std::vector<int> nums2 = {1, 7, 3};
  EXPECT_EQ(4, solution.minOperations(nums1, nums2));
}

TEST_P(MinimumOperationsToTransformArrayTest, Example2) {
  std::vector<int> nums1 = {1, 3, 6};
  std::vector<int> nums2 = {2, 4, 5, 3};
  EXPECT_EQ(4, solution.minOperations(nums1, nums2));
}

TEST_P(MinimumOperationsToTransformArrayTest, Example3) {
  std::vector<int> nums1 = {2};
  std::vector<int> nums2 = {3, 4};
  EXPECT_EQ(3, solution.minOperations(nums1, nums2));
}

TEST_P(MinimumOperationsToTransformArrayTest, SelfAuthoredAlreadyAlignedAppendOnly) {
  std::vector<int> nums1 = {5};
  std::vector<int> nums2 = {5, 6};
  // Position 0 already matches (0 ops). Append copies 5, increment to 6: +2.
  EXPECT_EQ(2, solution.minOperations(nums1, nums2));
}

TEST_P(MinimumOperationsToTransformArrayTest, SelfAuthoredAppendInsideInterval) {
  std::vector<int> nums1 = {10, 20};
  std::vector<int> nums2 = {12, 20, 11};
  // |10-12|+|20-20|=2, +1 append, copy within interval of idx0, target 11
  // inside [10,12] -> distance 0. Total 3.
  EXPECT_EQ(3, solution.minOperations(nums1, nums2));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToTransformArraySuite,
    MinimumOperationsToTransformArrayTest,
    ::testing::ValuesIn(MinimumOperationsToTransformArraySolution().getStrategyNames()));

}  // namespace problem_3724
}  // namespace leetcode
