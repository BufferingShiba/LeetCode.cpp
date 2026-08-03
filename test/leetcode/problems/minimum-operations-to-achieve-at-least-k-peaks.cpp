#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/minimum-operations-to-achieve-at-least-k-peaks.h"

using namespace leetcode::problem_3892;

class MinimumOperationsToAchieveAtLeastKPeaksTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumOperationsToAchieveAtLeastKPeaksSolution solution;
};

TEST_P(MinimumOperationsToAchieveAtLeastKPeaksTest, Example1) {
  std::vector<int> nums = {2, 1, 2};
  int k = 1;
  EXPECT_EQ(solution.minOperations(nums, k), 1);
}

TEST_P(MinimumOperationsToAchieveAtLeastKPeaksTest, Example2) {
  std::vector<int> nums = {4, 5, 3, 6};
  int k = 2;
  EXPECT_EQ(solution.minOperations(nums, k), 0);
}

TEST_P(MinimumOperationsToAchieveAtLeastKPeaksTest, Example3) {
  std::vector<int> nums = {3, 7, 3};
  int k = 2;
  EXPECT_EQ(solution.minOperations(nums, k), -1);
}

TEST_P(MinimumOperationsToAchieveAtLeastKPeaksTest, AlreadyPeaks) {
  // nums = [1, 10, 1, 10, 1] has peaks at indices 1 and 3, k=2 -> 0 ops
  std::vector<int> nums = {1, 10, 1, 10, 1};
  int k = 2;
  EXPECT_EQ(solution.minOperations(nums, k), 0);
}

TEST_P(MinimumOperationsToAchieveAtLeastKPeaksTest, ImpossibleTooManyPeaks) {
  // n=5, max peaks = 2, k=3 is impossible
  std::vector<int> nums = {1, 10, 1, 10, 1};
  int k = 3;
  EXPECT_EQ(solution.minOperations(nums, k), -1);
}

TEST_P(MinimumOperationsToAchieveAtLeastKPeaksTest, NeedAllOperations) {
  // n=4, all equal to 1, need 2 peaks.
  // cost[i] = max(1,1)+1-1 = 1. Pick positions 0 and 2 (non-adjacent), total = 2.
  std::vector<int> nums = {1, 1, 1, 1};
  int k = 2;
  EXPECT_EQ(solution.minOperations(nums, k), 2);
}

TEST_P(MinimumOperationsToAchieveAtLeastKPeaksTest, SmallN) {
  // n=2, k=1
  std::vector<int> nums = {5, 3};
  int k = 1;
  // cost[0] = max(3,3)+1-5 = 0 (already peak)
  // cost[1] = max(5,5)+1-3 = 3
  EXPECT_EQ(solution.minOperations(nums, k), 0);
}

TEST_P(MinimumOperationsToAchieveAtLeastKPeaksTest, KEqualsZero) {
  std::vector<int> nums = {1, 2, 3};
  int k = 0;
  EXPECT_EQ(solution.minOperations(nums, k), 0);
}

TEST_P(MinimumOperationsToAchieveAtLeastKPeaksTest, SinglePeakNeeded) {
  // nums=[3,5,3,5], already has peaks at 1 and 3, k=1 -> 0 ops
  std::vector<int> nums = {3, 5, 3, 5};
  int k = 1;
  EXPECT_EQ(solution.minOperations(nums, k), 0);
}

INSTANTIATE_TEST_SUITE_P(Strategies,
                         MinimumOperationsToAchieveAtLeastKPeaksTest,
                         testing::ValuesIn(MinimumOperationsToAchieveAtLeastKPeaksSolution()
                                               .getStrategyNames()));
