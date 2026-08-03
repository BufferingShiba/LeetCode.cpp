#include <gtest/gtest.h>

#include "leetcode/problems/maximize-sum-of-array-after-k-negations.h"

using namespace leetcode::problem_1005;

class MaximizeSumOfArrayAfterKNegationsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MaximizeSumOfArrayAfterKNegationsSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximizeSumOfArrayAfterKNegationsTest, Example1) {
  std::vector<int> nums = {4, 2, 3};
  int k = 1;
  EXPECT_EQ(solution.largestSumAfterKNegations(nums, k), 5);
}

TEST_P(MaximizeSumOfArrayAfterKNegationsTest, Example2) {
  std::vector<int> nums = {3, -1, 0, 2};
  int k = 3;
  EXPECT_EQ(solution.largestSumAfterKNegations(nums, k), 6);
}

TEST_P(MaximizeSumOfArrayAfterKNegationsTest, Example3) {
  std::vector<int> nums = {2, -3, -1, 5, -4};
  int k = 2;
  EXPECT_EQ(solution.largestSumAfterKNegations(nums, k), 13);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MaximizeSumOfArrayAfterKNegationsTest,
    ::testing::ValuesIn(
        MaximizeSumOfArrayAfterKNegationsSolution().getStrategyNames()));
