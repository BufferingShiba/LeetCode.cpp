#include "leetcode/problems/spiral-matrix-iii.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_885 {

class SpiralMatrixIiiTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SpiralMatrixIiiSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  rows = 1, cols = 4, rStart = 0, cStart = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]
TEST_P(SpiralMatrixIiiTest, OfficialExample1) {
  const std::vector<std::vector<int>> expected = {
    {0, 0},
    {0, 1},
    {0, 2},
    {0, 3}
  };
  EXPECT_EQ(expected, solution.spiralMatrixIII(1, 4, 0, 0));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  rows = 5, cols = 6, rStart = 1, cStart = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
TEST_P(SpiralMatrixIiiTest, OfficialExample2) {
  const std::vector<std::vector<int>> expected = {
    {1, 4},
    {1, 5},
    {2, 5},
    {2, 4},
    {2, 3},
    {1, 3},
    {0, 3},
    {0, 4},
    {0, 5},
    {3, 5},
    {3, 4},
    {3, 3},
    {3, 2},
    {2, 2},
    {1, 2},
    {0, 2},
    {4, 5},
    {4, 4},
    {4, 3},
    {4, 2},
    {4, 1},
    {3, 1},
    {2, 1},
    {1, 1},
    {0, 1},
    {4, 0},
    {3, 0},
    {2, 0},
    {1, 0},
    {0, 0}
  };
  EXPECT_EQ(expected, solution.spiralMatrixIII(5, 6, 1, 4));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, SpiralMatrixIiiTest,
    ::testing::ValuesIn(SpiralMatrixIiiSolution().getStrategyNames()));

}  // namespace problem_885
}  // namespace leetcode
