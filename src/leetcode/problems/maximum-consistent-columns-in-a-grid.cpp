#include "leetcode/problems/maximum-consistent-columns-in-a-grid.h"

namespace leetcode {
namespace problem_3989 {

namespace {

int maxConsistentColumnsImpl(std::vector<std::vector<int>>& grid, int limit) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  // dp[j] = length of longest valid column subsequence ending at column j.
  std::vector<int> dp(n, 1);
  int best = 1;

  for (int j = 1; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      bool compatible = true;
      for (int r = 0; r < m; ++r) {
        const long long diff =
            static_cast<long long>(grid[r][j]) - static_cast<long long>(grid[r][i]);
        if (diff < 0 ? -diff > limit : diff > limit) {
          compatible = false;
          break;
        }
      }
      if (compatible) {
        dp[j] = std::max(dp[j], dp[i] + 1);
      }
    }
    best = std::max(best, dp[j]);
  }

  return best;
}

}  // namespace

MaximumConsistentColumnsInAGridSolution::MaximumConsistentColumnsInAGridSolution() {
  using Metadata = SolutionBase<Func>::StrategyMetadata;
  setMetaInfo({.id = 3989,
               .title = "Maximum Consistent Columns in a Grid",
               .url = "https://leetcode.com/problems/maximum-consistent-columns-in-a-grid/"});
  registerStrategy(
      Metadata{.name = "LongestValidSubsequenceDP",
               .expected = "Accepted",
               .time_complexity = "O(n^2 * m)",
               .space_complexity = "O(n)",
               .tags = {"Dynamic Programming", "Array"}},
      maxConsistentColumnsImpl);
}

int MaximumConsistentColumnsInAGridSolution::maxConsistentColumns(
    std::vector<std::vector<int>>& grid, int limit) {
  return getSolution()(grid, limit);
}

}  // namespace problem_3989
}  // namespace leetcode
