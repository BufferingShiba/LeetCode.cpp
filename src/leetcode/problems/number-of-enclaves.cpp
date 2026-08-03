#include "leetcode/problems/number-of-enclaves.h"

#include <queue>
#include <utility>

namespace leetcode {
namespace problem_1020 {

namespace {

int numEnclavesImpl(std::vector<std::vector<int>>& grid) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());

  const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  std::queue<std::pair<int, int>> q;

  // Enqueue all boundary land cells and mark them as sea (visited)
  for (int i = 0; i < m; ++i) {
    if (grid[i][0] == 1) {
      grid[i][0] = 0;
      q.emplace(i, 0);
    }
    if (n > 1 && grid[i][n - 1] == 1) {
      grid[i][n - 1] = 0;
      q.emplace(i, n - 1);
    }
  }
  for (int j = 0; j < n; ++j) {
    if (grid[0][j] == 1) {
      grid[0][j] = 0;
      q.emplace(0, j);
    }
    if (m > 1 && grid[m - 1][j] == 1) {
      grid[m - 1][j] = 0;
      q.emplace(m - 1, j);
    }
  }

  // BFS to flood-fill all cells reachable from the boundary
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    for (const auto& dir : dirs) {
      int nr = r + dir[0];
      int nc = c + dir[1];
      if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
        grid[nr][nc] = 0;
        q.emplace(nr, nc);
      }
    }
  }

  // Count remaining land cells (enclaves)
  int count = 0;
  for (const auto& row : grid) {
    for (int val : row) {
      if (val == 1) ++count;
    }
  }
  return count;
}

}  // namespace

NumberOfEnclavesSolution::NumberOfEnclavesSolution() {
  setMetaInfo({.id = 1020,
               .title = "Number of Enclaves",
               .url = "https://leetcode.com/problems/number-of-enclaves/"});
  registerStrategy({.name = "BFS from boundary",
                    .expected = "Accepted",
                    .time_complexity = "O(m * n)",
                    .space_complexity = "O(m * n)",
                    .tags = {"Array", "Breadth-First Search", "Matrix"}},
                   numEnclavesImpl);
}

int NumberOfEnclavesSolution::numEnclaves(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_1020
}  // namespace leetcode
