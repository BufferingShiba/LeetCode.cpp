#include <gtest/gtest.h>

#include "leetcode/problems/minimum-path-cost-in-a-grid.h"

namespace leetcode::problem_2304 {

class MinimumPathCostInAGridTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumPathCostInAGridSolution solution;
};

TEST_P(MinimumPathCostInAGridTest, Example1) {
  std::vector<std::vector<int>> grid = {{5, 3}, {4, 0}, {2, 1}};
  std::vector<std::vector<int>> moveCost = {
      {9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}};
  EXPECT_EQ(solution.minPathCost(grid, moveCost), 17);
}

TEST_P(MinimumPathCostInAGridTest, Example2) {
  std::vector<std::vector<int>> grid = {{5, 1, 2}, {4, 0, 3}};
  std::vector<std::vector<int>> moveCost = {
      {12, 10, 15}, {20, 23, 8}, {21, 7, 1},
      {8, 1, 13},   {9, 10, 25}, {5, 3, 2}};
  EXPECT_EQ(solution.minPathCost(grid, moveCost), 6);
}

INSTANTIATE_TEST_SUITE_P(Strategies, MinimumPathCostInAGridTest,
                         testing::ValuesIn(MinimumPathCostInAGridSolution().getStrategyNames()));

}  // namespace leetcode::problem_2304
