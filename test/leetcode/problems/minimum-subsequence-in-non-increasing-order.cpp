#include <gtest/gtest.h>

#include "leetcode/problems/minimum-subsequence-in-non-increasing-order.h"

using namespace leetcode::problem_1403;

class MinimumSubsequenceInNonIncreasingOrderTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  MinimumSubsequenceInNonIncreasingOrderSolution solution_;
};

// LeetCode Example 1
TEST_P(MinimumSubsequenceInNonIncreasingOrderTest, Example1) {
  std::vector<int> nums = {4, 3, 10, 9, 8};
  std::vector<int> expected = {10, 9};
  EXPECT_EQ(solution_.minSubsequence(nums), expected);
}

// LeetCode Example 2
TEST_P(MinimumSubsequenceInNonIncreasingOrderTest, Example2) {
  std::vector<int> nums = {4, 4, 7, 6, 7};
  std::vector<int> expected = {7, 7, 6};
  EXPECT_EQ(solution_.minSubsequence(nums), expected);
}

// SelfAuthored: single element
TEST_P(MinimumSubsequenceInNonIncreasingOrderTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  std::vector<int> expected = {5};
  EXPECT_EQ(solution_.minSubsequence(nums), expected);
}

// SelfAuthored: all equal elements
TEST_P(MinimumSubsequenceInNonIncreasingOrderTest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {1, 1, 1, 1};
  std::vector<int> expected = {1, 1, 1};
  EXPECT_EQ(solution_.minSubsequence(nums), expected);
}

// SelfAuthored: already sorted descending
TEST_P(MinimumSubsequenceInNonIncreasingOrderTest, SelfAuthoredAlreadySortedDescending) {
  std::vector<int> nums = {9, 5, 3, 1};
  std::vector<int> expected = {9, 5};
  EXPECT_EQ(solution_.minSubsequence(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumSubsequenceInNonIncreasingOrderTest,
    testing::ValuesIn(
        MinimumSubsequenceInNonIncreasingOrderSolution().getStrategyNames()));
