#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/difference-between-ones-and-zeros-in-row-and-column.h"

namespace leetcode {
namespace problem_2482 {

class DifferenceBetweenOnesAndZerosInRowAndColumnTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DifferenceBetweenOnesAndZerosInRowAndColumnSolution solution;
};

TEST_P(DifferenceBetweenOnesAndZerosInRowAndColumnTest, Example1) {
  std::vector<std::vector<int>> grid = {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
  std::vector<std::vector<int>> expected = {
      {0, 0, 4}, {0, 0, 4}, {-2, -2, 2}};
  EXPECT_EQ(solution.onesMinusZeros(grid), expected);
}

TEST_P(DifferenceBetweenOnesAndZerosInRowAndColumnTest, Example2) {
  std::vector<std::vector<int>> grid = {{1, 1, 1}, {1, 1, 1}};
  std::vector<std::vector<int>> expected = {{5, 5, 5}, {5, 5, 5}};
  EXPECT_EQ(solution.onesMinusZeros(grid), expected);
}

TEST_P(DifferenceBetweenOnesAndZerosInRowAndColumnTest, SingleCellOne) {
  std::vector<std::vector<int>> grid = {{1}};
  // m=1, n=1: onesRow=onesCol=1, zerosRow=zerosCol=0
  std::vector<std::vector<int>> expected = {{2}};
  EXPECT_EQ(solution.onesMinusZeros(grid), expected);
}

TEST_P(DifferenceBetweenOnesAndZerosInRowAndColumnTest, SingleCellZero) {
  std::vector<std::vector<int>> grid = {{0}};
  // m=1, n=1: onesRow=onesCol=0, zerosRow=zerosCol=1
  std::vector<std::vector<int>> expected = {{-2}};
  EXPECT_EQ(solution.onesMinusZeros(grid), expected);
}

TEST_P(DifferenceBetweenOnesAndZerosInRowAndColumnTest, MixedRowCol) {
  std::vector<std::vector<int>> grid = {{1, 0, 1}, {0, 1, 0}};
  // m=2, n=3
  // onesRow = [2, 1], onesCol = [1, 1, 1]
  // zerosRow = [1, 2], zerosCol = [1, 1, 1]
  // diff[0][0]=2+1-1-1=1; diff[0][1]=2+1-1-1=1; diff[0][2]=2+1-1-1=1
  // diff[1][0]=1+1-2-1=-1; diff[1][1]=1+1-2-1=-1; diff[1][2]=1+1-2-1=-1
  std::vector<std::vector<int>> expected = {{1, 1, 1}, {-1, -1, -1}};
  EXPECT_EQ(solution.onesMinusZeros(grid), expected);
}

INSTANTIATE_TEST_SUITE_P(
    DifferenceBetweenOnesAndZerosInRowAndColumnTestSuite,
    DifferenceBetweenOnesAndZerosInRowAndColumnTest,
    ::testing::ValuesIn(DifferenceBetweenOnesAndZerosInRowAndColumnSolution()
                            .getStrategyNames()));

}  // namespace problem_2482
}  // namespace leetcode
