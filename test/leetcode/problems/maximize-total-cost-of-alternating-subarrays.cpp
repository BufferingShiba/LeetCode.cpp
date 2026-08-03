#include <gtest/gtest.h>

#include "leetcode/problems/maximize-total-cost-of-alternating-subarrays.h"

using namespace leetcode::problem_3196;

class MaximizeTotalCostOfAlternatingSubarraysTest : public testing::TestWithParam<std::string> {
 protected:
  MaximizeTotalCostOfAlternatingSubarraysSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(MaximizeTotalCostOfAlternatingSubarraysTest, Example1) {
  std::vector<int> nums = {1, -2, 3, 4};
  EXPECT_EQ(solution.maximumTotalCost(nums), 10);
}

TEST_P(MaximizeTotalCostOfAlternatingSubarraysTest, Example2) {
  std::vector<int> nums = {1, -1, 1, -1};
  EXPECT_EQ(solution.maximumTotalCost(nums), 4);
}

TEST_P(MaximizeTotalCostOfAlternatingSubarraysTest, Example3) {
  std::vector<int> nums = {0};
  EXPECT_EQ(solution.maximumTotalCost(nums), 0);
}

TEST_P(MaximizeTotalCostOfAlternatingSubarraysTest, Example4) {
  std::vector<int> nums = {1, -1};
  EXPECT_EQ(solution.maximumTotalCost(nums), 2);
}

TEST_P(MaximizeTotalCostOfAlternatingSubarraysTest, SelfAuthoredAllNegative) {
  std::vector<int> nums = {-5, -3, -1};
  // Best: keep whole array: -5 - (-3) + (-1) = -5 + 3 - 1 = -3
  EXPECT_EQ(solution.maximumTotalCost(nums), -3);
}

TEST_P(MaximizeTotalCostOfAlternatingSubarraysTest, SelfAuthoredAllPositive) {
  std::vector<int> nums = {2, 3, 4};
  // Split each: 2 + 3 + 4 = 9 (splitting always better since all positive)
  EXPECT_EQ(solution.maximumTotalCost(nums), 9);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximizeTotalCostOfAlternatingSubarraysTest,
    testing::ValuesIn(MaximizeTotalCostOfAlternatingSubarraysSolution().getStrategyNames()));
