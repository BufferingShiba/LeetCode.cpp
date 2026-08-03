#include <gtest/gtest.h>

#include "leetcode/problems/maximum-subarray-sum-after-multiplier.h"

using namespace leetcode::problem_3976;

class MaximumSubarraySumAfterMultiplierTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MaximumSubarraySumAfterMultiplierSolution solution;
};

TEST_P(MaximumSubarraySumAfterMultiplierTest, Example1) {
  std::vector<int> nums = {1, -2, 3, 4, -5};
  int k = 2;
  EXPECT_EQ(solution.maxSubarraySum(nums, k), 14);
}

TEST_P(MaximumSubarraySumAfterMultiplierTest, Example2) {
  std::vector<int> nums = {-5, -4, -3};
  int k = 2;
  EXPECT_EQ(solution.maxSubarraySum(nums, k), -1);
}

TEST_P(MaximumSubarraySumAfterMultiplierTest, SelfAuthoredSinglePositive) {
  std::vector<int> nums = {5};
  int k = 2;
  // max(5*2=10, 5/2=2) = 10
  EXPECT_EQ(solution.maxSubarraySum(nums, k), 10);
}

TEST_P(MaximumSubarraySumAfterMultiplierTest, SelfAuthoredSingleNegative) {
  std::vector<int> nums = {-5};
  int k = 2;
  // max(-5*2=-10, -5/2=-2) = -2
  EXPECT_EQ(solution.maxSubarraySum(nums, k), -2);
}

TEST_P(MaximumSubarraySumAfterMultiplierTest, SelfAuthoredAllPositiveK1) {
  std::vector<int> nums = {1, 2, 3};
  int k = 1;
  // k=1: multiply/divide no effect, original Kadane max = 6
  EXPECT_EQ(solution.maxSubarraySum(nums, k), 6);
}

TEST_P(MaximumSubarraySumAfterMultiplierTest, SelfAuthoredDivideMiddleNegative) {
  std::vector<int> nums = {10, -100, 10};
  int k = 100;
  // multiply first element: 1000 is best (dp1 path)
  EXPECT_EQ(solution.maxSubarraySum(nums, k), 1000);
}

INSTANTIATE_TEST_SUITE_P(
    All, MaximumSubarraySumAfterMultiplierTest,
    testing::ValuesIn(
        MaximumSubarraySumAfterMultiplierSolution().getStrategyNames()));
