#include "leetcode/problems/minimum-moves-to-reach-target-with-rotations.h"

#include <queue>
#include <vector>

namespace leetcode::problem_1210 {

namespace {

int minimumMovesImpl(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());

  // Quick check: start or target cells blocked
  if (grid[0][0] == 1 || grid[0][1] == 1 ||
      grid[n - 1][n - 2] == 1 || grid[n - 1][n - 1] == 1) {
    return -1;
  }

  // visited[r][c][orientation]: 0 = horizontal, 1 = vertical
  std::vector<std::vector<std::array<bool, 2>>> visited(
      n, std::vector<std::array<bool, 2>>(n, {false, false}));

  // Queue stores (r, c, orientation)
  std::queue<std::tuple<int, int, int>> q;
  q.emplace(0, 0, 0);
  visited[0][0][0] = true;

  int steps = 0;
  while (!q.empty()) {
    const int level_size = static_cast<int>(q.size());
    for (int i = 0; i < level_size; ++i) {
      auto [r, c, orient] = q.front();
      q.pop();

      // Check if reached target
      if (orient == 0 && r == n - 1 && c == n - 2) {
        return steps;
      }

      if (orient == 0) {
        // Horizontal: tail at (r, c), head at (r, c+1)

        // 1. Move right: need (r, c+2) empty and in bounds
        if (c + 2 < n && grid[r][c + 2] == 0 && !visited[r][c + 1][0]) {
          visited[r][c + 1][0] = true;
          q.emplace(r, c + 1, 0);
        }

        // 2. Move down: need (r+1, c) and (r+1, c+1) both empty
        if (r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0) {
          if (!visited[r + 1][c][0]) {
            visited[r + 1][c][0] = true;
            q.emplace(r + 1, c, 0);
          }
          // 3. Rotate clockwise: becomes vertical at (r, c)
          if (!visited[r][c][1]) {
            visited[r][c][1] = true;
            q.emplace(r, c, 1);
          }
        }
      } else {
        // Vertical: tail at (r, c), head at (r+1, c)

        // 1. Move right: need (r, c+1) and (r+1, c+1) both empty
        if (c + 1 < n && grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0) {
          if (!visited[r][c + 1][1]) {
            visited[r][c + 1][1] = true;
            q.emplace(r, c + 1, 1);
          }
          // 4. Rotate counterclockwise: becomes horizontal at (r, c)
          if (!visited[r][c][0]) {
            visited[r][c][0] = true;
            q.emplace(r, c, 0);
          }
        }

        // 2. Move down: need (r+2, c) empty and in bounds
        if (r + 2 < n && grid[r + 2][c] == 0 && !visited[r + 1][c][1]) {
          visited[r + 1][c][1] = true;
          q.emplace(r + 1, c, 1);
        }
      }
    }
    ++steps;
  }

  return -1;
}

}  // namespace

MinimumMovesToReachTargetWithRotationsSolution::
    MinimumMovesToReachTargetWithRotationsSolution() {
  setMetaInfo({.id = 1210,
               .title = "Minimum Moves to Reach Target with Rotations",
               .url = "https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/"});

  registerStrategy(
      {.name = "BFS",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"Array", "Breadth-First Search", "Matrix"}},
      minimumMovesImpl);
}

int MinimumMovesToReachTargetWithRotationsSolution::minimumMoves(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_1210
