#include "leetcode/problems/01-matrix.h"

#include <queue>

namespace leetcode {
namespace problem_542 {

static vector<vector<int>> solution1(vector<vector<int>>& mat) {
  int m = mat.size();
  int n = mat[0].size();
  vector<vector<int>> dist(m, vector<int>(n, -1));
  std::queue<std::pair<int, int>> q;

  // Multi-source BFS: all zeros are sources with distance 0.
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] == 0) {
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    for (auto& d : dirs) {
      int nr = r + d[0];
      int nc = c + d[1];
      if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == -1) {
        dist[nr][nc] = dist[r][c] + 1;
        q.push({nr, nc});
      }
    }
  }
  return dist;
}

Problem01MatrixSolution::Problem01MatrixSolution() {
  setMetaInfo({
      .id = 542,
      .title = "01 Matrix",
      .url = "https://leetcode.com/problems/01-matrix"
  });
  registerStrategy(
      {.name = "Multi-source BFS",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"BFS", "Array", "Matrix"}},
      solution1);
}

vector<vector<int>> Problem01MatrixSolution::updateMatrix(vector<vector<int>>& mat) {
  return getSolution()(mat);
}

}  // namespace problem_542
}  // namespace leetcode
