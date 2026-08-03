#include "leetcode/problems/find-the-safest-path-in-a-grid.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2812 {

class FindTheSafestPathInAGridTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheSafestPathInAGridSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  grid = [[1,0,0],[0,0,0],[0,0,1]]
// Output: 0
TEST_P(FindTheSafestPathInAGridTest, OfficialExample1) {
  vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,1}};
  EXPECT_EQ(0, solution.maximumSafenessFactor(grid));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  grid = [[0,0,1],[0,0,0],[0,0,0]]
// Output: 2
TEST_P(FindTheSafestPathInAGridTest, OfficialExample2) {
  vector<vector<int>> grid = {{0,0,1},{0,0,0},{0,0,0}};
  EXPECT_EQ(2, solution.maximumSafenessFactor(grid));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
// Output: 2
TEST_P(FindTheSafestPathInAGridTest, OfficialExample3) {
  vector<vector<int>> grid = {{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};
  EXPECT_EQ(2, solution.maximumSafenessFactor(grid));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, FindTheSafestPathInAGridTest,
    ::testing::ValuesIn(FindTheSafestPathInAGridSolution().getStrategyNames()));

}  // namespace problem_2812
}  // namespace leetcode
