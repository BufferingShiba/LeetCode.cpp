#include <gtest/gtest.h>
#include <vector>

#include "leetcode/problems/minimum-xor-path-in-a-grid.h"

namespace leetcode::problem_3882 {

class MinimumXorPathInAGridTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumXorPathInAGridSolution solution;
};

TEST_P(MinimumXorPathInAGridTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}};
  EXPECT_EQ(solution.minCost(grid), 6);
}

TEST_P(MinimumXorPathInAGridTest, Example2) {
  std::vector<std::vector<int>> grid = {{6, 7}, {5, 8}};
  EXPECT_EQ(solution.minCost(grid), 9);
}

TEST_P(MinimumXorPathInAGridTest, Example3) {
  std::vector<std::vector<int>> grid = {{2, 7, 5}};
  EXPECT_EQ(solution.minCost(grid), 0);
}

TEST_P(MinimumXorPathInAGridTest, SelfAuthoredSingleCell) {
  std::vector<std::vector<int>> grid = {{42}};
  EXPECT_EQ(solution.minCost(grid), 42);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumXorPathInAGridStrategies,
    MinimumXorPathInAGridTest,
    ::testing::ValuesIn(MinimumXorPathInAGridSolution().getStrategyNames()));

}  // namespace leetcode::problem_3882
