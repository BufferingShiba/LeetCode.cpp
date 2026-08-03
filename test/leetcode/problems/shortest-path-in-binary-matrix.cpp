#include "leetcode/problems/shortest-path-in-binary-matrix.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1091 {
namespace {

class ShortestPathInBinaryMatrixTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ShortestPathInBinaryMatrixSolution solution;
};

TEST_P(ShortestPathInBinaryMatrixTest, Example1) {
  std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};
  EXPECT_EQ(2, solution.shortestPathBinaryMatrix(grid));
}

TEST_P(ShortestPathInBinaryMatrixTest, Example2) {
  std::vector<std::vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  EXPECT_EQ(4, solution.shortestPathBinaryMatrix(grid));
}

TEST_P(ShortestPathInBinaryMatrixTest, Example3) {
  std::vector<std::vector<int>> grid = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  EXPECT_EQ(-1, solution.shortestPathBinaryMatrix(grid));
}

TEST_P(ShortestPathInBinaryMatrixTest, EdgeSingleCell) {
  std::vector<std::vector<int>> grid = {{0}};
  EXPECT_EQ(1, solution.shortestPathBinaryMatrix(grid));
}

TEST_P(ShortestPathInBinaryMatrixTest, EdgeSingleCellBlocked) {
  std::vector<std::vector<int>> grid = {{1}};
  EXPECT_EQ(-1, solution.shortestPathBinaryMatrix(grid));
}

TEST_P(ShortestPathInBinaryMatrixTest, AllClear3x3) {
  std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  // Shortest path is the diagonal: (0,0)->(1,1)->(2,2), length 3.
  EXPECT_EQ(3, solution.shortestPathBinaryMatrix(grid));
}

TEST_P(ShortestPathInBinaryMatrixTest, BlockedStart) {
  std::vector<std::vector<int>> grid = {
      {1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  EXPECT_EQ(-1, solution.shortestPathBinaryMatrix(grid));
}

INSTANTIATE_TEST_SUITE_P(
    ShortestPathInBinaryMatrixStrategies,
    ShortestPathInBinaryMatrixTest,
    ::testing::ValuesIn(ShortestPathInBinaryMatrixSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1091
}  // namespace leetcode
