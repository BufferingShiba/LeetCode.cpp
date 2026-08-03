#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-square-submatrices-with-all-ones.h"

namespace leetcode {
namespace problem_1277 {

using CountSquareSubmatricesWithAllOnesTest =
    ::testing::TestWithParam<std::string>;

INSTANTIATE_TEST_SUITE_P(
    CountSquareSubmatricesWithAllOnes, CountSquareSubmatricesWithAllOnesTest,
    ::testing::ValuesIn(CountSquareSubmatricesWithAllOnesSolution().getStrategyNames()));

TEST_P(CountSquareSubmatricesWithAllOnesTest, Example1) {
  CountSquareSubmatricesWithAllOnesSolution solution;
  solution.setStrategy(GetParam());
  std::vector<std::vector<int>> matrix = {
      {0, 1, 1, 1},
      {1, 1, 1, 1},
      {0, 1, 1, 1}};
  EXPECT_EQ(solution.countSquares(matrix), 15);
}

TEST_P(CountSquareSubmatricesWithAllOnesTest, Example2) {
  CountSquareSubmatricesWithAllOnesSolution solution;
  solution.setStrategy(GetParam());
  std::vector<std::vector<int>> matrix = {
      {1, 0, 1},
      {1, 1, 0},
      {1, 1, 0}};
  EXPECT_EQ(solution.countSquares(matrix), 7);
}

TEST_P(CountSquareSubmatricesWithAllOnesTest, SelfAuthoredSingleOne) {
  CountSquareSubmatricesWithAllOnesSolution solution;
  solution.setStrategy(GetParam());
  std::vector<std::vector<int>> matrix = {{1}};
  EXPECT_EQ(solution.countSquares(matrix), 1);
}

TEST_P(CountSquareSubmatricesWithAllOnesTest, SelfAuthoredSingleZero) {
  CountSquareSubmatricesWithAllOnesSolution solution;
  solution.setStrategy(GetParam());
  std::vector<std::vector<int>> matrix = {{0}};
  EXPECT_EQ(solution.countSquares(matrix), 0);
}

TEST_P(CountSquareSubmatricesWithAllOnesTest, SelfAuthoredSingleRow) {
  CountSquareSubmatricesWithAllOnesSolution solution;
  solution.setStrategy(GetParam());
  std::vector<std::vector<int>> matrix = {{1, 1, 1}};
  EXPECT_EQ(solution.countSquares(matrix), 3);  // each 1x1 square
}

TEST_P(CountSquareSubmatricesWithAllOnesTest, SelfAuthoredAllOnesTwoByTwo) {
  CountSquareSubmatricesWithAllOnesSolution solution;
  solution.setStrategy(GetParam());
  std::vector<std::vector<int>> matrix = {{1, 1}, {1, 1}};
  EXPECT_EQ(solution.countSquares(matrix), 5);  // 4 side-1 + 1 side-2
}

}  // namespace problem_1277
}  // namespace leetcode
