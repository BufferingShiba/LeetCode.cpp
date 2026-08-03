#include "leetcode/problems/increment-submatrices-by-one.h"

#include <vector>

namespace leetcode {
namespace problem_2536 {

namespace {

std::vector<std::vector<int>> rangeAddQueriesImpl(int n,
                                                   std::vector<std::vector<int>>& queries) {
  // 2D difference array of size (n+1) x (n+1), initialized to 0
  std::vector<std::vector<int>> diff(n + 1, std::vector<int>(n + 1, 0));

  for (const auto& q : queries) {
    int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
    diff[r1][c1] += 1;
    diff[r1][c2 + 1] -= 1;
    diff[r2 + 1][c1] -= 1;
    diff[r2 + 1][c2 + 1] += 1;
  }

  // Compute 2D prefix sum to reconstruct the final matrix
  std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int val = diff[i][j];
      if (i > 0) val += result[i - 1][j];
      if (j > 0) val += result[i][j - 1];
      if (i > 0 && j > 0) val -= result[i - 1][j - 1];
      result[i][j] = val;
    }
  }

  return result;
}

}  // namespace

IncrementSubmatricesByOneSolution::IncrementSubmatricesByOneSolution() {
  setMetaInfo({.id = 2536,
               .title = "Increment Submatrices by One",
               .url = "https://leetcode.com/problems/increment-submatrices-by-one/"});

  registerStrategy({.name = "2D Difference Array",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2 + q)",
                    .space_complexity = "O(n^2)",
                    .tags = {"Array", "Matrix", "Prefix Sum"}},
                   rangeAddQueriesImpl);
}

}  // namespace problem_2536
}  // namespace leetcode
