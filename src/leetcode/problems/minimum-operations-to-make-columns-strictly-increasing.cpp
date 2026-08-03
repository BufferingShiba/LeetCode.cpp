#include "leetcode/problems/minimum-operations-to-make-columns-strictly-increasing.h"

namespace leetcode::problem_3402 {

namespace {

int minimumOperationsImpl(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());
  int ops = 0;
  for (int j = 0; j < n; ++j) {
    for (int i = 1; i < m; ++i) {
      if (grid[i][j] <= grid[i - 1][j]) {
        ops += grid[i - 1][j] + 1 - grid[i][j];
        grid[i][j] = grid[i - 1][j] + 1;
      }
    }
  }
  return ops;
}

}  // namespace

MinimumOperationsToMakeColumnsStrictlyIncreasingSolution::
    MinimumOperationsToMakeColumnsStrictlyIncreasingSolution() {
  setMetaInfo({.id = 3402,
               .title = "Minimum Operations to Make Columns Strictly Increasing",
               .url = "https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy", "Matrix"}},
      minimumOperationsImpl);
}

int
MinimumOperationsToMakeColumnsStrictlyIncreasingSolution::minimumOperations(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_3402
