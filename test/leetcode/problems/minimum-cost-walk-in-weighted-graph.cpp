#include <gtest/gtest.h>

#include "leetcode/problems/minimum-cost-walk-in-weighted-graph.h"

namespace leetcode::problem_3108 {

class MinimumCostWalkInWeightedGraphTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumCostWalkInWeightedGraphSolution solution_;
};

TEST_P(MinimumCostWalkInWeightedGraphTest, Example1) {
  int n = 5;
  std::vector<std::vector<int>> edges = {{0, 1, 7}, {1, 3, 7}, {1, 2, 1}};
  std::vector<std::vector<int>> query = {{0, 3}, {3, 4}};
  auto result = solution_.minimumCost(n, edges, query);
  std::vector<int> expected = {1, -1};
  EXPECT_EQ(result, expected);
}

TEST_P(MinimumCostWalkInWeightedGraphTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> edges = {
      {0, 2, 7}, {0, 1, 15}, {1, 2, 6}, {1, 2, 1}};
  std::vector<std::vector<int>> query = {{1, 2}};
  auto result = solution_.minimumCost(n, edges, query);
  std::vector<int> expected = {0};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MinimumCostWalkInWeightedGraphTest,
    testing::ValuesIn(
        MinimumCostWalkInWeightedGraphSolution().getStrategyNames()));

}  // namespace leetcode::problem_3108
