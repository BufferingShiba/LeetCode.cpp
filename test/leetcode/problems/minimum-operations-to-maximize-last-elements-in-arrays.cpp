#include <gtest/gtest.h>

#include "leetcode/problems/minimum-operations-to-maximize-last-elements-in-arrays.h"

using namespace leetcode::problem_2934;

class MinimumOperationsToMaximizeLastElementsInArraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumOperationsToMaximizeLastElementsInArraysSolution solution_;
};

TEST_P(MinimumOperationsToMaximizeLastElementsInArraysTest, Example1) {
  std::vector<int> nums1 = {1, 2, 7};
  std::vector<int> nums2 = {4, 5, 3};
  EXPECT_EQ(solution_.minOperations(nums1, nums2), 1);
}

TEST_P(MinimumOperationsToMaximizeLastElementsInArraysTest, Example2) {
  std::vector<int> nums1 = {2, 3, 4, 5, 9};
  std::vector<int> nums2 = {8, 8, 4, 4, 4};
  EXPECT_EQ(solution_.minOperations(nums1, nums2), 2);
}

TEST_P(MinimumOperationsToMaximizeLastElementsInArraysTest, Example3) {
  std::vector<int> nums1 = {1, 5, 4};
  std::vector<int> nums2 = {2, 5, 3};
  EXPECT_EQ(solution_.minOperations(nums1, nums2), -1);
}

TEST_P(MinimumOperationsToMaximizeLastElementsInArraysTest, SelfAuthoredSingleElement) {
  std::vector<int> nums1 = {5};
  std::vector<int> nums2 = {3};
  EXPECT_EQ(solution_.minOperations(nums1, nums2), 0);
}

TEST_P(MinimumOperationsToMaximizeLastElementsInArraysTest, SelfAuthoredNeedSwapLast) {
  // Last element swap is necessary
  std::vector<int> nums1 = {10, 1};
  std::vector<int> nums2 = {1, 10};
  // Without swap: max1=1, max2=10; i=0: (10,1): 10<=1? no, swap: (1,10): 1<=1✓,10<=10✓ cost=1
  // With swap last: max1=10, max2=1; i=0: (10,1): 10<=10✓,1<=1✓ cost=0 + 1(last)=1
  // min=1
  EXPECT_EQ(solution_.minOperations(nums1, nums2), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MinimumOperationsToMaximizeLastElementsInArraysTest,
    ::testing::ValuesIn(
        MinimumOperationsToMaximizeLastElementsInArraysSolution()
            .getStrategyNames()));
