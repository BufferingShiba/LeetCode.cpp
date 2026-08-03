#include <gtest/gtest.h>

#include "leetcode/problems/minimum-weighted-subgraph-with-the-required-paths-ii.h"

using namespace leetcode::problem_3553;

class MinimumWeightedSubgraphWithTheRequiredPathsIiTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumWeightedSubgraphWithTheRequiredPathsIiSolution solution_;
};

TEST_P(MinimumWeightedSubgraphWithTheRequiredPathsIiTest, Example1) {
  std::vector<std::vector<int>> edges = {
      {0, 1, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 4}, {2, 5, 6}};
  std::vector<std::vector<int>> queries = {{2, 3, 4}, {0, 2, 5}};
  std::vector<int> expected = {12, 11};
  EXPECT_EQ(solution_.minimumWeight(edges, queries), expected);
}

TEST_P(MinimumWeightedSubgraphWithTheRequiredPathsIiTest, Example2) {
  std::vector<std::vector<int>> edges = {{1, 0, 8}, {0, 2, 7}};
  std::vector<std::vector<int>> queries = {{0, 1, 2}};
  std::vector<int> expected = {15};
  EXPECT_EQ(solution_.minimumWeight(edges, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MinimumWeightedSubgraphWithTheRequiredPathsIiTest,
    testing::ValuesIn(
        MinimumWeightedSubgraphWithTheRequiredPathsIiSolution()
            .getStrategyNames()));
