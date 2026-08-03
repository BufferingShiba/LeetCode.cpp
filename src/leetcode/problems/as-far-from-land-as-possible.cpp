#include "leetcode/problems/as-far-from-land-as-possible.h"

#include <queue>
#include <utility>

namespace leetcode::problem_1162 {

namespace {

int maxDistanceImpl(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  std::queue<std::pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        q.push({i, j});
      }
    }
  }
  // 没有陆地或没有水
  if (q.empty() || q.size() == static_cast<size_t>(n * n)) {
    return -1;
  }

  const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int dist = -1;
  while (!q.empty()) {
    int level = static_cast<int>(q.size());
    ++dist;
    while (level-- > 0) {
      auto [x, y] = q.front();
      q.pop();
      for (const auto& d : dirs) {
        int nx = x + d[0];
        int ny = y + d[1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != 0) {
          continue;
        }
        grid[nx][ny] = 1;  // 标记已访问
        q.push({nx, ny});
      }
    }
  }
  return dist;
}

}  // namespace

int AsFarFromLandAsPossibleSolution::maxDistance(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

AsFarFromLandAsPossibleSolution::AsFarFromLandAsPossibleSolution() {
  setMetaInfo({.id = 1162,
               .title = "As Far from Land as Possible",
               .url =
                   "https://leetcode.com/problems/as-far-from-land-as-possible/"});
  registerStrategy(
      {.name = "multi-source-bfs",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"BFS", "Matrix"}},
      maxDistanceImpl);
}

}  // namespace leetcode::problem_1162
