#include <gtest/gtest.h>

#include "leetcode/problems/target-sum.h"

namespace leetcode::problem_494 {

class TargetSumTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  TargetSumSolution solution_;
};

INSTANTIATE_TEST_SUITE_P(
    Strategy,
    TargetSumTest,
    ::testing::ValuesIn(TargetSumSolution().getStrategyNames()));

TEST_P(TargetSumTest, Example1) {
  std::vector<int> nums = {1, 1, 1, 1, 1};
  int target = 3;
  EXPECT_EQ(solution_.findTargetSumWays(nums, target), 5);
}

TEST_P(TargetSumTest, Example2) {
  std::vector<int> nums = {1};
  int target = 1;
  EXPECT_EQ(solution_.findTargetSumWays(nums, target), 1);
}

TEST_P(TargetSumTest, SelfAuthoredSingleElementNegativeTarget) {
  std::vector<int> nums = {1};
  int target = -1;
  EXPECT_EQ(solution_.findTargetSumWays(nums, target), 1);
}

TEST_P(TargetSumTest, SelfAuthoredImpossibleTarget) {
  std::vector<int> nums = {1, 2, 3};
  int target = 100;
  EXPECT_EQ(solution_.findTargetSumWays(nums, target), 0);
}

TEST_P(TargetSumTest, SelfAuthoredAllZeros) {
  std::vector<int> nums = {0, 0, 0};
  int target = 0;
  // Each zero can be +0 or -0, so 2^3 = 8 ways
  EXPECT_EQ(solution_.findTargetSumWays(nums, target), 8);
}

}  // namespace leetcode::problem_494
