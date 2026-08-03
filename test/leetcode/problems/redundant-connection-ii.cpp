#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/redundant-connection-ii.h"

using namespace leetcode::problem_685;

class RedundantConnectionIiTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RedundantConnectionIiSolution solution;
};

TEST_P(RedundantConnectionIiTest, Example1) {
  std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
  std::vector<int> expected = {2, 3};
  EXPECT_EQ(solution.findRedundantDirectedConnection(edges), expected);
}

TEST_P(RedundantConnectionIiTest, Example2) {
  std::vector<std::vector<int>> edges = {
      {1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
  std::vector<int> expected = {4, 1};
  EXPECT_EQ(solution.findRedundantDirectedConnection(edges), expected);
}

TEST_P(RedundantConnectionIiTest, SelfAuthoredPureCycleNoIndegreeTwo) {
  // A single directed cycle, no extra parent.
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 1}};
  std::vector<int> expected = {3, 1};
  EXPECT_EQ(solution.findRedundantDirectedConnection(edges), expected);
}

TEST_P(RedundantConnectionIiTest, SelfAuthoredIndegreeTwoNoCycle) {
  // Node 3 has two parents, removing the later edge fixes the tree.
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  std::vector<int> expected = {1, 3};
  EXPECT_EQ(solution.findRedundantDirectedConnection(edges), expected);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, RedundantConnectionIiTest,
    testing::ValuesIn(RedundantConnectionIiSolution().getStrategyNames()));
