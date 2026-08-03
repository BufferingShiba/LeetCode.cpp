#include "leetcode/problems/map-of-highest-peak.h"

#include <queue>
#include <utility>

namespace leetcode::problem_1765 {

namespace {

std::vector<std::vector<int>> highestPeakImpl(std::vector<std::vector<int>>& isWater) {
  const int m = static_cast<int>(isWater.size());
  const int n = static_cast<int>(isWater[0].size());
  const int INF = m * n + 5;

  std::vector<std::vector<int>> height(m, std::vector<int>(n, INF));
  std::queue<std::pair<int, int>> q;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (isWater[i][j] == 1) {
        height[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (const auto& d : dirs) {
      const int nx = x + d[0];
      const int ny = y + d[1];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == INF) {
        height[nx][ny] = height[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }

  return height;
}

}  // namespace

MapOfHighestPeakSolution::MapOfHighestPeakSolution() {
  setMetaInfo({.id = 1765,
               .title = "Map of Highest Peak",
               .url = "https://leetcode.com/problems/map-of-highest-peak/"});

  registerStrategy({.name = "BFS",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n)",
                    .space_complexity = "O(m*n)",
                    .tags = {"Array", "Breadth-First Search", "Matrix"},
                    .notes = "Multisource BFS; height equals shortest distance to nearest water."},
                   &highestPeakImpl);
}

std::vector<std::vector<int>> MapOfHighestPeakSolution::highestPeak(
    std::vector<std::vector<int>>& isWater) {
  return getSolution()(isWater);
}

}  // namespace leetcode::problem_1765
