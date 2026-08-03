#include <gtest/gtest.h>

#include "leetcode/problems/maximum-sum-of-m-non-overlapping-subarrays-ii.h"

using namespace leetcode::problem_3957;

class MaximumSumOfMNonOverlappingSubarraysIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MaximumSumOfMNonOverlappingSubarraysIiSolution solution;
};

TEST_P(MaximumSumOfMNonOverlappingSubarraysIiTest, Example1) {
  std::vector<int> nums = {4, 1, -5, 2};
  int m = 2, l = 1, r = 3;
  EXPECT_EQ(solution.maximumSum(nums, m, l, r), 7);
}

TEST_P(MaximumSumOfMNonOverlappingSubarraysIiTest, Example2) {
  std::vector<int> nums = {1, 0, 3, 4};
  int m = 2, l = 1, r = 2;
  EXPECT_EQ(solution.maximumSum(nums, m, l, r), 8);
}

TEST_P(MaximumSumOfMNonOverlappingSubarraysIiTest, Example3) {
  std::vector<int> nums = {-1, 7, -4};
  int m = 1, l = 2, r = 3;
  EXPECT_EQ(solution.maximumSum(nums, m, l, r), 6);
}

TEST_P(MaximumSumOfMNonOverlappingSubarraysIiTest, Example4) {
  std::vector<int> nums = {-3, -4, -1};
  int m = 2, l = 1, r = 2;
  EXPECT_EQ(solution.maximumSum(nums, m, l, r), -1);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, MaximumSumOfMNonOverlappingSubarraysIiTest,
    ::testing::ValuesIn(
        MaximumSumOfMNonOverlappingSubarraysIiSolution().getStrategyNames()));
