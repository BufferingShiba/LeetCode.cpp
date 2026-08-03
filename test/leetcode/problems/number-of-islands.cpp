
#include "leetcode/problems/number-of-islands.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_200 {

class NumberOfIslandsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfIslandsSolution solution;
};

TEST_P(NumberOfIslandsTest, Example1) {
  vector<vector<char>> grid = {
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'}};
  EXPECT_EQ(1, solution.numIslands(grid));
}

TEST_P(NumberOfIslandsTest, Example2) {
  vector<vector<char>> grid = {
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'}};
  EXPECT_EQ(3, solution.numIslands(grid));
}

TEST_P(NumberOfIslandsTest, SelfAuthoredAllWater) {
  vector<vector<char>> grid = {
      {'0', '0', '0'},
      {'0', '0', '0'}};
  EXPECT_EQ(0, solution.numIslands(grid));
}

TEST_P(NumberOfIslandsTest, SelfAuthoredSingleCellLand) {
  vector<vector<char>> grid = {{'1'}};
  EXPECT_EQ(1, solution.numIslands(grid));
}

TEST_P(NumberOfIslandsTest, SelfAuthoredAllLand) {
  vector<vector<char>> grid = {
      {'1', '1'},
      {'1', '1'}};
  EXPECT_EQ(1, solution.numIslands(grid));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, NumberOfIslandsTest,
    ::testing::ValuesIn(NumberOfIslandsSolution().getStrategyNames()));

}  // namespace problem_200
}  // namespace leetcode
