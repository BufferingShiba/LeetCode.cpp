#include <gtest/gtest.h>

#include "leetcode/problems/minimum-threshold-path-with-limited-heavy-edges.h"

using namespace leetcode::problem_3924;

class MinimumThresholdPathWithLimitedHeavyEdgesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MinimumThresholdPathWithLimitedHeavyEdgesSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MinimumThresholdPathWithLimitedHeavyEdgesTest, Example1) {
  int n = 6;
  std::vector<std::vector<int>> edges = {
      {0, 1, 5}, {1, 2, 3}, {3, 4, 4}, {4, 5, 1}, {1, 4, 2}};
  int source = 0, target = 3, k = 1;
  EXPECT_EQ(solution.minimumThreshold(n, edges, source, target, k), 4);
}

TEST_P(MinimumThresholdPathWithLimitedHeavyEdgesTest, Example2) {
  int n = 6;
  std::vector<std::vector<int>> edges = {
      {0, 1, 3}, {1, 2, 4}, {3, 4, 5}, {4, 5, 6}};
  int source = 0, target = 4, k = 1;
  EXPECT_EQ(solution.minimumThreshold(n, edges, source, target, k), -1);
}

TEST_P(MinimumThresholdPathWithLimitedHeavyEdgesTest, Example3) {
  int n = 4;
  std::vector<std::vector<int>> edges = {
      {0, 1, 2}, {1, 2, 2}, {2, 3, 2}, {3, 0, 2}};
  int source = 0, target = 0, k = 0;
  EXPECT_EQ(solution.minimumThreshold(n, edges, source, target, k), 0);
}

TEST_P(MinimumThresholdPathWithLimitedHeavyEdgesTest, SelfAuthoredSingleEdge) {
  int n = 2;
  std::vector<std::vector<int>> edges = {{0, 1, 10}};
  // source=0, target=1, k=0: need all edges light => threshold >= 10
  EXPECT_EQ(solution.minimumThreshold(n, edges, 0, 1, 0), 10);
  // k=1: even threshold=0 works (the single edge is heavy but we can take 1)
  EXPECT_EQ(solution.minimumThreshold(n, edges, 0, 1, 1), 0);
}

TEST_P(MinimumThresholdPathWithLimitedHeavyEdgesTest,
       SelfAuthoredAllHeavyPath) {
  int n = 4;
  std::vector<std::vector<int>> edges = {
      {0, 1, 100}, {1, 2, 100}, {2, 3, 100}};
  // Path length 3, k=2 => not enough, need all 3 heavy edges => unreachable
  // But if threshold >= 100, all edges become light, so path uses 0 heavy edges
  EXPECT_EQ(solution.minimumThreshold(n, edges, 0, 3, 0), 100);
  // k=3: all heavy edges allowed, threshold can be 0
  EXPECT_EQ(solution.minimumThreshold(n, edges, 0, 3, 3), 0);
  // k=2: not enough, need threshold to make at least one edge light
  // If threshold=100, all edges become light (0 heavy). So answer is 100.
  EXPECT_EQ(solution.minimumThreshold(n, edges, 0, 3, 2), 100);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MinimumThresholdPathWithLimitedHeavyEdgesTest,
    ::testing::ValuesIn(
        MinimumThresholdPathWithLimitedHeavyEdgesSolution().getStrategyNames()));
