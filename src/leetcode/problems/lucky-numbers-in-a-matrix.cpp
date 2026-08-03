#include "leetcode/problems/lucky-numbers-in-a-matrix.h"

#include <algorithm>

namespace leetcode {
namespace problem_1380 {

namespace {

std::vector<int> luckyNumbersImpl(std::vector<std::vector<int>>& matrix) {
  const int m = static_cast<int>(matrix.size());
  const int n = static_cast<int>(matrix[0].size());

  // maxInColumn[j] = maximum value in column j.
  std::vector<int> maxInColumn(n, 0);
  for (int j = 0; j < n; ++j) {
    maxInColumn[j] = matrix[0][j];
    for (int i = 1; i < m; ++i) {
      maxInColumn[j] = std::max(maxInColumn[j], matrix[i][j]);
    }
  }

  std::vector<int> result;
  for (int i = 0; i < m; ++i) {
    int minRow = matrix[i][0];
    int minCol = 0;
    for (int j = 1; j < n; ++j) {
      if (matrix[i][j] < minRow) {
        minRow = matrix[i][j];
        minCol = j;
      }
    }
    // minRow is minimum in row i; check if it is also max in column minCol.
    if (minRow == maxInColumn[minCol]) {
      result.push_back(minRow);
    }
  }
  return result;
}

}  // namespace

LuckyNumbersInAMatrixSolution::LuckyNumbersInAMatrixSolution() {
  setMetaInfo({1380, "Lucky Numbers in a Matrix",
               "https://leetcode.com/problems/lucky-numbers-in-a-matrix/"});
  registerStrategy(
      {.name = "RowMinColMax",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Matrix"}},
      luckyNumbersImpl);
}

}  // namespace problem_1380
}  // namespace leetcode
