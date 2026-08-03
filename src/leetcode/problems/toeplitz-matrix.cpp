#include <vector>

#include "leetcode/problems/toeplitz-matrix.h"

namespace leetcode::problem_766 {

bool isToeplitzMatrixImpl(std::vector<std::vector<int>>& matrix) {
  const int m = static_cast<int>(matrix.size());
  const int n = static_cast<int>(matrix[0].size());
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      if (matrix[i][j] != matrix[i - 1][j - 1]) {
        return false;
      }
    }
  }
  return true;
}

ToeplitzMatrixSolution::ToeplitzMatrixSolution() {
  setMetaInfo({
      .id = 766,
      .title = "Toeplitz Matrix",
      .url = "https://leetcode.com/problems/toeplitz-matrix/",
  });
  registerStrategy(
      {
          .name = "diagonal-check",
          .expected = "Accepted",
          .time_complexity = "O(m*n)",
          .space_complexity = "O(1)",
          .tags = {"Array", "Matrix"},
      },
      isToeplitzMatrixImpl);
}

bool ToeplitzMatrixSolution::isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
  return getSolution()(matrix);
}

}  // namespace leetcode::problem_766
