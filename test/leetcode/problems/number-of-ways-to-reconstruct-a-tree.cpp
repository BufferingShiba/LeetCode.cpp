#include <gtest/gtest.h>

#include "leetcode/problems/number-of-ways-to-reconstruct-a-tree.h"

using namespace leetcode::problem_1719;

class NumberOfWaysToReconstructATreeTest
    : public testing::TestWithParam<std::string> {
 protected:
  NumberOfWaysToReconstructATreeSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(NumberOfWaysToReconstructATreeTest, Example1) {
  std::vector<std::vector<int>> pairs = {{1, 2}, {2, 3}};
  EXPECT_EQ(solution.checkWays(pairs), 1);
}

TEST_P(NumberOfWaysToReconstructATreeTest, Example2) {
  std::vector<std::vector<int>> pairs = {{1, 2}, {2, 3}, {1, 3}};
  EXPECT_EQ(solution.checkWays(pairs), 2);
}

TEST_P(NumberOfWaysToReconstructATreeTest, Example3) {
  std::vector<std::vector<int>> pairs = {{1, 2}, {2, 3}, {2, 4}, {1, 5}};
  EXPECT_EQ(solution.checkWays(pairs), 0);
}

TEST_P(NumberOfWaysToReconstructATreeTest, SelfAuthoredSingleChain) {
  // Complete graph on 4 nodes: all C(4,2)=6 pairs exist.
  // Any permutation forms a valid rooted chain → multiple ways → return 2.
  std::vector<std::vector<int>> pairs = {
      {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
  EXPECT_EQ(solution.checkWays(pairs), 2);
}

TEST_P(NumberOfWaysToReconstructATreeTest, SelfAuthoredStarTree) {
  // Root 1 with children 2,3,4: only root-child pairs exist.
  std::vector<std::vector<int>> pairs = {{1, 2}, {1, 3}, {1, 4}};
  EXPECT_EQ(solution.checkWays(pairs), 1);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfWaysToReconstructATree,
    NumberOfWaysToReconstructATreeTest,
    testing::ValuesIn(
        NumberOfWaysToReconstructATreeSolution().getStrategyNames()));
