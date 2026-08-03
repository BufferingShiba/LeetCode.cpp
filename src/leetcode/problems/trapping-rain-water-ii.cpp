#include "leetcode/problems/trapping-rain-water-ii.h"

#include <queue>
#include <tuple>
#include <vector>

namespace leetcode::problem_407 {
namespace {

int trapRainWaterHeap(std::vector<std::vector<int>>& heightMap) {
  const int m = static_cast<int>(heightMap.size());
  const int n = static_cast<int>(heightMap[0].size());
  if (m < 3 || n < 3) {
    return 0;  // Need an enclosed region to trap water.
  }

  const int dr[4] = {-1, 1, 0, 0};
  const int dc[4] = {0, 0, -1, 1};

  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  // Min-heap: {height, row, col}.
  using Cell = std::tuple<int, int, int>;
  std::priority_queue<Cell, std::vector<Cell>, std::greater<Cell>> pq;

  // Push all boundary cells.
  for (int i = 0; i < m; ++i) {
    pq.push({heightMap[i][0], i, 0});
    pq.push({heightMap[i][n - 1], i, n - 1});
    visited[i][0] = true;
    visited[i][n - 1] = true;
  }
  for (int j = 0; j < n; ++j) {
    pq.push({heightMap[0][j], 0, j});
    pq.push({heightMap[m - 1][j], m - 1, j});
    visited[0][j] = true;
    visited[m - 1][j] = true;
  }

  int water = 0;
  while (!pq.empty()) {
    auto [bound_h, r, c] = pq.top();
    pq.pop();

    for (int k = 0; k < 4; ++k) {
      const int nr = r + dr[k];
      const int nc = c + dc[k];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) {
        continue;
      }
      visited[nr][nc] = true;
      // The current water level to reach this cell is bound_h. If the cell is
      // lower, it traps water; otherwise it becomes the new bound.
      if (heightMap[nr][nc] < bound_h) {
        water += bound_h - heightMap[nr][nc];
        pq.push({bound_h, nr, nc});
      } else {
        pq.push({heightMap[nr][nc], nr, nc});
      }
    }
  }
  return water;
}

}  // namespace

TrappingRainWaterIiSolution::TrappingRainWaterIiSolution() {
  setMetaInfo({.id = 407,
               .title = "Trapping Rain Water II",
               .url = "https://leetcode.com/problems/trapping-rain-water-ii/"});
  registerStrategy(
      {.name = "min_heap_boundary",
       .expected = "Accepted",
       .time_complexity = "O(m*n*log(m*n))",
       .space_complexity = "O(m*n)",
       .tags = {"Array", "Breadth-First Search", "Heap (Priority Queue)",
                "Matrix"}},
      trapRainWaterHeap);
}

int TrappingRainWaterIiSolution::trapRainWater(
    std::vector<std::vector<int>>& heightMap) {
  return getSolution()(heightMap);
}

}  // namespace leetcode::problem_407
