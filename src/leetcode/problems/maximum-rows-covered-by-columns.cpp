#include "leetcode/problems/maximum-rows-covered-by-columns.h"

#include <algorithm>

namespace leetcode::problem_2397 {

namespace {

// Enumerate all combinations of selecting numSelect columns out of n, using a
// bitmask. For each column mask, count rows covered: a row (bitmask over its
// 1-cells) is covered iff (rowMask & colMask) == rowMask.
int maximumRowsImpl(std::vector<std::vector<int>>& matrix, int numSelect) {
  const int m = static_cast<int>(matrix.size());
  const int n = static_cast<int>(matrix[0].size());

  std::vector<int> rowMasks(m, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == 1) {
        rowMasks[i] |= (1 << j);
      }
    }
  }

  int best = 0;
  // DFS over column selections.
  std::function<void(int, int, int)> dfs = [&](int idx, int left, int colMask) {
    if (left == 0) {
      int covered = 0;
      for (int r = 0; r < m; ++r) {
        if ((rowMasks[r] & colMask) == rowMasks[r]) {
          ++covered;
        }
      }
      best = std::max(best, covered);
      return;
    }
    // idx: current candidate column index, need to place `left` more selections
    // among columns [idx, n).
    for (int j = idx; j <= n - left; ++j) {
      dfs(j + 1, left - 1, colMask | (1 << j));
    }
  };

  dfs(0, numSelect, 0);
  return best;
}

}  // namespace

int MaximumRowsCoveredByColumnsSolution::maximumRows(
    std::vector<std::vector<int>>& matrix, int numSelect) {
  return getSolution()(matrix, numSelect);
}

MaximumRowsCoveredByColumnsSolution::MaximumRowsCoveredByColumnsSolution() {
  setMetaInfo({.id = 2397,
               .title = "Maximum Rows Covered by Columns",
               .url = "https://leetcode.com/problems/maximum-rows-covered-by-columns/"});
  registerStrategy(
      {.name = "bitset-enumeration",
       .expected = "Accepted",
       .time_complexity = "O(C(n,k) * m)",
       .space_complexity = "O(m)",
       .tags = {"Array", "Backtracking", "Bit Manipulation", "Matrix",
                "Enumeration"}},
      maximumRowsImpl);
}

}  // namespace leetcode::problem_2397
