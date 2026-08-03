#include "leetcode/problems/maximum-non-negative-product-in-a-matrix.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1594 {

class MaximumNonNegativeProductInAMatrixTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNonNegativeProductInAMatrixSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
// Output: -1
TEST_P(MaximumNonNegativeProductInAMatrixTest, OfficialExample1) {
  vector<vector<int>> grid = {{-1, -2, -3}, {-2, -3, -3}, {-3, -3, -2}};
  EXPECT_EQ(-1, solution.maxProductPath(grid));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
// Output: 8
TEST_P(MaximumNonNegativeProductInAMatrixTest, OfficialExample2) {
  vector<vector<int>> grid = {{1, -2, 1}, {1, -2, 1}, {3, -4, 1}};
  EXPECT_EQ(8, solution.maxProductPath(grid));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  grid = [[1,3],[0,-4]]
// Output: 0
TEST_P(MaximumNonNegativeProductInAMatrixTest, OfficialExample3) {
  vector<vector<int>> grid = {{1, 3}, {0, -4}};
  EXPECT_EQ(0, solution.maxProductPath(grid));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumNonNegativeProductInAMatrixTest,
    ::testing::ValuesIn(MaximumNonNegativeProductInAMatrixSolution().getStrategyNames()));

}  // namespace problem_1594
}  // namespace leetcode
