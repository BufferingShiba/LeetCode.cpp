#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-sum-of-m-non-overlapping-subarrays-i.h"

namespace leetcode {
namespace problem_3956 {

class MaximumSumOfMNonOverlappingSubarraysITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumSumOfMNonOverlappingSubarraysISolution solution;
};

TEST_P(MaximumSumOfMNonOverlappingSubarraysITest, Example1) {
  std::vector<int> nums = {4, 1, -5, 2};
  EXPECT_EQ(7LL, solution.maximumSum(nums, 2, 1, 3));
}

TEST_P(MaximumSumOfMNonOverlappingSubarraysITest, Example2) {
  std::vector<int> nums = {1, 0, 3, 4};
  EXPECT_EQ(8LL, solution.maximumSum(nums, 2, 1, 2));
}

TEST_P(MaximumSumOfMNonOverlappingSubarraysITest, Example3) {
  std::vector<int> nums = {-1, 7, -4};
  EXPECT_EQ(6LL, solution.maximumSum(nums, 1, 2, 3));
}

TEST_P(MaximumSumOfMNonOverlappingSubarraysITest, Example4) {
  std::vector<int> nums = {-3, -4, -1};
  EXPECT_EQ(-1LL, solution.maximumSum(nums, 2, 1, 2));
}

TEST_P(MaximumSumOfMNonOverlappingSubarraysITest, SelfAuthoredSinglePositive) {
  std::vector<int> nums = {5};
  EXPECT_EQ(5LL, solution.maximumSum(nums, 1, 1, 1));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumSumOfMNonOverlappingSubarraysITests,
    MaximumSumOfMNonOverlappingSubarraysITest,
    ::testing::ValuesIn(
        MaximumSumOfMNonOverlappingSubarraysISolution().getStrategyNames()));

}  // namespace problem_3956
}  // namespace leetcode
