#include "leetcode/problems/minimum-path-cost-in-a-grid.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode::problem_2304 {

static int minPathCostImpl(std::vector<std::vector<int>>& grid,
                           std::vector<std::vector<int>>& moveCost) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());

  std::vector<std::vector<int>> dp(m, std::vector<int>(n, INT_MAX));

  for (int c = 0; c < n; ++c) {
    dp[0][c] = grid[0][c];
  }

  for (int r = 1; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      int best = INT_MAX;
      for (int prev_c = 0; prev_c < n; ++prev_c) {
        int val = grid[r - 1][prev_c];
        int cost = dp[r - 1][prev_c] + moveCost[val][c];
        if (cost < best) {
          best = cost;
        }
      }
      dp[r][c] = grid[r][c] + best;
    }
  }

  int ans = INT_MAX;
  for (int c = 0; c < n; ++c) {
    if (dp[m - 1][c] < ans) {
      ans = dp[m - 1][c];
    }
  }
  return ans;
}

MinimumPathCostInAGridSolution::MinimumPathCostInAGridSolution() {
  setMetaInfo({.id = 2304,
               .title = "Minimum Path Cost in a Grid",
               .url = "https://leetcode.com/problems/minimum-path-cost-in-a-grid/"});
  registerStrategy(
      {.name = "DP",
       .expected = "Accepted",
       .time_complexity = "O(m * n^2)",
       .space_complexity = "O(m * n)",
       .tags = {"Array", "Dynamic Programming", "Matrix"}},
      minPathCostImpl);
}

int MinimumPathCostInAGridSolution::minPathCost(
    std::vector<std::vector<int>>& grid,
    std::vector<std::vector<int>>& moveCost) {
  return getSolution()(grid, moveCost);
}

}  // namespace leetcode::problem_2304
