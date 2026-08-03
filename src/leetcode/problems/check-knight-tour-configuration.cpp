#include "leetcode/problems/check-knight-tour-configuration.h"

namespace leetcode {
namespace problem_2596 {

static bool solution1(vector<vector<int>>& grid) {
  int n = (int)grid.size();
  // Coordinate lookup: pos[value] = {row, col}
  vector<pair<int, int>> pos(n * n);
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      pos[grid[r][c]] = {r, c};
    }
  }

  // Knight must start at the top-left cell.
  if (grid[0][0] != 0) return false;

  static const int knightMoves[8][2] = {
      {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
      {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

  for (int v = 1; v < n * n; ++v) {
    int dr = pos[v].first - pos[v - 1].first;
    int dc = pos[v].second - pos[v - 1].second;
    bool validMove = false;
    for (auto& mv : knightMoves) {
      if (dr == mv[0] && dc == mv[1]) {
        validMove = true;
        break;
      }
    }
    if (!validMove) return false;
  }
  return true;
}

CheckKnightTourConfigurationSolution::CheckKnightTourConfigurationSolution() {
  setMetaInfo({
      .id = 2596,
      .title = "Check Knight Tour Configuration",
      .url = "https://leetcode.com/problems/check-knight-tour-configuration"
  });
  registerStrategy({.name = "Brute Force", .time_complexity = "O(n^2)", .space_complexity = "O(n^2)", .tags = {"Array", "Matrix"}}, solution1);
}

bool CheckKnightTourConfigurationSolution::checkValidGrid(vector<vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_2596
}  // namespace leetcode
