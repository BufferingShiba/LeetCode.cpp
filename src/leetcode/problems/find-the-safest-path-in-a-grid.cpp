#include "leetcode/problems/find-the-safest-path-in-a-grid.h"

#include <queue>
#include <vector>

namespace leetcode {
namespace problem_2812 {

static int solution1(std::vector<std::vector<int>>& grid) {
  int n = static_cast<int>(grid.size());
  const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  // Multi-source BFS from all thief cells to compute distance to nearest thief.
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, -1));
  std::queue<std::pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    for (const auto& d : dirs) {
      int nr = r + d[0], nc = c + d[1];
      if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
        dist[nr][nc] = dist[r][c] + 1;
        q.push({nr, nc});
      }
    }
  }

  // Binary search the maximum safeness factor.
  auto canReach = [&](int k) {
    if (dist[0][0] < k || dist[n - 1][n - 1] < k) return false;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();
      if (r == n - 1 && c == n - 1) return true;
      for (const auto& d : dirs) {
        int nr = r + d[0], nc = c + d[1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] &&
            dist[nr][nc] >= k) {
          visited[nr][nc] = true;
          q.push({nr, nc});
        }
      }
    }
    return false;
  };

  int lo = 0, hi = 2 * n;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (canReach(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo;
}

FindTheSafestPathInAGridSolution::FindTheSafestPathInAGridSolution() {
  setMetaInfo({
      .id = 2812,
      .title = "Find the Safest Path in a Grid",
      .url = "https://leetcode.com/problems/find-the-safest-path-in-a-grid"
  });
  registerStrategy(
      {.name = "MultiSourceBFS + BinarySearch",
       .expected = "Accepted",
       .time_complexity = "O(n^2 log n)",
       .space_complexity = "O(n^2)",
       .tags = {"BFS", "Binary Search"}},
      solution1);
}

int FindTheSafestPathInAGridSolution::maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_2812
}  // namespace leetcode
