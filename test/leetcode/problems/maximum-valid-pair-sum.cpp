#include "leetcode/problems/maximum-valid-pair-sum.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3979 {
namespace {

class MaximumValidPairSumTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumValidPairSumSolution solution_;
};

TEST_P(MaximumValidPairSumTest, Example1) {
  std::vector<int> nums = {1, 3, 5, 2, 8};
  EXPECT_EQ(solution_.maxValidPairSum(nums, 2), 13);
}

TEST_P(MaximumValidPairSumTest, Example2) {
  std::vector<int> nums = {5, 1, 9};
  EXPECT_EQ(solution_.maxValidPairSum(nums, 1), 14);
}

TEST_P(MaximumValidPairSumTest, OnlyFarthestPair) {
  std::vector<int> nums = {4, 2, 7, 1};
  EXPECT_EQ(solution_.maxValidPairSum(nums, 3), 5);
}

TEST_P(MaximumValidPairSumTest, BestLeftValueCanChange) {
  std::vector<int> nums = {1, 10, 2, 3, 20};
  EXPECT_EQ(solution_.maxValidPairSum(nums, 2), 30);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumValidPairSumStrategies, MaximumValidPairSumTest,
    ::testing::ValuesIn(MaximumValidPairSumSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3979
}  // namespace leetcode
