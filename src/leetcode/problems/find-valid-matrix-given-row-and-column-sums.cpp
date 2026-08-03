#include "leetcode/problems/find-valid-matrix-given-row-and-column-sums.h"

namespace leetcode {
namespace problem_1605 {

namespace {

std::vector<std::vector<int>> restoreMatrixImpl(std::vector<int>& rowSum,
                                                std::vector<int>& colSum) {
  const int m = static_cast<int>(rowSum.size());
  const int n = static_cast<int>(colSum.size());
  std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));

  int i = 0;
  int j = 0;
  while (i < m && j < n) {
    int value = std::min(rowSum[i], colSum[j]);
    matrix[i][j] = value;
    rowSum[i] -= value;
    colSum[j] -= value;
    if (rowSum[i] == 0) ++i;
    if (colSum[j] == 0) ++j;
  }
  return matrix;
}

}  // namespace

FindValidMatrixGivenRowAndColumnSumsSolution::FindValidMatrixGivenRowAndColumnSumsSolution() {
  setMetaInfo({.id = 1605,
               .title = "Find Valid Matrix Given Row and Column Sums",
               .url = "https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/"});
  registerStrategy({.name = "greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n)",
                    .space_complexity = "O(m*n)",
                    .tags = {"Array", "Greedy", "Matrix"}},
                   restoreMatrixImpl);
}

std::vector<std::vector<int>>
FindValidMatrixGivenRowAndColumnSumsSolution::restoreMatrix(
    std::vector<int>& rowSum, std::vector<int>& colSum) {
  return getSolution()(rowSum, colSum);
}

}  // namespace problem_1605
}  // namespace leetcode
