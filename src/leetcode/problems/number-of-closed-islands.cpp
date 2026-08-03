#include "leetcode/problems/number-of-closed-islands.h"

namespace leetcode {
namespace problem_1254 {

namespace {

int closedIslandImpl(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  const int dr[4] = {1, -1, 0, 0};
  const int dc[4] = {0, 0, 1, -1};

  // Touch border means the island is not fully enclosed -> not closed.
  // Returns true if the land region touches the grid border.
  std::function<bool(int, int, std::vector<std::vector<int>>&)> dfs =
      [&](int r, int c, std::vector<std::vector<int>>& g) -> bool {
    bool touchesBorder = (r == 0 || r == m - 1 || c == 0 || c == n - 1);
    g[r][c] = 2;  // mark visited
    for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (nr >= 0 && nr < m && nc >= 0 && nc < n && g[nr][nc] == 0) {
        touchesBorder = dfs(nr, nc, g) || touchesBorder;
      }
    }
    return touchesBorder;
  };

  int count = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid[r][c] == 0) {
        if (!dfs(r, c, grid)) {
          ++count;
        }
      }
    }
  }
  return count;
}

}  // namespace

NumberOfClosedIslandsSolution::NumberOfClosedIslandsSolution() {
  setMetaInfo({.id = 1254,
               .title = "Number of Closed Islands",
               .url =
                   "https://leetcode.com/problems/number-of-closed-islands/"});
  registerStrategy(
      {
          .name = "DFS flood fill",
          .expected = "Accepted",
          .time_complexity = "O(m * n)",
          .space_complexity = "O(m * n)",
          .tags = {"DFS", "Matrix"},
          .notes =
              "Mark each 0-land region via DFS; if it does not touch the grid "
              "border it is fully enclosed by water (cells outside the grid are "
              "not water), hence it is a closed island.",
      },
      closedIslandImpl);
}

int NumberOfClosedIslandsSolution::closedIsland(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_1254
}  // namespace leetcode
