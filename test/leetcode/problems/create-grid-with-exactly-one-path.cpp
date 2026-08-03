#include "leetcode/problems/create-grid-with-exactly-one-path.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3963 {

namespace {

bool isFree(char c) { return c == '.'; }

bool isValidPath(const std::vector<std::string>& grid, int m, int n) {
  // 统计从 (0,0) 出发、只能向右/向下、仅经过自由格的路径数量（上限 2 即视为超过 1）。
  if (!isFree(grid[0][0])) return false;
  std::vector<std::vector<int>> ways(m, std::vector<int>(n, 0));
  ways[0][0] = 1;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!isFree(grid[i][j])) continue;
      if (i > 0 && ways[i - 1][j] > 0) ways[i][j] += ways[i - 1][j];
      if (j > 0 && ways[i][j - 1] > 0) ways[i][j] += ways[i][j - 1];
      if (ways[i][j] > 1) return false;  // 多条路径
    }
  }
  return ways[m - 1][n - 1] == 1;
}

}  // namespace

class CreateGridWithExactlyOnePathTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CreateGridWithExactlyOnePathSolution solution_;
};

TEST_P(CreateGridWithExactlyOnePathTest, OfficialExample1) {
  int m = 2, n = 3;
  auto grid = solution_.createGrid(m, n);
  ASSERT_EQ(grid.size(), static_cast<size_t>(m));
  EXPECT_TRUE(isValidPath(grid, m, n));
}

TEST_P(CreateGridWithExactlyOnePathTest, OfficialExample2) {
  int m = 3, n = 3;
  auto grid = solution_.createGrid(m, n);
  ASSERT_EQ(grid.size(), static_cast<size_t>(m));
  EXPECT_TRUE(isValidPath(grid, m, n));
}

TEST_P(CreateGridWithExactlyOnePathTest, OfficialExample3) {
  int m = 1, n = 4;
  auto grid = solution_.createGrid(m, n);
  ASSERT_EQ(grid.size(), static_cast<size_t>(m));
  EXPECT_TRUE(isValidPath(grid, m, n));
}

TEST_P(CreateGridWithExactlyOnePathTest, SelfAuthoredSingleColumn) {
  int m = 5, n = 1;
  auto grid = solution_.createGrid(m, n);
  ASSERT_EQ(grid.size(), static_cast<size_t>(m));
  EXPECT_TRUE(isValidPath(grid, m, n));
}

TEST_P(CreateGridWithExactlyOnePathTest, SelfAuthoredSingleRow) {
  int m = 1, n = 1;
  auto grid = solution_.createGrid(m, n);
  ASSERT_EQ(grid.size(), static_cast<size_t>(m));
  EXPECT_TRUE(isValidPath(grid, m, n));
}

INSTANTIATE_TEST_SUITE_P(
    CreateGridWithExactlyOnePathTests, CreateGridWithExactlyOnePathTest,
    ::testing::ValuesIn(CreateGridWithExactlyOnePathSolution().getStrategyNames()));

}  // namespace problem_3963
}  // namespace leetcode
