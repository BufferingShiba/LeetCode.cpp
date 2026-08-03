#include "leetcode/problems/minimum-number-of-operations-to-satisfy-conditions.h"
#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode::problem_3122 {

namespace {

int minimumOperationsImpl(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  std::vector<std::vector<int>> cost(n, std::vector<int>(10, 0));
  for (int col = 0; col < n; ++col) {
    std::vector<int> cnt(10, 0);
    for (int row = 0; row < m; ++row) {
      ++cnt[grid[row][col]];
    }
    for (int v = 0; v < 10; ++v) {
      cost[col][v] = m - cnt[v];
    }
  }

  std::vector<int> dp(10, 0);
  for (int col = 0; col < n; ++col) {
    std::vector<int> next(10, INT_MAX);
    for (int v = 0; v < 10; ++v) {
      int best = INT_MAX;
      for (int prev = 0; prev < 10; ++prev) {
        if (prev == v) continue;
        best = std::min(best, dp[prev]);
      }
      next[v] = cost[col][v] + best;
    }
    dp = std::move(next);
  }

  return *std::min_element(dp.begin(), dp.end());
}

}  // namespace

MinimumNumberOfOperationsToSatisfyConditionsSolution::
    MinimumNumberOfOperationsToSatisfyConditionsSolution() {
  setMetaInfo({.id = 3122,
               .title = "Minimum Number of Operations to Satisfy Conditions",
               .url = "https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/"});
  registerStrategy(
      {.name = "dp-by-column",
       .expected = "Accepted",
       .time_complexity = "O(m*n + n*10*10)",
       .space_complexity = "O(n*10)",
       .tags = {"Array", "Dynamic Programming", "Matrix"}},
      minimumOperationsImpl);
}

int MinimumNumberOfOperationsToSatisfyConditionsSolution::minimumOperations(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_3122
