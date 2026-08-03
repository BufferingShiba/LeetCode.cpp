#include <gtest/gtest.h>

#include "leetcode/problems/island-perimeter.h"

namespace leetcode::problem_463 {

class IslandPerimeterTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  IslandPerimeterSolution solution;
};

TEST_P(IslandPerimeterTest, Example1) {
  std::vector<std::vector<int>> grid = {
      {0, 1, 0, 0},
      {1, 1, 1, 0},
      {0, 1, 0, 0},
      {1, 1, 0, 0}};
  EXPECT_EQ(solution.islandPerimeter(grid), 16);
}

TEST_P(IslandPerimeterTest, Example2) {
  std::vector<std::vector<int>> grid = {{1}};
  EXPECT_EQ(solution.islandPerimeter(grid), 4);
}

TEST_P(IslandPerimeterTest, Example3) {
  std::vector<std::vector<int>> grid = {{1, 0}};
  EXPECT_EQ(solution.islandPerimeter(grid), 4);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, IslandPerimeterTest,
    ::testing::ValuesIn(IslandPerimeterSolution().getStrategyNames()));

}  // namespace leetcode::problem_463
