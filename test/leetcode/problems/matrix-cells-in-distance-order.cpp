#include <gtest/gtest.h>

#include <set>
#include <utility>

#include "leetcode/problems/matrix-cells-in-distance-order.h"

namespace leetcode {
namespace problem_1030 {

class MatrixCellsInDistanceOrderTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  MatrixCellsInDistanceOrderSolution solution_;
};

TEST_P(MatrixCellsInDistanceOrderTest, Example1) {
  int rows = 1, cols = 2, rCenter = 0, cCenter = 0;
  auto result = solution_.allCellsDistOrder(rows, cols, rCenter, cCenter);
  EXPECT_EQ(result.size(), 2);
  EXPECT_EQ(result[0], std::vector<int>({0, 0}));
  EXPECT_EQ(result[1], std::vector<int>({0, 1}));
}

TEST_P(MatrixCellsInDistanceOrderTest, Example2) {
  int rows = 2, cols = 2, rCenter = 0, cCenter = 1;
  auto result = solution_.allCellsDistOrder(rows, cols, rCenter, cCenter);
  EXPECT_EQ(result.size(), 4);
  // 验证所有单元格都出现
  std::set<std::pair<int, int>> expectedCells = {
      {0, 0}, {0, 1}, {1, 0}, {1, 1}};
  std::set<std::pair<int, int>> resultCells;
  for (const auto& cell : result) {
    resultCells.insert({cell[0], cell[1]});
  }
  EXPECT_EQ(resultCells, expectedCells);
  // 验证距离非递减
  for (size_t i = 1; i < result.size(); ++i) {
    int d1 = std::abs(result[i - 1][0] - rCenter) +
             std::abs(result[i - 1][1] - cCenter);
    int d2 = std::abs(result[i][0] - rCenter) +
             std::abs(result[i][1] - cCenter);
    EXPECT_LE(d1, d2);
  }
}

TEST_P(MatrixCellsInDistanceOrderTest, Example3) {
  int rows = 2, cols = 3, rCenter = 1, cCenter = 2;
  auto result = solution_.allCellsDistOrder(rows, cols, rCenter, cCenter);
  EXPECT_EQ(result.size(), 6);
  // 验证所有单元格
  std::set<std::pair<int, int>> expectedCells;
  for (int r = 0; r < rows; ++r)
    for (int c = 0; c < cols; ++c) expectedCells.insert({r, c});
  std::set<std::pair<int, int>> resultCells;
  for (const auto& cell : result) resultCells.insert({cell[0], cell[1]});
  EXPECT_EQ(resultCells, expectedCells);
  // 验证距离非递减
  for (size_t i = 1; i < result.size(); ++i) {
    int d1 = std::abs(result[i - 1][0] - rCenter) +
             std::abs(result[i - 1][1] - cCenter);
    int d2 = std::abs(result[i][0] - rCenter) +
             std::abs(result[i][1] - cCenter);
    EXPECT_LE(d1, d2);
  }
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MatrixCellsInDistanceOrderTest,
    ::testing::ValuesIn(
        MatrixCellsInDistanceOrderSolution().getStrategyNames()));

}  // namespace problem_1030
}  // namespace leetcode
