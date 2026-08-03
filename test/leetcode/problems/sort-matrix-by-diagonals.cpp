#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/sort-matrix-by-diagonals.h"

namespace leetcode {
namespace problem_3446 {

class SortMatrixByDiagonalsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SortMatrixByDiagonalsSolution solution;
};

TEST_P(SortMatrixByDiagonalsTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
  std::vector<std::vector<int>> expected = {{8, 2, 3}, {9, 6, 7}, {4, 5, 1}};
  EXPECT_EQ(solution.sortMatrix(grid), expected);
}

TEST_P(SortMatrixByDiagonalsTest, Example2) {
  std::vector<std::vector<int>> grid = {{0, 1}, {1, 2}};
  std::vector<std::vector<int>> expected = {{2, 1}, {1, 0}};
  EXPECT_EQ(solution.sortMatrix(grid), expected);
}

TEST_P(SortMatrixByDiagonalsTest, Example3) {
  std::vector<std::vector<int>> grid = {{1}};
  std::vector<std::vector<int>> expected = {{1}};
  EXPECT_EQ(solution.sortMatrix(grid), expected);
}

TEST_P(SortMatrixByDiagonalsTest, SelfAuthoredSingleDiagonalCase) {
  std::vector<std::vector<int>> grid = {{4, 1}, {3, 2}};
  // Main diagonal [4,2] -> non-increasing [4,2] (already).
  // Bottom-left diagonal [3] unchanged. Top-right [1] unchanged.
  std::vector<std::vector<int>> expected = {{4, 1}, {3, 2}};
  EXPECT_EQ(solution.sortMatrix(grid), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SortMatrixByDiagonalsParam, SortMatrixByDiagonalsTest,
    ::testing::ValuesIn(SortMatrixByDiagonalsSolution().getStrategyNames()));

}  // namespace problem_3446
}  // namespace leetcode
