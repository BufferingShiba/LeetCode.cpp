#include "leetcode/problems/count-sub-islands.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1905 {

class CountSubIslandsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountSubIslandsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
TEST_P(CountSubIslandsTest, OfficialExample1) {
  vector<vector<int>> grid1 = {{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}};
  vector<vector<int>> grid2 = {{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};
  int expected = 3;
  int result = solution.countSubIslands(grid1, grid2);
  EXPECT_EQ(expected, result);
}

// ===== Official Example 2 (from LeetCode) =====
TEST_P(CountSubIslandsTest, OfficialExample2) {
  vector<vector<int>> grid1 = {{1, 0, 1, 0, 1}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {1, 0, 1, 0, 1}};
  vector<vector<int>> grid2 = {{0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {0, 1, 0, 1, 0}, {0, 1, 0, 1, 0}, {1, 0, 0, 0, 1}};
  int expected = 2;
  int result = solution.countSubIslands(grid1, grid2);
  EXPECT_EQ(expected, result);
}

// ===== Equivalent grids: every island in grid2 is a sub-island =====
// Only two islands: {(0,0),(0,1),(1,1),(1,2),(2,2)} and {(2,0)}.
TEST_P(CountSubIslandsTest, IdenticalGrids) {
  vector<vector<int>> grid1 = {{1, 1, 0}, {0, 1, 1}, {1, 0, 1}};
  vector<vector<int>> grid2 = grid1;
  int expected = 2;
  int result = solution.countSubIslands(grid1, grid2);
  EXPECT_EQ(expected, result);
}

// ===== No land in grid2 =====
TEST_P(CountSubIslandsTest, EmptyGrid2) {
  vector<vector<int>> grid1 = {{1, 1, 1}, {1, 1, 1}};
  vector<vector<int>> grid2 = {{0, 0, 0}, {0, 0, 0}};
  int expected = 0;
  int result = solution.countSubIslands(grid1, grid2);
  EXPECT_EQ(expected, result);
}

// A maximal connected island exercises traversal depth without relying on
// recursive call-stack capacity.
TEST_P(CountSubIslandsTest, LargeConnectedGrid) {
  constexpr int kSize = 500;
  vector<vector<int>> grid1(kSize, vector<int>(kSize, 1));
  vector<vector<int>> grid2 = grid1;
  EXPECT_EQ(1, solution.countSubIslands(grid1, grid2));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, CountSubIslandsTest,
    ::testing::ValuesIn(CountSubIslandsSolution().getStrategyNames()));

}  // namespace problem_1905
}  // namespace leetcode
