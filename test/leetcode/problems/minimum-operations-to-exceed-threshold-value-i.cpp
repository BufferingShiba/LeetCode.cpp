#include <gtest/gtest.h>

#include "leetcode/problems/minimum-operations-to-exceed-threshold-value-i.h"

namespace leetcode::problem_3065 {

class MinimumOperationsToExceedThresholdValueITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumOperationsToExceedThresholdValueISolution solution;
};

TEST_P(MinimumOperationsToExceedThresholdValueITest, Example1) {
  std::vector<int> nums = {2, 11, 10, 1, 3};
  int k = 10;
  EXPECT_EQ(solution.minOperations(nums, k), 3);
}

TEST_P(MinimumOperationsToExceedThresholdValueITest, Example2) {
  std::vector<int> nums = {1, 1, 2, 4, 9};
  int k = 1;
  EXPECT_EQ(solution.minOperations(nums, k), 0);
}

TEST_P(MinimumOperationsToExceedThresholdValueITest, Example3) {
  std::vector<int> nums = {1, 1, 2, 4, 9};
  int k = 9;
  EXPECT_EQ(solution.minOperations(nums, k), 4);
}

TEST_P(MinimumOperationsToExceedThresholdValueITest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {5, 5, 5, 5};
  int k = 5;
  EXPECT_EQ(solution.minOperations(nums, k), 0);
}

TEST_P(MinimumOperationsToExceedThresholdValueITest, SelfAuthoredAllLess) {
  std::vector<int> nums = {1, 2, 3};
  int k = 100;
  EXPECT_EQ(solution.minOperations(nums, k), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumOperationsToExceedThresholdValueITest,
    ::testing::ValuesIn(
        MinimumOperationsToExceedThresholdValueISolution().getStrategyNames()));

}  // namespace leetcode::problem_3065
