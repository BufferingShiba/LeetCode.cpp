#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/minimum-cost-to-cut-a-stick.h"

using leetcode::problem_1547::MinimumCostToCutAStickSolution;

class MinimumCostToCutAStickTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCostToCutAStickSolution solution;
};

TEST_P(MinimumCostToCutAStickTest, Example1) {
  int n = 7;
  std::vector<int> cuts = {1, 3, 4, 5};
  EXPECT_EQ(solution.minCost(n, cuts), 16);
}

TEST_P(MinimumCostToCutAStickTest, Example2) {
  int n = 9;
  std::vector<int> cuts = {5, 6, 1, 4, 2};
  EXPECT_EQ(solution.minCost(n, cuts), 22);
}

TEST_P(MinimumCostToCutAStickTest, SelfAuthoredSingleCut) {
  int n = 5;
  std::vector<int> cuts = {2};
  EXPECT_EQ(solution.minCost(n, cuts), 5);
}

TEST_P(MinimumCostToCutAStickTest, SelfAuthoredTwoCuts) {
  int n = 10;
  std::vector<int> cuts = {2, 7};
  // Cut at 7 first (cost 10), then at 2 (cost 7) => 17
  EXPECT_EQ(solution.minCost(n, cuts), 17);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumCostToCutAStickTest,
    testing::ValuesIn(MinimumCostToCutAStickSolution().getStrategyNames()));
