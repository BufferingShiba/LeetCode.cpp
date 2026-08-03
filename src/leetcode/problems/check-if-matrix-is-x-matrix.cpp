#include "leetcode/problems/check-if-matrix-is-x-matrix.h"

namespace leetcode {
namespace problem_2319 {

namespace {

bool checkXMatrixImpl(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      const bool onDiagonal = (i == j) || (i + j == n - 1);
      if (onDiagonal) {
        if (grid[i][j] == 0) return false;
      } else {
        if (grid[i][j] != 0) return false;
      }
    }
  }
  return true;
}

}  // namespace

CheckIfMatrixIsXMatrixSolution::CheckIfMatrixIsXMatrixSolution() {
  setMetaInfo({2319, "Check if Matrix Is X-Matrix",
               "https://leetcode.com/problems/check-if-matrix-is-x-matrix/"});
  registerStrategy({"linear-scan", "Accepted", "O(n^2)", "O(1)", {"Array", "Matrix"},
                     "Single pass checking each cell against its diagonal membership."},
                   checkXMatrixImpl);
}

bool CheckIfMatrixIsXMatrixSolution::checkXMatrix(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_2319
}  // namespace leetcode
