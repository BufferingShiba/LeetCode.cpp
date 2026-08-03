#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/cells-with-odd-values-in-a-matrix.h"

namespace leetcode {
namespace problem_1252 {
namespace {

class CellsWithOddValuesInAMatrixTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CellsWithOddValuesInAMatrixSolution solution;
};

TEST_P(CellsWithOddValuesInAMatrixTest, Example1) {
  int m = 2, n = 3;
  std::vector<std::vector<int>> indices = {{0, 1}, {1, 1}};
  EXPECT_EQ(6, solution.oddCells(m, n, indices));
}

TEST_P(CellsWithOddValuesInAMatrixTest, Example2) {
  int m = 2, n = 2;
  std::vector<std::vector<int>> indices = {{1, 1}, {0, 0}};
  EXPECT_EQ(0, solution.oddCells(m, n, indices));
}

TEST_P(CellsWithOddValuesInAMatrixTest, SelfAuthoredSingleOperation) {
  int m = 3, n = 3;
  std::vector<std::vector<int>> indices = {{1, 1}};
  // row1+col1 -> center 2, cross cells 1 => 4 cells odd
  EXPECT_EQ(4, solution.oddCells(m, n, indices));
}

TEST_P(CellsWithOddValuesInAMatrixTest, SelfAuthoredSingleRow) {
  int m = 1, n = 5;
  std::vector<std::vector<int>> indices = {{0, 2}};
  // row0 + col2: cell(0,2)=2 odd? no; others=1 odd => 4 odd
  EXPECT_EQ(4, solution.oddCells(m, n, indices));
}

INSTANTIATE_TEST_SUITE_P(
    CellsWithOddValuesInAMatrixTestSuite, CellsWithOddValuesInAMatrixTest,
    ::testing::ValuesIn(
        CellsWithOddValuesInAMatrixSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1252
}  // namespace leetcode
