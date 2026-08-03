#include <gtest/gtest.h>

#include "leetcode/problems/count-number-of-possible-root-nodes.h"

using namespace leetcode::problem_2581;

class CountNumberOfPossibleRootNodesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountNumberOfPossibleRootNodesSolution solution;
};

TEST_P(CountNumberOfPossibleRootNodesTest, Example1) {
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {4, 2}};
  std::vector<std::vector<int>> guesses = {{1, 3}, {0, 1}, {1, 0}, {2, 4}};
  int k = 3;
  EXPECT_EQ(solution.rootCount(edges, guesses, k), 3);
}

TEST_P(CountNumberOfPossibleRootNodesTest, Example2) {
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
  std::vector<std::vector<int>> guesses = {{1, 0}, {3, 4}, {2, 1}, {3, 2}};
  int k = 1;
  EXPECT_EQ(solution.rootCount(edges, guesses, k), 5);
}

INSTANTIATE_TEST_SUITE_P(Strategies, CountNumberOfPossibleRootNodesTest,
                         testing::ValuesIn(CountNumberOfPossibleRootNodesSolution().getStrategyNames()));
