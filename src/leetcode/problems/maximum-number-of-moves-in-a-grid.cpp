#include "leetcode/problems/maximum-number-of-moves-in-a-grid.h"

#include <algorithm>

namespace leetcode {
namespace problem_2684 {
namespace {

int maxMovesImpl(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  std::vector<int> cur(m, 0);   // moves for current column
  std::vector<int> next(m, -1); // moves for next column
  int best = 0;

  for (int col = 0; col < n - 1; ++col) {
    std::fill(next.begin(), next.end(), -1);
    for (int row = 0; row < m; ++row) {
      if (cur[row] < 0) continue;
      const int val = grid[row][col];
      for (int dr = -1; dr <= 1; ++dr) {
        const int nr = row + dr;
        if (nr < 0 || nr >= m) continue;
        if (grid[nr][col + 1] > val) {
          next[nr] = std::max(next[nr], cur[row] + 1);
        }
      }
    }
    int colBest = -1;
    for (int row = 0; row < m; ++row) {
      colBest = std::max(colBest, next[row]);
    }
    if (colBest < 0) break;
    best = std::max(best, colBest);
    cur.swap(next);
  }

  return best;
}

}  // namespace

MaximumNumberOfMovesInAGrid::MaximumNumberOfMovesInAGrid() {
  setMetaInfo({.id = 2684,
               .title = "Maximum Number of Moves in a Grid",
               .url = "https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/"});
  registerStrategy(
      {.name = "ColumnDP",
       .expected = "Accepted",
       .time_complexity = "O(m * n)",
       .space_complexity = "O(m)",
       .tags = {"Array", "Dynamic Programming", "Matrix"}},
      maxMovesImpl);
}

int MaximumNumberOfMovesInAGrid::maxMoves(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_2684
}  // namespace leetcode
