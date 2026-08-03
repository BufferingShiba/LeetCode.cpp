#include "leetcode/problems/number-of-increasing-paths-in-a-grid.h"

#include <vector>

namespace leetcode {
namespace problem_2328 {

namespace {

constexpr int kMod = 1'000'000'007;
constexpr int kDx[4] = {0, 0, 1, -1};
constexpr int kDy[4] = {1, -1, 0, 0};

int Dfs(int i, int j, const std::vector<std::vector<int>>& grid,
        std::vector<std::vector<int>>& memo) {
  if (memo[i][j] != -1) {
    return memo[i][j];
  }
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());
  long long total = 1;  // 单格路径
  for (int d = 0; d < 4; ++d) {
    int ni = i + kDx[d];
    int nj = j + kDy[d];
    if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > grid[i][j]) {
      total = (total + Dfs(ni, nj, grid, memo)) % kMod;
    }
  }
  return memo[i][j] = static_cast<int>(total);
}

int countPathsImpl(std::vector<std::vector<int>>& grid) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());
  std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      ans = (ans + Dfs(i, j, grid, memo)) % kMod;
    }
  }
  return static_cast<int>(ans);
}

}  // namespace

NumberOfIncreasingPathsInAGridSolution::NumberOfIncreasingPathsInAGridSolution() {
  setMetaInfo({.id = 2328,
               .title = "Number of Increasing Paths in a Grid",
               .url = "https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/"});
  registerStrategy(
      {.name = "DFS with Memoization",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"Array", "Dynamic Programming", "Depth-First Search", "Memoization", "Matrix"}},
      countPathsImpl);
}

int NumberOfIncreasingPathsInAGridSolution::countPaths(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_2328
}  // namespace leetcode
