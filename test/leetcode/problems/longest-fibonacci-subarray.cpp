#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/longest-fibonacci-subarray.h"

namespace leetcode {
namespace problem_3708 {
namespace {

using LongestFibonacciSubarrayTestParam = std::string;

class LongestFibonacciSubarrayTest
    : public testing::TestWithParam<LongestFibonacciSubarrayTestParam> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LongestFibonacciSubarraySolution solution;
};

TEST_P(LongestFibonacciSubarrayTest, Example1) {
  std::vector<int> nums = {1, 1, 1, 1, 2, 3, 5, 1};
  EXPECT_EQ(solution.longestSubarray(nums), 5);
}

TEST_P(LongestFibonacciSubarrayTest, Example2) {
  std::vector<int> nums = {5, 2, 7, 9, 16};
  EXPECT_EQ(solution.longestSubarray(nums), 5);
}

TEST_P(LongestFibonacciSubarrayTest, Example3) {
  std::vector<int> nums = {1000000000, 1000000000, 1000000000};
  EXPECT_EQ(solution.longestSubarray(nums), 2);
}

TEST_P(LongestFibonacciSubarrayTest, SelfAuthored) {
  // Minimal length = 3, all Fibonacci
  {
    std::vector<int> nums = {1, 2, 3};
    EXPECT_EQ(solution.longestSubarray(nums), 3);
  }

  // All same value (cannot form Fibonacci beyond length 2)
  {
    std::vector<int> nums = {2, 2, 2, 2, 2};
    EXPECT_EQ(solution.longestSubarray(nums), 2);
  }

  // Fibonacci sequence spanning entire array
  {
    std::vector<int> nums = {1, 1, 2, 3, 5, 8, 13, 21};
    EXPECT_EQ(solution.longestSubarray(nums), 8);
  }

  // Two separate Fibonacci runs
  {
    std::vector<int> nums = {1, 1, 2, 3, 0, 2, 2, 4, 6, 10};
    EXPECT_EQ(solution.longestSubarray(nums), 6);
  }

  // Large values near boundary
  {
    std::vector<int> nums = {500000000, 500000000, 1000000000};
    EXPECT_EQ(solution.longestSubarray(nums), 3);
  }
}

INSTANTIATE_TEST_SUITE_P(Strategies, LongestFibonacciSubarrayTest,
                         testing::ValuesIn(LongestFibonacciSubarraySolution()
                                               .getStrategyNames()));

}  // namespace
}  // namespace problem_3708
}  // namespace leetcode
