#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-average-subarray-i.h"

namespace leetcode::problem_643 {

class MaximumAverageSubarrayITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumAverageSubarrayISolution solution_;
};

TEST_P(MaximumAverageSubarrayITest, Example1) {
  std::vector<int> nums = {1, 12, -5, -6, 50, 3};
  int k = 4;
  double expected = 12.75;
  EXPECT_NEAR(solution_.findMaxAverage(nums, k), expected, 1e-5);
}

TEST_P(MaximumAverageSubarrayITest, Example2) {
  std::vector<int> nums = {5};
  int k = 1;
  double expected = 5.0;
  EXPECT_NEAR(solution_.findMaxAverage(nums, k), expected, 1e-5);
}

TEST_P(MaximumAverageSubarrayITest, SelfAuthoredNegativeValues) {
  std::vector<int> nums = {-1, -2, -3, -4};
  int k = 2;
  double expected = -1.5;
  EXPECT_NEAR(solution_.findMaxAverage(nums, k), expected, 1e-5);
}

TEST_P(MaximumAverageSubarrayITest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {7, 7, 7, 7};
  int k = 3;
  double expected = 7.0;
  EXPECT_NEAR(solution_.findMaxAverage(nums, k), expected, 1e-5);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumAverageSubarrayISuite, MaximumAverageSubarrayITest,
    ::testing::ValuesIn(
        MaximumAverageSubarrayISolution().getStrategyNames()));

}  // namespace leetcode::problem_643
