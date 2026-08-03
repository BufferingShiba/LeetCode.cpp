#include "leetcode/problems/range-sum-query-2d-immutable.h"

namespace leetcode {
namespace problem_304 {

NumMatrix::NumMatrix(const std::vector<std::vector<int>>& matrix) {
  int m = static_cast<int>(matrix.size());
  int n = static_cast<int>(matrix[0].size());
  pref_.assign(m + 1, std::vector<int>(n + 1, 0));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      pref_[i][j] = matrix[i - 1][j - 1] + pref_[i - 1][j] +
                    pref_[i][j - 1] - pref_[i - 1][j - 1];
    }
  }
}

int NumMatrix::sumRegion(int row1, int col1, int row2, int col2) {
  return pref_[row2 + 1][col2 + 1] - pref_[row1][col2 + 1] -
         pref_[row2 + 1][col1] + pref_[row1][col1];
}

}  // namespace problem_304
}  // namespace leetcode
