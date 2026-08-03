#include "leetcode/problems/largest-local-values-in-a-matrix.h"

namespace leetcode::problem_2373 {

namespace {

std::vector<std::vector<int>> largestLocalImpl(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  const int m = n - 2;
  std::vector<std::vector<int>> result(m, std::vector<int>(m, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      int maxVal = 0;
      for (int r = i; r < i + 3; ++r) {
        for (int c = j; c < j + 3; ++c) {
          maxVal = std::max(maxVal, grid[r][c]);
        }
      }
      result[i][j] = maxVal;
    }
  }
  return result;
}

}  // namespace

LargestLocalValuesInAMatrixSolution::LargestLocalValuesInAMatrixSolution() {
  setMetaInfo({.id = 2373,
               .title = "Largest Local Values in a Matrix",
               .url = "https://leetcode.com/problems/largest-local-values-in-a-matrix/"});
  registerStrategy({.name = "brute_force",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Matrix"}},
                   largestLocalImpl);
}

std::vector<std::vector<int>> LargestLocalValuesInAMatrixSolution::largestLocal(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_2373
