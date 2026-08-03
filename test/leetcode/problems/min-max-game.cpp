#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/min-max-game.h"

using leetcode::problem_2293::MinMaxGameSolution;

class MinMaxGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinMaxGameSolution solution;
};

TEST_P(MinMaxGameTest, Example1) {
  std::vector<int> nums = {1, 3, 5, 2, 4, 8, 2, 2};
  EXPECT_EQ(1, solution.minMaxGame(nums));
}

TEST_P(MinMaxGameTest, Example2) {
  std::vector<int> nums = {3};
  EXPECT_EQ(3, solution.minMaxGame(nums));
}

TEST_P(MinMaxGameTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  EXPECT_EQ(7, solution.minMaxGame(nums));
}

TEST_P(MinMaxGameTest, SelfAuthoredAllIncreasing) {
  std::vector<int> nums = {1, 2, 3, 4};
  // round1: newNums = [min(1,2), max(3,4)] = [1, 4]
  // round2: return min(1,4) = 1
  EXPECT_EQ(1, solution.minMaxGame(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinMaxGameTestSuite, MinMaxGameTest,
    ::testing::ValuesIn(MinMaxGameSolution().getStrategyNames()));
