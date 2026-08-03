#include "leetcode/problems/number-of-ways-to-arrive-at-destination.h"

#include <gtest/gtest.h>

namespace leetcode::problem_1976 {

class NumberOfWaysToArriveAtDestinationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfWaysToArriveAtDestinationSolution solution;
};

TEST_P(NumberOfWaysToArriveAtDestinationTest, Example1) {
  int n = 7;
  std::vector<std::vector<int>> roads = {
      {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3},
      {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
  EXPECT_EQ(solution.countPaths(n, roads), 4);
}

TEST_P(NumberOfWaysToArriveAtDestinationTest, Example2) {
  int n = 2;
  std::vector<std::vector<int>> roads = {{1, 0, 10}};
  EXPECT_EQ(solution.countPaths(n, roads), 1);
}

TEST_P(NumberOfWaysToArriveAtDestinationTest, SelfAuthoredSingleNode) {
  int n = 1;
  std::vector<std::vector<int>> roads = {};
  EXPECT_EQ(solution.countPaths(n, roads), 1);
}

TEST_P(NumberOfWaysToArriveAtDestinationTest, SelfAuthoredTwoEqualPaths) {
  int n = 3;
  std::vector<std::vector<int>> roads = {{0, 1, 5}, {1, 2, 5}, {0, 2, 10}};
  EXPECT_EQ(solution.countPaths(n, roads), 2);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfWaysToArriveAtDestinationTestSuite, NumberOfWaysToArriveAtDestinationTest,
    ::testing::ValuesIn(NumberOfWaysToArriveAtDestinationSolution().getStrategyNames()));

}  // namespace leetcode::problem_1976
