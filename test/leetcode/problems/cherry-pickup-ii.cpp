#include <gtest/gtest.h>

#include "leetcode/problems/cherry-pickup-ii.h"

using leetcode::problem_1463::CherryPickupIiSolution;

class CherryPickupIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CherryPickupIiSolution solution;
};

TEST_P(CherryPickupIiTest, Example1) {
  std::vector<std::vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
  EXPECT_EQ(24, solution.cherryPickup(grid));
}

TEST_P(CherryPickupIiTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {1, 0, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 3, 0}, {2, 0, 9, 0, 0, 0, 0},
      {0, 3, 0, 5, 4, 0, 0}, {1, 0, 2, 3, 0, 0, 6}};
  EXPECT_EQ(28, solution.cherryPickup(grid));
}

TEST_P(CherryPickupIiTest, TwoRows) {
  // rows=2, cols=4. Robot1 starts (0,0), robot2 starts (0,3).
  // Row0 collects 1+4=5. Row1 best: robot1->col1(6), robot2->col3(8) => 14.
  // Total 5+14=19.
  std::vector<std::vector<int>> grid = {{1, 2, 3, 4}, {5, 6, 7, 8}};
  EXPECT_EQ(19, solution.cherryPickup(grid));
}

TEST_P(CherryPickupIiTest, SameCellDedup) {
  // rows=2, cols=3. Row0: robot1 at col0(1), robot2 at col2(3) => 4.
  // Row1: best pair is robot1->col0(1), robot2->col1(9) = 10. Total=14.
  std::vector<std::vector<int>> grid = {{1, 1, 3}, {1, 9, 1}};
  EXPECT_EQ(14, solution.cherryPickup(grid));
}

INSTANTIATE_TEST_SUITE_P(
    CherryPickupIiStrategies, CherryPickupIiTest,
    ::testing::ValuesIn(CherryPickupIiSolution().getStrategyNames()));
