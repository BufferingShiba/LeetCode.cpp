#include <gtest/gtest.h>

#include "leetcode/problems/minimize-maximum-component-cost.h"

#include <vector>

namespace leetcode::problem_3613 {

class MinimizeMaximumComponentCostTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  MinimizeMaximumComponentCostSolution solution_;
};

TEST_P(MinimizeMaximumComponentCostTest, Example1) {
  int n = 5;
  std::vector<std::vector<int>> edges = {{0, 1, 4}, {1, 2, 3}, {1, 3, 2}, {3, 4, 6}};
  int k = 2;
  EXPECT_EQ(4, solution_.minCost(n, edges, k));
}

TEST_P(MinimizeMaximumComponentCostTest, Example2) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 1, 5}, {1, 2, 5}, {2, 3, 5}};
  int k = 1;
  EXPECT_EQ(5, solution_.minCost(n, edges, k));
}

TEST_P(MinimizeMaximumComponentCostTest, SelfAuthoredSingletonGraph) {
  int n = 1;
  std::vector<std::vector<int>> edges;
  int k = 1;
  EXPECT_EQ(0, solution_.minCost(n, edges, k));
}

TEST_P(MinimizeMaximumComponentCostTest, SelfAuthoredEachNodeItsOwnComponent) {
  int n = 4;
  std::vector<std::vector<int>> edges = {{0, 1, 3}, {1, 2, 7}, {2, 3, 9}};
  int k = 4;
  // k >= n: can remove all edges, every component cost 0.
  EXPECT_EQ(0, solution_.minCost(n, edges, k));
}

INSTANTIATE_TEST_SUITE_P(
    MinimizeMaximumComponentCostTestSuite,
    MinimizeMaximumComponentCostTest,
    ::testing::ValuesIn(MinimizeMaximumComponentCostSolution().getStrategyNames()));

}  // namespace leetcode::problem_3613
