#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/longest-strictly-increasing-or-strictly-decreasing-subarray.h"

namespace leetcode {
namespace problem_3105 {

class LongestStrictlyIncreasingOrStrictlyDecreasingSubarrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LongestStrictlyIncreasingOrStrictlyDecreasingSubarraySolution solution_;
};

TEST_P(LongestStrictlyIncreasingOrStrictlyDecreasingSubarrayTest, Example1) {
  std::vector<int> nums = {1, 4, 3, 3, 2};
  EXPECT_EQ(2, solution_.longestMonotonicSubarray(nums));
}

TEST_P(LongestStrictlyIncreasingOrStrictlyDecreasingSubarrayTest, Example2) {
  std::vector<int> nums = {3, 3, 3, 3};
  EXPECT_EQ(1, solution_.longestMonotonicSubarray(nums));
}

TEST_P(LongestStrictlyIncreasingOrStrictlyDecreasingSubarrayTest, Example3) {
  std::vector<int> nums = {3, 2, 1};
  EXPECT_EQ(3, solution_.longestMonotonicSubarray(nums));
}

TEST_P(LongestStrictlyIncreasingOrStrictlyDecreasingSubarrayTest,
       SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(1, solution_.longestMonotonicSubarray(nums));
}

TEST_P(LongestStrictlyIncreasingOrStrictlyDecreasingSubarrayTest,
       SelfAuthoredMonotonicAllIncreasing) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(5, solution_.longestMonotonicSubarray(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LongestStrictlyIncreasingOrStrictlyDecreasingSubarrayTestSuite,
    LongestStrictlyIncreasingOrStrictlyDecreasingSubarrayTest,
    ::testing::ValuesIn(
        LongestStrictlyIncreasingOrStrictlyDecreasingSubarraySolution()
            .getStrategyNames()));

}  // namespace problem_3105
}  // namespace leetcode
