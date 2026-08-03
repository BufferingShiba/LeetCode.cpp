#include "leetcode/problems/maximal-square.h"

#include <algorithm>

namespace leetcode {
namespace problem_221 {

namespace {

int maximalSquareImpl(std::vector<std::vector<char>>& matrix) {
  const int m = static_cast<int>(matrix.size());
  const int n = static_cast<int>(matrix[0].size());

  std::vector<int> dp(n, 0);      // current row
  std::vector<int> prev(n, 0);    // previous row
  int maxSide = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == '1') {
        if (i == 0 || j == 0) {
          dp[j] = 1;
        } else {
          int up = prev[j];
          int left = (j > 0) ? dp[j - 1] : 0;
          int diag = prev[j - 1];
          dp[j] = std::min({up, left, diag}) + 1;
        }
      } else {
        dp[j] = 0;
      }
      maxSide = std::max(maxSide, dp[j]);
    }
    std::swap(dp, prev);
  }

  return maxSide * maxSide;
}

}  // namespace

MaximalSquareSolution::MaximalSquareSolution() {
  setMetaInfo({.id = 221,
               .title = "Maximal Square",
               .url = "https://leetcode.com/problems/maximal-square/"});
  SolutionBase<Func>::StrategyMetadata meta;
  meta.name = "dynamic-programming";
  meta.expected = "Accepted";
  meta.time_complexity = "O(m*n)";
  meta.space_complexity = "O(n)";
  meta.tags = {"Array", "Dynamic Programming", "Matrix"};
  registerStrategy(meta, maximalSquareImpl);
}

int MaximalSquareSolution::maximalSquare(std::vector<std::vector<char>>& matrix) {
  return getSolution()(matrix);
}

}  // namespace problem_221
}  // namespace leetcode
