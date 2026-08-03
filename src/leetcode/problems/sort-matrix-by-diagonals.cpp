#include "leetcode/problems/sort-matrix-by-diagonals.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3446 {

namespace {

std::vector<std::vector<int>> sortMatrixImpl(
    std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  // Bottom-left triangle diagonals (including main diagonal, starting at
  // (i, 0) for i = 0..n-1) should be sorted in non-increasing order.
  for (int start = 0; start < n; ++start) {
    std::vector<int> diag;
    int r = start, c = 0;
    while (r < n && c < n) {
      diag.push_back(grid[r][c]);
      ++r;
      ++c;
    }
    std::sort(diag.begin(), diag.end(), std::greater<int>());
    r = start;
    c = 0;
    for (int v : diag) {
      grid[r][c] = v;
      ++r;
      ++c;
    }
  }
  // Top-right triangle diagonals (starting at (0, j) for j = 1..n-1)
  // should be sorted in non-decreasing order.
  for (int start = 1; start < n; ++start) {
    std::vector<int> diag;
    int r = 0, c = start;
    while (r < n && c < n) {
      diag.push_back(grid[r][c]);
      ++r;
      ++c;
    }
    std::sort(diag.begin(), diag.end());
    r = 0;
    c = start;
    for (int v : diag) {
      grid[r][c] = v;
      ++r;
      ++c;
    }
  }
  return grid;
}

}  // namespace

SortMatrixByDiagonalsSolution::SortMatrixByDiagonalsSolution() {
  setMetaInfo({.id = 3446,
               .title = "Sort Matrix by Diagonals",
               .url =
                   "https://leetcode.com/problems/sort-matrix-by-diagonals/"});
  registerStrategy(
      {.name = "diagonal collect sort",
       .expected = "Accepted",
       .time_complexity = "O(n^2 log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Sorting", "Matrix"}},
      sortMatrixImpl);
}

std::vector<std::vector<int>> SortMatrixByDiagonalsSolution::sortMatrix(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_3446
}  // namespace leetcode
