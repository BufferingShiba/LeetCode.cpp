#include <gtest/gtest.h>
#include "leetcode/problems/minimum-partition-score.h"
#include <vector>

using leetcode::problem_3826::MinimumPartitionScoreSolution;

class MinimumPartitionScoreTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumPartitionScoreSolution solution;
};

TEST_P(MinimumPartitionScoreTest, Example1) {
  std::vector<int> nums = {5, 1, 2, 1};
  int k = 2;
  EXPECT_EQ(25, solution.minPartitionScore(nums, k));
}

TEST_P(MinimumPartitionScoreTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4};
  int k = 1;
  EXPECT_EQ(55, solution.minPartitionScore(nums, k));
}

TEST_P(MinimumPartitionScoreTest, Example3) {
  std::vector<int> nums = {1, 1, 1};
  int k = 3;
  EXPECT_EQ(3, solution.minPartitionScore(nums, k));
}

TEST_P(MinimumPartitionScoreTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {10};
  int k = 1;
  EXPECT_EQ(55, solution.minPartitionScore(nums, k));
}

TEST_P(MinimumPartitionScoreTest, SelfAuthoredSplitEverything) {
  std::vector<int> nums = {1, 2};
  int k = 2;
  // [1] -> 1, [2] -> 3, total 4
  EXPECT_EQ(4, solution.minPartitionScore(nums, k));
}

TEST_P(MinimumPartitionScoreTest, SelfAuthoredEqualSplit) {
  std::vector<int> nums = {3, 3};
  int k = 2;
  // [3] -> 6, [3] -> 6, total 12
  EXPECT_EQ(12, solution.minPartitionScore(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumPartitionScoreSuite, MinimumPartitionScoreTest,
    ::testing::ValuesIn(MinimumPartitionScoreSolution().getStrategyNames()));
