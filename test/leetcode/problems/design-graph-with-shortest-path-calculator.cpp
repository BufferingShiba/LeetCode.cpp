#include <gtest/gtest.h>

#include "leetcode/problems/design-graph-with-shortest-path-calculator.h"

namespace leetcode::problem_2642 {

class DesignGraphWithShortestPathCalculatorTest
    : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(DesignGraphWithShortestPathCalculatorTest, Example1) {
  std::vector<std::vector<int>> edges = {
      {0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
  Graph g(4, edges);

  EXPECT_EQ(6, g.shortestPath(3, 2));
  EXPECT_EQ(-1, g.shortestPath(0, 3));

  g.addEdge({1, 3, 4});
  EXPECT_EQ(6, g.shortestPath(0, 3));
}

TEST_P(DesignGraphWithShortestPathCalculatorTest, SelfAuthoredSingleNodeSelfPath) {
  std::vector<std::vector<int>> edges;
  Graph g(1, edges);
  EXPECT_EQ(0, g.shortestPath(0, 0));
}

TEST_P(DesignGraphWithShortestPathCalculatorTest, SelfAuthoredDirectEdgeThenNoPath) {
  std::vector<std::vector<int>> edges = {{0, 1, 7}};
  Graph g(2, edges);
  EXPECT_EQ(7, g.shortestPath(0, 1));
  EXPECT_EQ(-1, g.shortestPath(1, 0));
  g.addEdge({1, 0, 3});
  EXPECT_EQ(3, g.shortestPath(1, 0));
}

INSTANTIATE_TEST_SUITE_P(
    DesignGraphWithShortestPathCalculatorTestSuite,
    DesignGraphWithShortestPathCalculatorTest,
    ::testing::Values(0));

}  // namespace leetcode::problem_2642
