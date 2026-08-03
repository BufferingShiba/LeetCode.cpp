#include "leetcode/problems/01-matrix.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_542 {

class Problem01MatrixTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  Problem01MatrixSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
TEST_P(Problem01MatrixTest, OfficialExample1) {
  std::vector<std::vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  std::vector<std::vector<int>> expected = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  EXPECT_EQ(expected, solution.updateMatrix(mat));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
TEST_P(Problem01MatrixTest, OfficialExample2) {
  std::vector<std::vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  std::vector<std::vector<int>> expected = {{0, 0, 0}, {0, 1, 0}, {1, 2, 1}};
  EXPECT_EQ(expected, solution.updateMatrix(mat));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, Problem01MatrixTest,
    ::testing::ValuesIn(Problem01MatrixSolution().getStrategyNames()));

}  // namespace problem_542
}  // namespace leetcode
