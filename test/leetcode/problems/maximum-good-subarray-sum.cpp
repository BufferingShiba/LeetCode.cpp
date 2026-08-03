#include <gtest/gtest.h>

#include "leetcode/problems/maximum-good-subarray-sum.h"

namespace leetcode::problem_3026 {

class MaximumGoodSubarraySumTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumGoodSubarraySumSolution solution_;
};

TEST_P(MaximumGoodSubarraySumTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(solution_.maximumSubarraySum(nums, 1), 11);
}

TEST_P(MaximumGoodSubarraySumTest, Example2) {
  std::vector<int> nums = {-1, 3, 2, 4, 5};
  EXPECT_EQ(solution_.maximumSubarraySum(nums, 3), 11);
}

TEST_P(MaximumGoodSubarraySumTest, Example3) {
  std::vector<int> nums = {-1, -2, -3, -4};
  EXPECT_EQ(solution_.maximumSubarraySum(nums, 2), -6);
}

TEST_P(MaximumGoodSubarraySumTest, SelfAuthoredNoGoodSubarray) {
  std::vector<int> nums = {1, 1, 1};
  EXPECT_EQ(solution_.maximumSubarraySum(nums, 5), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumGoodSubarraySumTestSuites, MaximumGoodSubarraySumTest,
    ::testing::ValuesIn(MaximumGoodSubarraySumSolution().getStrategyNames()));

}  // namespace leetcode::problem_3026
