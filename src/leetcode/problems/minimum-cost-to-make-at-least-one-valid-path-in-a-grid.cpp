#include "leetcode/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid.h"

#include <deque>
#include <limits>
#include <utility>

namespace leetcode {
namespace problem_1368 {

namespace {

using Cell = std::pair<int, int>;

// 0-1 BFS: edge to the arrow direction costs 0, other three directions cost 1.
int minCostImpl(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  // directions indexed by arrow value 1..4
  static const int dr[5] = {0, 0, 0, 1, -1};
  static const int dc[5] = {0, 1, -1, 0, 0};

  std::vector<std::vector<int>> dist(
      m, std::vector<int>(n, std::numeric_limits<int>::max()));
  std::deque<Cell> dq;

  dist[0][0] = 0;
  dq.emplace_back(0, 0);

  while (!dq.empty()) {
    Cell cur = dq.front();
    dq.pop_front();
    int r = cur.first;
    int c = cur.second;
    if (cur.first == m - 1 && cur.second == n - 1) {
      return dist[r][c];
    }

    const int arrow = grid[r][c];
    for (int dir = 1; dir <= 4; ++dir) {
      int nr = r + dr[dir];
      int nc = c + dc[dir];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
        continue;
      }
      int w = (dir == arrow) ? 0 : 1;
      if (dist[r][c] + w < dist[nr][nc]) {
        dist[nr][nc] = dist[r][c] + w;
        if (w == 0) {
          dq.push_front({nr, nc});
        } else {
          dq.push_back({nr, nc});
        }
      }
    }
  }

  // The grid is always reachable (we can modify arrows), this returns a fallback.
  return dist[m - 1][n - 1];
}

}  // namespace

MinimumCostToMakeAtLeastOneValidPathInAGridSolution::
    MinimumCostToMakeAtLeastOneValidPathInAGridSolution() {
  setMetaInfo({.id = 1368,
               .title = "Minimum Cost to Make at Least One Valid Path in a Grid",
               .url = "https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/"});
  registerStrategy(
      {.name = "ZeroOneBFS",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"BFS", "Shortest Path", "Graph Theory", "Matrix",
                "Heap (Priority Queue)"},
       .notes = "0-1 BFS with deque; moving along the arrow costs 0, other \
directions cost 1."},
      minCostImpl);
}

int MinimumCostToMakeAtLeastOneValidPathInAGridSolution::minCost(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_1368
}  // namespace leetcode
