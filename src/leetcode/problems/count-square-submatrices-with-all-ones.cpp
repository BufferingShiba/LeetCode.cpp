#include "leetcode/problems/count-square-submatrices-with-all-ones.h"

namespace leetcode {
namespace problem_1277 {

namespace {

int countSquaresImpl(std::vector<std::vector<int>>& matrix) {
  const int m = static_cast<int>(matrix.size());
  const int n = static_cast<int>(matrix[0].size());
  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
  int total = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == 1) {
        if (i == 0 || j == 0) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = 1 + std::min(dp[i - 1][j],
                                  std::min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
        total += dp[i][j];
      }
    }
  }
  return total;
}

}  // namespace

CountSquareSubmatricesWithAllOnesSolution::
    CountSquareSubmatricesWithAllOnesSolution() {
  this->setMetaInfo({.id = 1277,
                     .title = "Count Square Submatrices with All Ones",
                     .url = "https://leetcode.com/problems/count-square-submatrices-with-all-ones/"});
  this->registerStrategy(
      {.name = "dp-bottom-right",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"Array", "Dynamic Programming", "Matrix"}},
      countSquaresImpl);
}

int CountSquareSubmatricesWithAllOnesSolution::countSquares(
    std::vector<std::vector<int>>& matrix) {
  return getSolution()(matrix);
}

}  // namespace problem_1277
}  // namespace leetcode
