#include <gtest/gtest.h>
#include "leetcode/problems/longest-subarray-of-1s-after-deleting-one-element.h"

using namespace leetcode::problem_1493;

class LongestSubarrayOf1sAfterDeletingOneElementTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  LongestSubarrayOf1sAfterDeletingOneElementSolution solution;
};

TEST_P(LongestSubarrayOf1sAfterDeletingOneElementTest, Example1) {
  std::vector<int> nums = {1, 1, 0, 1};
  EXPECT_EQ(solution.longestSubarray(nums), 3);
}

TEST_P(LongestSubarrayOf1sAfterDeletingOneElementTest, Example2) {
  std::vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  EXPECT_EQ(solution.longestSubarray(nums), 5);
}

TEST_P(LongestSubarrayOf1sAfterDeletingOneElementTest, Example3) {
  std::vector<int> nums = {1, 1, 1};
  EXPECT_EQ(solution.longestSubarray(nums), 2);
}

TEST_P(LongestSubarrayOf1sAfterDeletingOneElementTest, SelfAuthoredAllZeros) {
  std::vector<int> nums = {0, 0, 0};
  EXPECT_EQ(solution.longestSubarray(nums), 0);
}

TEST_P(LongestSubarrayOf1sAfterDeletingOneElementTest, SelfAuthoredSingleElementOne) {
  std::vector<int> nums = {1};
  EXPECT_EQ(solution.longestSubarray(nums), 0);
}

TEST_P(LongestSubarrayOf1sAfterDeletingOneElementTest, SelfAuthoredSingleElementZero) {
  std::vector<int> nums = {0};
  EXPECT_EQ(solution.longestSubarray(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    LongestSubarrayOf1sAfterDeletingOneElementTest,
    testing::ValuesIn(LongestSubarrayOf1sAfterDeletingOneElementSolution().getStrategyNames()));
