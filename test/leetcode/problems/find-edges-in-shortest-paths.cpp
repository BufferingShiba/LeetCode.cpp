#include <gtest/gtest.h>

#include "leetcode/problems/find-edges-in-shortest-paths.h"

using namespace leetcode::problem_3123;

class FindEdgesInShortestPathsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FindEdgesInShortestPathsSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindEdgesInShortestPathsTest, Example1) {
  int n = 6;
  std::vector<std::vector<int>> edges = {{0, 1, 4}, {0, 2, 1}, {1, 3, 2},
                                         {1, 4, 3}, {1, 5, 1}, {2, 3, 1},
                                         {3, 5, 3}, {4, 5, 2}};
  std::vector<bool> expected = {true, true, true, false,
                                true, true, true, false};
  EXPECT_EQ(solution.findAnswer(n, edges), expected);
}

TEST_P(FindEdgesInShortestPathsTest, Example2) {
  int n = 4;
  std::vector<std::vector<int>> edges = {
      {2, 0, 1}, {0, 1, 1}, {0, 3, 4}, {3, 2, 2}};
  std::vector<bool> expected = {true, false, false, true};
  EXPECT_EQ(solution.findAnswer(n, edges), expected);
}

TEST_P(FindEdgesInShortestPathsTest, SelfAuthoredDisconnectedGraph) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 5}};
  std::vector<bool> expected = {false};
  EXPECT_EQ(solution.findAnswer(n, edges), expected);
}

TEST_P(FindEdgesInShortestPathsTest, SelfAuthoredSingleEdge) {
  int n = 2;
  std::vector<std::vector<int>> edges = {{0, 1, 10}};
  std::vector<bool> expected = {true};
  EXPECT_EQ(solution.findAnswer(n, edges), expected);
}

TEST_P(FindEdgesInShortestPathsTest, SelfAuthoredTwoParallelPaths) {
  // 0 --1-- 1
  // 0 --1-- 2
  // 1 --1-- 2
  // Both edges from 0 to {1,2} and the edge 1-2: shortest path 0->1->2 or
  // 0->2->1 are both length 2, but only 0->1 and 0->2 are on some shortest
  // path to node 2? Let's compute: D(0->2) = 1 via direct edge. So only direct
  // edge 0-2 is on shortest path.
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1, 1}, {0, 2, 1}, {1, 2, 1}};
  // Shortest 0->2: direct 0->2 length 1. Edge 0-2 only.
  std::vector<bool> expected = {false, true, false};
  EXPECT_EQ(solution.findAnswer(n, edges), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, FindEdgesInShortestPathsTest,
    ::testing::ValuesIn(FindEdgesInShortestPathsSolution().getStrategyNames()));
