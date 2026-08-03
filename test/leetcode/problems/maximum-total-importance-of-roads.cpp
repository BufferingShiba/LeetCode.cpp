#include <gtest/gtest.h>

#include "leetcode/problems/maximum-total-importance-of-roads.h"

using namespace leetcode::problem_2285;

class MaximumTotalImportanceOfRoadsTest
    : public testing::TestWithParam<std::string> {
 protected:
  MaximumTotalImportanceOfRoadsSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumTotalImportanceOfRoadsTest, Example1) {
  int n = 5;
  std::vector<std::vector<int>> roads = {
      {0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
  EXPECT_EQ(solution.maximumImportance(n, roads), 43);
}

TEST_P(MaximumTotalImportanceOfRoadsTest, Example2) {
  int n = 5;
  std::vector<std::vector<int>> roads = {{0, 3}, {2, 4}, {1, 3}};
  EXPECT_EQ(solution.maximumImportance(n, roads), 20);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumTotalImportanceOfRoads,
    MaximumTotalImportanceOfRoadsTest,
    testing::ValuesIn(
        MaximumTotalImportanceOfRoadsSolution().getStrategyNames()));
