#include "leetcode/problems/cells-with-odd-values-in-a-matrix.h"

namespace leetcode {
namespace problem_1252 {
namespace {

int oddCellsImpl(int m, int n, std::vector<std::vector<int>>& indices) {
  std::vector<int> rowCounts(m, 0);
  std::vector<int> colCounts(n, 0);
  for (const auto& idx : indices) {
    ++rowCounts[idx[0]];
    ++colCounts[idx[1]];
  }

  int oddRows = 0, oddCols = 0;
  for (int x : rowCounts) {
    if (x % 2 == 1) ++oddRows;
  }
  for (int x : colCounts) {
    if (x % 2 == 1) ++oddCols;
  }

  // odd cells = oddRows * evenCols + evenRows * oddCols
  return oddRows * (n - oddCols) + (m - oddRows) * oddCols;
}

}  // namespace

CellsWithOddValuesInAMatrixSolution::CellsWithOddValuesInAMatrixSolution() {
  setMetaInfo({.id = 1252,
               .title = "Cells with Odd Values in a Matrix",
               .url = "https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/"});
  registerStrategy(
      {.name = "Counting",
       .expected = "Accepted",
       .time_complexity = "O(m + n + indices.length)",
       .space_complexity = "O(m + n)",
       .tags = {"Array", "Math"}},
      oddCellsImpl);
}

int CellsWithOddValuesInAMatrixSolution::oddCells(int m, int n,
                                                  std::vector<std::vector<int>>& indices) {
  return getSolution()(m, n, indices);
}

}  // namespace problem_1252
}  // namespace leetcode
