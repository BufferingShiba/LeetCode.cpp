#include <gtest/gtest.h>

#include "leetcode/problems/reachable-nodes-in-subdivided-graph.h"

using namespace leetcode::problem_882;

class ReachableNodesInSubdividedGraphTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  ReachableNodesInSubdividedGraphSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ReachableNodesInSubdividedGraphTest, Example1) {
  std::vector<std::vector<int>> edges = {{0, 1, 10}, {0, 2, 1}, {1, 2, 2}};
  int maxMoves = 6, n = 3;
  EXPECT_EQ(solution.reachableNodes(edges, maxMoves, n), 13);
}

TEST_P(ReachableNodesInSubdividedGraphTest, Example2) {
  std::vector<std::vector<int>> edges = {
      {0, 1, 4}, {1, 2, 6}, {0, 2, 8}, {1, 3, 1}};
  int maxMoves = 10, n = 4;
  EXPECT_EQ(solution.reachableNodes(edges, maxMoves, n), 23);
}

TEST_P(ReachableNodesInSubdividedGraphTest, Example3) {
  std::vector<std::vector<int>> edges = {
      {1, 2, 4}, {1, 4, 5}, {1, 3, 1}, {2, 3, 4}, {3, 4, 5}};
  int maxMoves = 17, n = 5;
  EXPECT_EQ(solution.reachableNodes(edges, maxMoves, n), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, ReachableNodesInSubdividedGraphTest,
    ::testing::ValuesIn(
        ReachableNodesInSubdividedGraphSolution().getStrategyNames()));
