#include <gtest/gtest.h>

#include "leetcode/problems/minimum-operations-to-exceed-threshold-value-ii.h"

namespace leetcode {
namespace problem_3066 {
namespace {

class MinimumOperationsToExceedThresholdValueIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumOperationsToExceedThresholdValueIiSolution solution_;
};

TEST_P(MinimumOperationsToExceedThresholdValueIiTest, Example1) {
  std::vector<int> nums = {2, 11, 10, 1, 3};
  EXPECT_EQ(solution_.minOperations(nums, 10), 2);
}

TEST_P(MinimumOperationsToExceedThresholdValueIiTest, Example2) {
  std::vector<int> nums = {1, 1, 2, 4, 9};
  EXPECT_EQ(solution_.minOperations(nums, 20), 4);
}

TEST_P(MinimumOperationsToExceedThresholdValueIiTest, SelfAuthoredAllAlreadyAbove) {
  std::vector<int> nums = {5, 6, 7};
  EXPECT_EQ(solution_.minOperations(nums, 5), 0);
}

TEST_P(MinimumOperationsToExceedThresholdValueIiTest, SelfAuthoredRepeatedSmallValues) {
  std::vector<int> nums = {1, 1, 1, 1};
  EXPECT_EQ(solution_.minOperations(nums, 100), 3);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToExceedThresholdValueIiTestSuite,
    MinimumOperationsToExceedThresholdValueIiTest,
    ::testing::ValuesIn(
        MinimumOperationsToExceedThresholdValueIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3066
}  // namespace leetcode
