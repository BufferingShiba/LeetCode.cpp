#include <gtest/gtest.h>
#include "leetcode/problems/find-center-of-star-graph.h"
#include <string>
#include <vector>

using leetcode::problem_1791::FindCenterOfStarGraphSolution;

class FindCenterOfStarGraphTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  FindCenterOfStarGraphSolution solution;
};

TEST_P(FindCenterOfStarGraphTest, Example1) {
  std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
  EXPECT_EQ(2, solution.findCenter(edges));
}

TEST_P(FindCenterOfStarGraphTest, Example2) {
  std::vector<std::vector<int>> edges = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};
  EXPECT_EQ(1, solution.findCenter(edges));
}

TEST_P(FindCenterOfStarGraphTest, SelfAuthoredCenterIsSecondInFirstEdge) {
  std::vector<std::vector<int>> edges = {{2, 5}, {3, 5}, {5, 4}, {1, 5}};
  EXPECT_EQ(5, solution.findCenter(edges));
}

INSTANTIATE_TEST_SUITE_P(
    FindCenterOfStarGraphTest, FindCenterOfStarGraphTest,
    ::testing::ValuesIn(FindCenterOfStarGraphSolution().getStrategyNames()));
