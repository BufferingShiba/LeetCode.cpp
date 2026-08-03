#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/shortest-subarray-with-sum-at-least-k.h"

namespace leetcode {
namespace problem_862 {

class ShortestSubarrayWithSumAtLeastKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ShortestSubarrayWithSumAtLeastKSolution solution;
};

TEST_P(ShortestSubarrayWithSumAtLeastKTest, Example1) {
  std::vector<int> nums = {1};
  EXPECT_EQ(1, solution.shortestSubarray(nums, 1));
}

TEST_P(ShortestSubarrayWithSumAtLeastKTest, Example2) {
  std::vector<int> nums = {1, 2};
  EXPECT_EQ(-1, solution.shortestSubarray(nums, 4));
}

TEST_P(ShortestSubarrayWithSumAtLeastKTest, Example3) {
  std::vector<int> nums = {2, -1, 2};
  EXPECT_EQ(3, solution.shortestSubarray(nums, 3));
}

TEST_P(ShortestSubarrayWithSumAtLeastKTest, SelfAuthoredSingleBestNotAtEnd) {
  std::vector<int> nums = {3, -2, 3};
  EXPECT_EQ(1, solution.shortestSubarray(nums, 3));
}

INSTANTIATE_TEST_SUITE_P(
    ShortestSubarrayWithSumAtLeastKTestSuite,
    ShortestSubarrayWithSumAtLeastKTest,
    ::testing::ValuesIn(ShortestSubarrayWithSumAtLeastKSolution().getStrategyNames()));

}  // namespace problem_862
}  // namespace leetcode
