#include "leetcode/problems/reconstruct-a-2-row-binary-matrix.h"

namespace leetcode::problem_1253 {

static std::vector<std::vector<int>> reconstructMatrixImpl(int upper, int lower,
                                                            std::vector<int>& colsum) {
  int n = static_cast<int>(colsum.size());

  // Quick feasibility checks
  int total_sum = 0;
  int count2 = 0;
  for (int c : colsum) {
    total_sum += c;
    if (c == 2) ++count2;
  }
  if (upper + lower != total_sum) return {};
  if (upper < count2 || lower < count2) return {};

  std::vector<std::vector<int>> result(2, std::vector<int>(n, 0));

  for (int i = 0; i < n; ++i) {
    if (colsum[i] == 2) {
      result[0][i] = 1;
      result[1][i] = 1;
      --upper;
      --lower;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (colsum[i] == 1) {
      if (upper > 0) {
        result[0][i] = 1;
        --upper;
      } else {
        result[1][i] = 1;
        --lower;
      }
    }
  }

  return result;
}

ReconstructA2RowBinaryMatrixSolution::ReconstructA2RowBinaryMatrixSolution() {
  setMetaInfo({.id = 1253,
               .title = "Reconstruct a 2-Row Binary Matrix",
               .url = "https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/"});
  registerStrategy(
      {.name = "greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy", "Matrix"}},
      reconstructMatrixImpl);
  setDefaultStrategy();
}

}  // namespace leetcode::problem_1253
