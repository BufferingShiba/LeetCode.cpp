#include "leetcode/problems/sort-the-matrix-diagonally.h"

namespace leetcode {
namespace problem_1329 {

static std::vector<std::vector<int>> diagonalSortImpl(std::vector<std::vector<int>> mat) {
  const int m = static_cast<int>(mat.size());
  const int n = static_cast<int>(mat[0].size());

  // Each diagonal is identified by d = row - col, ranging from -(n-1) to (m-1).
  // For a fixed d, cells are (r, c) with c - r == -d ... collect and sort.
  for (int d = -(n - 1); d <= m - 1; ++d) {
    std::vector<int> diag;
    int r = (d < 0) ? 0 : d;
    int c = (d < 0) ? -d : 0;
    for (; r < m && c < n; ++r, ++c) {
      diag.push_back(mat[r][c]);
    }
    std::sort(diag.begin(), diag.end());
    r = (d < 0) ? 0 : d;
    c = (d < 0) ? -d : 0;
    for (std::size_t i = 0; i < diag.size(); ++i, ++r, ++c) {
      mat[r][c] = diag[i];
    }
  }
  return mat;
}

SortTheMatrixDiagonallySolution::SortTheMatrixDiagonallySolution() {
  setMetaInfo({
      .id = 1329,
      .title = "Sort the Matrix Diagonally",
      .url = "https://leetcode.com/problems/sort-the-matrix-diagonally"
  });
  registerStrategy({.name = "Diagonal Sort",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n*log(min(m,n)))",
                    .space_complexity = "O(min(m,n))",
                    .tags = {"Sorting", "Array"},
                    .notes = "For each diagonal collect, sort and write back."},
                   diagonalSortImpl);
}

std::vector<std::vector<int>> SortTheMatrixDiagonallySolution::diagonalSort(
    std::vector<std::vector<int>>& mat) {
  return getSolution()(mat);
}

}  // namespace problem_1329
}  // namespace leetcode
