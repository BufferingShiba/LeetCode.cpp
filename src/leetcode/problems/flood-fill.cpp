#include "leetcode/problems/flood-fill.h"

#include <queue>
#include <utility>

namespace leetcode::problem_733 {

namespace {

std::vector<std::vector<int>> floodFillImpl(
    std::vector<std::vector<int>>& image, int sr, int sc, int color) {
  const int m = static_cast<int>(image.size());
  const int n = static_cast<int>(image[0].size());
  const int original = image[sr][sc];
  if (original == color) {
    return image;
  }

  std::queue<std::pair<int, int>> queue;
  queue.push({sr, sc});
  image[sr][sc] = color;
  constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  while (!queue.empty()) {
    auto [r, c] = queue.front();
    queue.pop();
    for (const auto& dir : dirs) {
      int nr = r + dir[0];
      int nc = c + dir[1];
      if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == original) {
        image[nr][nc] = color;
        queue.push({nr, nc});
      }
    }
  }
  return image;
}

}  // namespace

FloodFillSolution::FloodFillSolution() {
  setMetaInfo({.id = 733,
               .title = "Flood Fill",
               .url = "https://leetcode.com/problems/flood-fill/"});
  registerStrategy(
      {.name = "IterativeBFS",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"Array", "Breadth-First Search", "Matrix"}},
      floodFillImpl);
}

std::vector<std::vector<int>> FloodFillSolution::floodFill(
    std::vector<std::vector<int>>& image, int sr, int sc, int color) {
  return getSolution()(image, sr, sc, color);
}

}  // namespace leetcode::problem_733
