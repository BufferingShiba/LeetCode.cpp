#include <gtest/gtest.h>
#include "leetcode/problems/minimum-operations-to-reach-target-array.h"

using namespace leetcode::problem_3810;

class MinimumOperationsToReachTargetArrayTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumOperationsToReachTargetArraySolution solution;
};

TEST_P(MinimumOperationsToReachTargetArrayTest, Example1) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> target = {2, 1, 3};
  EXPECT_EQ(solution.minOperations(nums, target), 2);
}

TEST_P(MinimumOperationsToReachTargetArrayTest, Example2) {
  std::vector<int> nums = {4, 1, 4};
  std::vector<int> target = {5, 1, 4};
  EXPECT_EQ(solution.minOperations(nums, target), 1);
}

TEST_P(MinimumOperationsToReachTargetArrayTest, Example3) {
  std::vector<int> nums = {7, 3, 7};
  std::vector<int> target = {5, 5, 9};
  EXPECT_EQ(solution.minOperations(nums, target), 2);
}

TEST_P(MinimumOperationsToReachTargetArrayTest, SelfAuthoredAlreadyMatched) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::vector<int> target = {1, 2, 3, 4, 5};
  EXPECT_EQ(solution.minOperations(nums, target), 0);
}

TEST_P(MinimumOperationsToReachTargetArrayTest, SelfAuthoredAllDifferent) {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> target = {5, 6, 7, 8};
  EXPECT_EQ(solution.minOperations(nums, target), 4);
}

TEST_P(MinimumOperationsToReachTargetArrayTest, SelfAuthoredSameValueAllPositions) {
  std::vector<int> nums = {7, 7, 7, 7};
  std::vector<int> target = {1, 2, 3, 4};
  EXPECT_EQ(solution.minOperations(nums, target), 1);
}

TEST_P(MinimumOperationsToReachTargetArrayTest, SelfAuthoredSingleElementNeedsChange) {
  std::vector<int> nums = {5};
  std::vector<int> target = {10};
  EXPECT_EQ(solution.minOperations(nums, target), 1);
}

TEST_P(MinimumOperationsToReachTargetArrayTest, SelfAuthoredSingleElementAlreadyMatched) {
  std::vector<int> nums = {5};
  std::vector<int> target = {5};
  EXPECT_EQ(solution.minOperations(nums, target), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumOperationsToReachTargetArrayTest,
    testing::ValuesIn(MinimumOperationsToReachTargetArraySolution().getStrategyNames()));
