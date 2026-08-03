#include <vector>

#include "leetcode/problems/difference-between-ones-and-zeros-in-row-and-column.h"

namespace leetcode {
namespace problem_2482 {

namespace {

std::vector<std::vector<int>> onesMinusZerosImpl(
    std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());
  std::vector<int> onesRow(m, 0);
  std::vector<int> onesCol(n, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        ++onesRow[i];
        ++onesCol[j];
      }
    }
  }
  std::vector<std::vector<int>> diff(m, std::vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      const int zerosRow = n - onesRow[i];
      const int zerosCol = m - onesCol[j];
      diff[i][j] =
          onesRow[i] + onesCol[j] - zerosRow - zerosCol;
    }
  }
  return diff;
}

}  // namespace

DifferenceBetweenOnesAndZerosInRowAndColumnSolution::
    DifferenceBetweenOnesAndZerosInRowAndColumnSolution() {
  setMetaInfo({.id = 2482,
               .title = "Difference Between Ones and Zeros in Row and Column",
               .url = "https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/"});
  registerStrategy({.name = "row_col_counts",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n)",
                    .space_complexity = "O(m+n)",
                    .tags = {"Array", "Matrix", "Simulation"}},
                   onesMinusZerosImpl);
}

std::vector<std::vector<int>>
DifferenceBetweenOnesAndZerosInRowAndColumnSolution::onesMinusZeros(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_2482
}  // namespace leetcode
