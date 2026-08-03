#include "leetcode/problems/select-cells-in-grid-with-maximum-score.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3276 {

namespace {

int maxScoreImpl(std::vector<std::vector<int>>& grid) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());

  // Find the maximum value in the grid
  int max_val = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      max_val = std::max(max_val, grid[i][j]);
    }
  }

  // row_mask[v] = bitmask of rows that contain value v
  std::vector<int> row_mask(max_val + 1, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      row_mask[grid[i][j]] |= (1 << i);
    }
  }

  int total_masks = 1 << m;
  std::vector<int> dp(total_masks, -1);
  dp[0] = 0;

  for (int v = 1; v <= max_val; ++v) {
    int mask_v = row_mask[v];
    if (mask_v == 0) continue;

    std::vector<int> new_dp = dp;  // copy: skip value v
    for (int mask = 0; mask < total_masks; ++mask) {
      if (dp[mask] < 0) continue;
      // Try to assign value v to each row that contains it
      for (int i = 0; i < m; ++i) {
        if ((mask_v >> i) & 1) {
          if (!(mask & (1 << i))) {
            int new_mask = mask | (1 << i);
            new_dp[new_mask] = std::max(new_dp[new_mask], dp[mask] + v);
          }
        }
      }
    }
    dp = std::move(new_dp);
  }

  int ans = 0;
  for (int mask = 0; mask < total_masks; ++mask) {
    ans = std::max(ans, dp[mask]);
  }
  return ans;
}

}  // anonymous namespace

SelectCellsInGridWithMaximumScoreSolution::SelectCellsInGridWithMaximumScoreSolution() {
  setMetaInfo({.id = 3276,
               .title = "Select Cells in Grid With Maximum Score",
               .url = "https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/"});
  registerStrategy(
      {.name = "DP over values with bitmask rows",
       .expected = "Accepted",
       .time_complexity = "O(V * 2^m * m)",
       .space_complexity = "O(2^m + V)",
       .tags = {"Dynamic Programming", "Bit Manipulation", "Matrix", "Bitmask"}},
      maxScoreImpl);
}

int SelectCellsInGridWithMaximumScoreSolution::maxScore(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_3276
}  // namespace leetcode
