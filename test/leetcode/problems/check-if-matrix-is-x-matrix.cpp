#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-matrix-is-x-matrix.h"

namespace leetcode {
namespace problem_2319 {
namespace test {

class CheckIfMatrixIsXMatrixTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckIfMatrixIsXMatrixSolution solution;
};

TEST_P(CheckIfMatrixIsXMatrixTest, Example1) {
  std::vector<std::vector<int>> grid = {
      {2, 0, 0, 1}, {0, 3, 1, 0}, {0, 5, 2, 0}, {4, 0, 0, 2}};
  EXPECT_TRUE(solution.checkXMatrix(grid));
}

TEST_P(CheckIfMatrixIsXMatrixTest, Example2) {
  std::vector<std::vector<int>> grid = {{5, 7, 0}, {0, 3, 1}, {0, 5, 0}};
  EXPECT_FALSE(solution.checkXMatrix(grid));
}

TEST_P(CheckIfMatrixIsXMatrixTest, SelfAuthoredFullXMatrix) {
  std::vector<std::vector<int>> grid = {
      {1, 0, 0, 0, 2}, {0, 3, 0, 4, 0}, {0, 0, 5, 0, 0},
      {0, 6, 0, 7, 0}, {8, 0, 0, 0, 9}};
  EXPECT_TRUE(solution.checkXMatrix(grid));
}

TEST_P(CheckIfMatrixIsXMatrixTest, SelfAuthoredZeroOnMainDiagonal) {
  std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  EXPECT_FALSE(solution.checkXMatrix(grid));
}

TEST_P(CheckIfMatrixIsXMatrixTest, SelfAuthoredZeroOnAntiDiagonal) {
  std::vector<std::vector<int>> grid = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  EXPECT_FALSE(solution.checkXMatrix(grid));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfMatrixIsXMatrixTestCases, CheckIfMatrixIsXMatrixTest,
    ::testing::ValuesIn(CheckIfMatrixIsXMatrixSolution().getStrategyNames()));

}  // namespace test
}  // namespace problem_2319
}  // namespace leetcode
