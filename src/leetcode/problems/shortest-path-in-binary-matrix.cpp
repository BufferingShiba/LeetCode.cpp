#include "leetcode/problems/shortest-path-in-binary-matrix.h"

#include <queue>
#include <utility>

namespace leetcode {
namespace problem_1091 {
namespace {

int shortestPathBinaryMatrixImpl(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  if (n == 0) return -1;
  if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
  if (n == 1) return 1;

  // dist[r][c] = shortest path length (number of cells) reaching (r,c).
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, -1));
  dist[0][0] = 1;

  std::queue<std::pair<int, int>> q;
  q.push({0, 0});

  const int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
  const int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    if (r == n - 1 && c == n - 1) return dist[r][c];

    for (int k = 0; k < 8; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
      if (grid[nr][nc] == 1 || dist[nr][nc] != -1) continue;
      dist[nr][nc] = dist[r][c] + 1;
      q.push({nr, nc});
    }
  }

  return -1;
}

}  // namespace

ShortestPathInBinaryMatrixSolution::ShortestPathInBinaryMatrixSolution() {
  setMetaInfo({
      .id = 1091,
      .title = "Shortest Path in Binary Matrix",
      .url = "https://leetcode.com/problems/shortest-path-in-binary-matrix/",
  });

  registerStrategy(
      {
          .name = "BFS",
          .expected = "Accepted",
          .time_complexity = "O(n^2)",
          .space_complexity = "O(n^2)",
          .tags = {"Breadth-First Search", "Matrix"},
          .notes = "8-directional BFS over the grid; shortest path guaranteed by unit weights.",
      },
      shortestPathBinaryMatrixImpl);
}

int ShortestPathInBinaryMatrixSolution::shortestPathBinaryMatrix(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_1091
}  // namespace leetcode
