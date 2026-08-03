#include "leetcode/problems/maximum-non-negative-product-in-a-matrix.h"

#include <algorithm>

namespace leetcode {
namespace problem_1594 {

namespace {
constexpr int kMod = 1000000007;
}  // namespace

static int solution1(vector<vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  // Track both the maximum and minimum product reachable at each cell.
  // Keeping the minimum matters because a large negative product can turn
  // into a large positive one after multiplying by a negative cell value.
  vector<vector<long long>> maxProd(m, vector<long long>(n, 0));
  vector<vector<long long>> minProd(m, vector<long long>(n, 0));

  maxProd[0][0] = minProd[0][0] = grid[0][0];
  for (int i = 1; i < m; ++i) {
    long long v = static_cast<long long>(grid[i][0]) * maxProd[i - 1][0];
    maxProd[i][0] = minProd[i][0] = v;
  }
  for (int j = 1; j < n; ++j) {
    long long v = static_cast<long long>(grid[0][j]) * maxProd[0][j - 1];
    maxProd[0][j] = minProd[0][j] = v;
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      long long candidates[4] = {
          static_cast<long long>(grid[i][j]) * maxProd[i - 1][j],
          static_cast<long long>(grid[i][j]) * minProd[i - 1][j],
          static_cast<long long>(grid[i][j]) * maxProd[i][j - 1],
          static_cast<long long>(grid[i][j]) * minProd[i][j - 1]};
      maxProd[i][j] = *std::max_element(candidates, candidates + 4);
      minProd[i][j] = *std::min_element(candidates, candidates + 4);
    }
  }

  if (maxProd[m - 1][n - 1] < 0) {
    return -1;
  }
  return static_cast<int>(maxProd[m - 1][n - 1] % kMod);
}

MaximumNonNegativeProductInAMatrixSolution::MaximumNonNegativeProductInAMatrixSolution() {
  setMetaInfo({
      .id = 1594,
      .title = "Maximum Non Negative Product in a Matrix",
      .url = "https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix"
  });
  registerStrategy({.name = "Dynamic Programming",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n)",
                    .space_complexity = "O(m*n)",
                    .tags = {"DP", "Matrix"}},
                   solution1);
}

int MaximumNonNegativeProductInAMatrixSolution::maxProductPath(vector<vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_1594
}  // namespace leetcode
