#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/longest-even-odd-subarray-with-threshold.h"

namespace leetcode {
namespace problem_2760 {

class LongestEvenOddSubarrayWithThresholdTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestEvenOddSubarrayWithThresholdSolution solution;
};

TEST_P(LongestEvenOddSubarrayWithThresholdTest, Example1) {
  std::vector<int> nums = {3, 2, 5, 4};
  int threshold = 5;
  EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), 3);
}

TEST_P(LongestEvenOddSubarrayWithThresholdTest, Example2) {
  std::vector<int> nums = {1, 2};
  int threshold = 2;
  EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), 1);
}

TEST_P(LongestEvenOddSubarrayWithThresholdTest, Example3) {
  std::vector<int> nums = {2, 3, 4, 5};
  int threshold = 4;
  EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), 3);
}

TEST_P(LongestEvenOddSubarrayWithThresholdTest, SelfAuthoredSingleEven) {
  std::vector<int> nums = {2};
  int threshold = 10;
  EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), 1);
}

TEST_P(LongestEvenOddSubarrayWithThresholdTest, SelfAuthoredAllAboveThreshold) {
  std::vector<int> nums = {4, 6, 8};
  int threshold = 3;
  EXPECT_EQ(solution.longestAlternatingSubarray(nums, threshold), 0);
}

INSTANTIATE_TEST_SUITE_P(
    LongestEvenOddSubarrayWithThresholdTestSuite,
    LongestEvenOddSubarrayWithThresholdTest,
    ::testing::ValuesIn(
        LongestEvenOddSubarrayWithThresholdSolution().getStrategyNames()));

}  // namespace problem_2760
}  // namespace leetcode
