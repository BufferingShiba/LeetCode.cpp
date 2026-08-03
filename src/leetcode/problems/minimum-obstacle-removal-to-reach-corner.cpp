#include "leetcode/problems/minimum-obstacle-removal-to-reach-corner.h"

#include <deque>
#include <utility>

namespace leetcode::problem_2290 {

namespace {

int minimumObstaclesImpl(std::vector<std::vector<int>>& grid) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());
  const int kInf = 0x3f3f3f3f;

  std::vector<std::vector<int>> dist(m, std::vector<int>(n, kInf));
  dist[0][0] = 0;

  std::deque<std::pair<int, int>> dq;
  dq.emplace_back(0, 0);

  const int dr[4] = {-1, 1, 0, 0};
  const int dc[4] = {0, 0, -1, 1};

  while (!dq.empty()) {
    auto [r, c] = dq.front();
    dq.pop_front();

    for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

      int weight = grid[nr][nc];
      int nd = dist[r][c] + weight;
      if (nd < dist[nr][nc]) {
        dist[nr][nc] = nd;
        if (weight == 0) {
          dq.emplace_front(nr, nc);
        } else {
          dq.emplace_back(nr, nc);
        }
      }
    }
  }

  return dist[m - 1][n - 1];
}

}  // namespace

MinimumObstacleRemovalToReachCornerSolution::
    MinimumObstacleRemovalToReachCornerSolution() {
  setMetaInfo(
      {.id = 2290,
       .title = "Minimum Obstacle Removal to Reach Corner",
       .url =
           "https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/"});

  registerStrategy(
      {.name = "0-1 BFS",
       .expected = "Accepted",
       .time_complexity = "O(m * n)",
       .space_complexity = "O(m * n)",
       .tags = {"Breadth-First Search", "Shortest Path",
                "Graph Theory", "Matrix"}},
      minimumObstaclesImpl);
}

int MinimumObstacleRemovalToReachCornerSolution::minimumObstacles(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_2290
