#include "leetcode/problems/modify-the-matrix.h"

namespace leetcode {
namespace problem_3033 {

namespace {

std::vector<std::vector<int>> modifiedMatrixImpl(std::vector<std::vector<int>>& matrix) {
  int m = static_cast<int>(matrix.size());
  int n = static_cast<int>(matrix[0].size());

  std::vector<int> colMax(n, -1);
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      colMax[j] = std::max(colMax[j], matrix[i][j]);
    }
  }

  std::vector<std::vector<int>> answer = matrix;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (answer[i][j] == -1) {
        answer[i][j] = colMax[j];
      }
    }
  }
  return answer;
}

}  // namespace

ModifyTheMatrixSolution::ModifyTheMatrixSolution() {
  setMetaInfo({.id = 3033,
               .title = "Modify the Matrix",
               .url = "https://leetcode.com/problems/modify-the-matrix/"});
  registerStrategy(
      {"ColumnMaxReplace", "Accepted", "O(m*n)", "O(n)", {"Array", "Matrix"}},
      modifiedMatrixImpl);
}

std::vector<std::vector<int>> ModifyTheMatrixSolution::modifiedMatrix(
    std::vector<std::vector<int>>& matrix) {
  return getSolution()(matrix);
}

}  // namespace problem_3033
}  // namespace leetcode
