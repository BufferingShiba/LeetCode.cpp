#include <gtest/gtest.h>
#include "leetcode/problems/maximum-score-of-a-good-subarray.h"

using namespace leetcode::problem_1793;

class MaximumScoreOfAGoodSubarrayTest : public ::testing::TestWithParam<std::string> {
protected:
  MaximumScoreOfAGoodSubarraySolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(MaximumScoreOfAGoodSubarrayTest, Example1) {
  std::vector<int> nums = {1, 4, 3, 7, 4, 5};
  int k = 3;
  EXPECT_EQ(solution.maximumScore(nums, k), 15);
}

TEST_P(MaximumScoreOfAGoodSubarrayTest, Example2) {
  std::vector<int> nums = {5, 5, 4, 5, 4, 1, 1, 1};
  int k = 0;
  EXPECT_EQ(solution.maximumScore(nums, k), 20);
}

INSTANTIATE_TEST_SUITE_P(
  Strategies,
  MaximumScoreOfAGoodSubarrayTest,
  ::testing::ValuesIn(MaximumScoreOfAGoodSubarraySolution().getStrategyNames())
);
