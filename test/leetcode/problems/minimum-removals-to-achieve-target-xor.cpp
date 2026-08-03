#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-removals-to-achieve-target-xor.h"

using leetcode::problem_3877::MinimumRemovalsToAchieveTargetXorSolution;

class MinimumRemovalsToAchieveTargetXorTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumRemovalsToAchieveTargetXorSolution solution;
};

TEST_P(MinimumRemovalsToAchieveTargetXorTest, Example1) {
  std::vector<int> nums = {1, 2, 3};
  int target = 2;
  EXPECT_EQ(solution.minRemovals(nums, target), 1);
}

TEST_P(MinimumRemovalsToAchieveTargetXorTest, Example2) {
  std::vector<int> nums = {2, 4};
  int target = 1;
  EXPECT_EQ(solution.minRemovals(nums, target), -1);
}

TEST_P(MinimumRemovalsToAchieveTargetXorTest, Example3) {
  std::vector<int> nums = {7};
  int target = 7;
  EXPECT_EQ(solution.minRemovals(nums, target), 0);
}

TEST_P(MinimumRemovalsToAchieveTargetXorTest, SelfAuthoredRemoveAllTargetZero) {
  // [5,3,9] 全部 XOR = 5^3^9 = 15，target=0，需移除 XOR=15 子集，即全部三个
  std::vector<int> nums = {5, 3, 9};
  int target = 0;
  EXPECT_EQ(solution.minRemovals(nums, target), 3);

  // [5,5] 全部 XOR = 0，无需移除
  std::vector<int> nums2 = {5, 5};
  EXPECT_EQ(solution.minRemovals(nums2, 0), 0);
}

TEST_P(MinimumRemovalsToAchieveTargetXorTest, SingleExactMatch) {
  std::vector<int> nums = {4};
  EXPECT_EQ(solution.minRemovals(nums, 4), 0);
}

TEST_P(MinimumRemovalsToAchieveTargetXorTest, SelfAuthoredEmptyTargetFullRemoval) {
  std::vector<int> nums = {1, 2};
  // XOR of [1,2] = 3; 要得到 target=0，需移除 XOR=3 的子集 {1,2}，移除 2 个
  EXPECT_EQ(solution.minRemovals(nums, 0), 2);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumRemovalsToAchieveTargetXorTestSuite,
    MinimumRemovalsToAchieveTargetXorTest,
    ::testing::ValuesIn(
        MinimumRemovalsToAchieveTargetXorSolution().getStrategyNames()));
