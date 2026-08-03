#include "leetcode/problems/check-knight-tour-configuration.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2596 {

class CheckKnightTourConfigurationTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckKnightTourConfigurationSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
// Output: true
TEST_P(CheckKnightTourConfigurationTest, OfficialExample1) {
  vector<vector<int>> grid = {{0, 11, 16, 5, 20}, {17, 4, 19, 10, 15}, {12, 1, 8, 21, 6}, {3, 18, 23, 14, 9}, {24, 13, 2, 7, 22}};
  bool expected = true;
  bool result = solution.checkValidGrid(grid);
  EXPECT_EQ(expected, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  grid = [[0,3,6],[5,8,1],[2,7,4]]
// Output: false
TEST_P(CheckKnightTourConfigurationTest, OfficialExample2) {
  vector<vector<int>> grid = {{0, 3, 6}, {5, 8, 1}, {2, 7, 4}};
  bool expected = false;
  bool result = solution.checkValidGrid(grid);
  EXPECT_EQ(expected, result);
}

// ===== Extra: start position not top-left =====
TEST_P(CheckKnightTourConfigurationTest, InvalidStart) {
  vector<vector<int>> grid = {{3, 0, 6}, {5, 8, 1}, {2, 7, 4}};
  bool expected = false;
  bool result = solution.checkValidGrid(grid);
  EXPECT_EQ(expected, result);
}

// ===== Extra: a trivial valid 3x3 config =====
// Valid Knight tour for 3x3: 0 at (0,0), then 1 at (2,1), 2 at (0,2), 3 at (1,0), 4 at (2,2), 5 at (0,1), 6 at (1,2), 7 at (2,0), 8 at (1,1)
// Check moves: (0,0)->(2,1)=(2,1) v; (2,1)->(0,2)=(-2,1) v; (0,2)->(1,0)=(1,-2) v;
// (1,0)->(2,2)=(1,2) v; (2,2)->(0,1)=(-2,-1) v; (0,1)->(1,2)=(1,1) IX -> invalid.

INSTANTIATE_TEST_SUITE_P(
    LeetCode, CheckKnightTourConfigurationTest,
    ::testing::ValuesIn(CheckKnightTourConfigurationSolution().getStrategyNames()));

}  // namespace problem_2596
}  // namespace leetcode
