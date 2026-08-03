#include "leetcode/problems/path-with-minimum-effort.h"

#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

namespace leetcode {
namespace problem_1631 {

namespace {

bool canReach(const std::vector<std::vector<int>>& heights, int limit) {
  int rows = static_cast<int>(heights.size());
  int cols = static_cast<int>(heights[0].size());

  std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
  std::queue<std::pair<int, int>> q;

  q.emplace(0, 0);
  visited[0][0] = true;

  constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    if (r == rows - 1 && c == cols - 1) {
      return true;
    }

    for (auto& d : dirs) {
      int nr = r + d[0];
      int nc = c + d[1];
      if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
      if (visited[nr][nc]) continue;
      if (std::abs(heights[nr][nc] - heights[r][c]) > limit) continue;

      visited[nr][nc] = true;
      q.emplace(nr, nc);
    }
  }

  return false;
}

int minimumEffortPathImpl(std::vector<std::vector<int>>& heights) {
  int rows = static_cast<int>(heights.size());
  int cols = static_cast<int>(heights[0].size());

  // Edge case: single cell
  if (rows == 1 && cols == 1) return 0;

  // Compute max adjacent difference for upper bound
  int maxDiff = 0;
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      if (r + 1 < rows) {
        maxDiff = std::max(maxDiff,
                           std::abs(heights[r + 1][c] - heights[r][c]));
      }
      if (c + 1 < cols) {
        maxDiff = std::max(maxDiff,
                           std::abs(heights[r][c + 1] - heights[r][c]));
      }
    }
  }

  int left = 0;
  int right = maxDiff;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (canReach(heights, mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return left;
}

}  // namespace

PathWithMinimumEffortSolution::PathWithMinimumEffortSolution() {
  setMetaInfo({.id = 1631,
               .title = "Path With Minimum Effort",
               .url = "https://leetcode.com/problems/path-with-minimum-effort/"});

  registerStrategy(
      {.name = "BinarySearch + BFS",
       .expected = "Accepted",
       .time_complexity = "O(m * n * log(M))",
       .space_complexity = "O(m * n)",
       .tags = {"Array", "Binary Search", "Breadth-First Search"}},
      minimumEffortPathImpl);
}

int PathWithMinimumEffortSolution::minimumEffortPath(
    std::vector<std::vector<int>>& heights) {
  return getSolution()(heights);
}

}  // namespace problem_1631
}  // namespace leetcode
