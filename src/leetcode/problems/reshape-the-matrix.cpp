#include "leetcode/problems/reshape-the-matrix.h"

namespace leetcode::problem_566 {

static std::vector<std::vector<int>> matrixReshapeImpl(std::vector<std::vector<int>>& mat, int r, int c) {
  int m = static_cast<int>(mat.size());
  int n = static_cast<int>(mat[0].size());
  if (m * n != r * c) {
    return mat;
  }
  std::vector<std::vector<int>> result(r, std::vector<int>(c));
  for (int k = 0; k < m * n; ++k) {
    result[k / c][k % c] = mat[k / n][k % n];
  }
  return result;
}

ReshapeTheMatrixSolution::ReshapeTheMatrixSolution() {
  setMetaInfo({.id = 566, .title = "Reshape the Matrix", .url = "https://leetcode.com/problems/reshape-the-matrix/"});
  registerStrategy({.name = "FlatIteration",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n)",
                    .space_complexity = "O(r*c)",
                    .tags = {"Array", "Matrix", "Simulation"}},
                   matrixReshapeImpl);
}

std::vector<std::vector<int>> ReshapeTheMatrixSolution::matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
  return getSolution()(mat, r, c);
}

}  // namespace leetcode::problem_566
