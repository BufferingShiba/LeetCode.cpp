
#include "leetcode/problems/number-of-islands.h"

namespace leetcode {
namespace problem_200 {

// DFS 洪水填充
// 遍历每个格子，遇到 '1' 时计数 +1，并用 DFS 将整个岛屿标记为已访问（原地置 '0'）。
// 时间复杂度: O(m*n), 空间复杂度: O(m*n)（递归栈深度最坏为整个网格）
static int solution_dfs(vector<vector<char>>& grid) {
  const int m = grid.size();
  const int n = grid[0].size();
  int count = 0;

  std::function<void(int, int)> dfs = [&](int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;
    grid[r][c] = '0';
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
  };

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '1') {
        ++count;
        dfs(i, j);
      }
    }
  }
  return count;
}

NumberOfIslandsSolution::NumberOfIslandsSolution() {
  setMetaInfo({.id = 200,
               .title = "Number of Islands",
               .url = "https://leetcode.com/problems/number-of-islands"});
  registerStrategy(
      {.name = "DFS Flood Fill",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"Depth-First Search", "Matrix"}},
      solution_dfs);
}

int NumberOfIslandsSolution::numIslands(vector<vector<char>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_200
}  // namespace leetcode
