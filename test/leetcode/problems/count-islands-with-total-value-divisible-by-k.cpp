#include "leetcode/problems/count-islands-with-total-value-divisible-by-k.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3619 {

class CountIslandsWithTotalValueDivisibleByKTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountIslandsWithTotalValueDivisibleByKSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
// Output: 2
TEST_P(CountIslandsWithTotalValueDivisibleByKTest, OfficialExample1) {
  vector<vector<int>> grid = {{0,2,1,0,0},{0,5,0,0,5},{0,0,1,0,0},{0,1,4,7,0},{0,2,0,0,8}};
  int k = 5;
  EXPECT_EQ(2, solution.countIslands(grid, k));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3
// Output: 6
TEST_P(CountIslandsWithTotalValueDivisibleByKTest, OfficialExample2) {
  vector<vector<int>> grid = {{3,0,3,0},{0,3,0,3},{3,0,3,0}};
  int k = 3;
  EXPECT_EQ(6, solution.countIslands(grid, k));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, CountIslandsWithTotalValueDivisibleByKTest,
    ::testing::ValuesIn(CountIslandsWithTotalValueDivisibleByKSolution().getStrategyNames()));

}  // namespace problem_3619
}  // namespace leetcode
