#include "leetcode/problems/check-if-grid-satisfies-conditions.h"

namespace leetcode {
namespace problem_3142 {

namespace {

bool satisfiesConditions(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + 1 < m && grid[i][j] != grid[i + 1][j]) {
        return false;
      }
      if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
        return false;
      }
    }
  }
  return true;
}

}  // namespace

CheckIfGridSatisfiesConditionsSolution::CheckIfGridSatisfiesConditionsSolution() {
  setMetaInfo({.id = 3142,
               .title = "Check if Grid Satisfies Conditions",
               .url = "https://leetcode.com/problems/check-if-grid-satisfies-conditions/"});
  registerStrategy({"simple_grid_scan",
                     "Accepted",
                     "O(m*n)",
                     "O(1)",
                     {"Array", "Matrix"}},
                    satisfiesConditions);
}

}  // namespace problem_3142
}  // namespace leetcode
