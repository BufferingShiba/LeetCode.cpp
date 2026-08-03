#include "leetcode/problems/maximal-network-rank.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode::problem_1615 {

class MaximalNetworkRankTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximalNetworkRankSolution solution;
};

TEST_P(MaximalNetworkRankTest, Example1) {
  int n = 4;
  std::vector<std::vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3}};
  EXPECT_EQ(solution.maximalNetworkRank(n, roads), 4);
}

TEST_P(MaximalNetworkRankTest, Example2) {
  int n = 5;
  std::vector<std::vector<int>> roads = {
      {0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
  EXPECT_EQ(solution.maximalNetworkRank(n, roads), 5);
}

TEST_P(MaximalNetworkRankTest, Example3) {
  int n = 8;
  std::vector<std::vector<int>> roads = {
      {0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}};
  EXPECT_EQ(solution.maximalNetworkRank(n, roads), 5);
}

TEST_P(MaximalNetworkRankTest, SelfAuthoredNoRoads) {
  int n = 3;
  std::vector<std::vector<int>> roads = {};
  EXPECT_EQ(solution.maximalNetworkRank(n, roads), 0);
}

TEST_P(MaximalNetworkRankTest, SelfAuthoredSingleEdge) {
  int n = 2;
  std::vector<std::vector<int>> roads = {{0, 1}};
  // rank of cities 0 and 1: deg0 + deg1 - 1 = 1 + 1 - 1 = 1
  EXPECT_EQ(solution.maximalNetworkRank(n, roads), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MaximalNetworkRankTestSuite, MaximalNetworkRankTest,
    ::testing::ValuesIn(MaximalNetworkRankSolution().getStrategyNames()));

}  // namespace leetcode::problem_1615
