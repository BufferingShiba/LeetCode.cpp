#include <gtest/gtest.h>

#include "leetcode/problems/minimum-degree-of-a-connected-trio-in-a-graph.h"

namespace leetcode::problem_1761 {

class MinimumDegreeOfAConnectedTrioInAGraphTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumDegreeOfAConnectedTrioInAGraphSolution solution;
};

TEST_P(MinimumDegreeOfAConnectedTrioInAGraphTest, Example1) {
  int n = 6;
  std::vector<std::vector<int>> edges = {
      {1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6}};
  EXPECT_EQ(3, solution.minTrioDegree(n, edges));
}

TEST_P(MinimumDegreeOfAConnectedTrioInAGraphTest, Example2) {
  int n = 7;
  std::vector<std::vector<int>> edges = {
      {1, 3}, {4, 1}, {4, 3}, {2, 5}, {5, 6}, {6, 7}, {7, 5}, {2, 6}};
  EXPECT_EQ(0, solution.minTrioDegree(n, edges));
}

TEST_P(MinimumDegreeOfAConnectedTrioInAGraphTest, NoTrio) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}};
  EXPECT_EQ(-1, solution.minTrioDegree(n, edges));
}

TEST_P(MinimumDegreeOfAConnectedTrioInAGraphTest, CompleteTriangleOnly) {
  int n = 3;
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {3, 1}};
  EXPECT_EQ(0, solution.minTrioDegree(n, edges));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumDegreeOfAConnectedTrioInAGraphTestInstance,
    MinimumDegreeOfAConnectedTrioInAGraphTest,
    ::testing::ValuesIn(
        MinimumDegreeOfAConnectedTrioInAGraphSolution().getStrategyNames()));

}  // namespace leetcode::problem_1761
