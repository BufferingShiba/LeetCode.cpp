#include "leetcode/problems/number-of-closed-islands.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1254 {

class NumberOfClosedIslandsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfClosedIslandsSolution solution;
};

TEST_P(NumberOfClosedIslandsTest, Example1) {
  std::vector<std::vector<int>> grid = {
      {1, 1, 1, 1, 1, 1, 1, 0},
      {1, 0, 0, 0, 0, 1, 1, 0},
      {1, 0, 1, 0, 1, 1, 1, 0},
      {1, 0, 0, 0, 0, 1, 0, 1},
      {1, 1, 1, 1, 1, 1, 1, 0}};
  EXPECT_EQ(2, solution.closedIsland(grid));
}

TEST_P(NumberOfClosedIslandsTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {0, 0, 1, 0, 0},
      {0, 1, 0, 1, 0},
      {0, 1, 1, 1, 0}};
  EXPECT_EQ(1, solution.closedIsland(grid));
}

TEST_P(NumberOfClosedIslandsTest, Example3) {
  std::vector<std::vector<int>> grid = {
      {1, 1, 1, 1, 1, 1, 1},
      {1, 0, 0, 0, 0, 0, 1},
      {1, 0, 1, 1, 1, 0, 1},
      {1, 0, 1, 0, 1, 0, 1},
      {1, 0, 1, 1, 1, 0, 1},
      {1, 0, 0, 0, 0, 0, 1},
      {1, 1, 1, 1, 1, 1, 1}};
  EXPECT_EQ(2, solution.closedIsland(grid));
}

TEST_P(NumberOfClosedIslandsTest, SelfAuthoredSingleCellLandNotClosed) {
  // A single 0 cell not on border but enclosed by 1s is a closed island.
  std::vector<std::vector<int>> grid = {
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1}};
  EXPECT_EQ(1, solution.closedIsland(grid));
}

TEST_P(NumberOfClosedIslandsTest, SelfAuthoredAllWater) {
  std::vector<std::vector<int>> grid = {
      {1, 1},
      {1, 1}};
  EXPECT_EQ(0, solution.closedIsland(grid));
}

TEST_P(NumberOfClosedIslandsTest, SelfAuthoredIslandTouchingBorderNotClosed) {
  std::vector<std::vector<int>> grid = {
      {0, 1},
      {0, 1}};
  EXPECT_EQ(0, solution.closedIsland(grid));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfClosedIslandsSuite, NumberOfClosedIslandsTest,
    ::testing::ValuesIn(NumberOfClosedIslandsSolution().getStrategyNames()));

}  // namespace problem_1254
}  // namespace leetcode
