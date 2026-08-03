#include "leetcode/problems/cherry-pickup-ii.h"

#include <algorithm>
#include <limits>

namespace leetcode::problem_1463 {

namespace {

int cherryPickupImpl(std::vector<std::vector<int>>& grid) {
  const int rows = static_cast<int>(grid.size());
  const int cols = static_cast<int>(grid[0].size());

  // dp[c1][c2]: max cherries collected up to current row with robot1 at column
  // c1 and robot2 at column c2.
  std::vector<std::vector<int>> dp(cols, std::vector<int>(cols, -1));
  dp[0][cols - 1] = grid[0][0] + grid[0][cols - 1];

  for (int r = 1; r < rows; ++r) {
    std::vector<std::vector<int>> ndp(cols, std::vector<int>(cols, -1));
    for (int c1 = 0; c1 < cols; ++c1) {
      for (int c2 = 0; c2 < cols; ++c2) {
        int best = -1;
        for (int d1 = -1; d1 <= 1; ++d1) {
          int p1 = c1 + d1;
          if (p1 < 0 || p1 >= cols) continue;
          for (int d2 = -1; d2 <= 1; ++d2) {
            int p2 = c2 + d2;
            if (p2 < 0 || p2 >= cols) continue;
            if (dp[p1][p2] < 0) continue;
            best = std::max(best, dp[p1][p2]);
          }
        }
        if (best < 0) continue;
        int gain = grid[r][c1] + grid[r][c2];
        if (c1 == c2) gain = grid[r][c1];
        ndp[c1][c2] = best + gain;
      }
    }
    dp.swap(ndp);
  }

  int result = 0;
  for (int c1 = 0; c1 < cols; ++c1) {
    for (int c2 = 0; c2 < cols; ++c2) {
      result = std::max(result, dp[c1][c2]);
    }
  }
  return result;
}

}  // namespace

CherryPickupIiSolution::CherryPickupIiSolution() {
  setMetaInfo({.id = 1463,
               .title = "Cherry Pickup II",
               .url = "https://leetcode.com/problems/cherry-pickup-ii/"});
  registerStrategy(
      {.name = "3D-DP",
       .expected = "Accepted",
       .time_complexity = "O(rows * cols^2)",
       .space_complexity = "O(cols^2)",
       .tags = {"Array", "Dynamic Programming", "Matrix"}},
      cherryPickupImpl);
}

int CherryPickupIiSolution::cherryPickup(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_1463
