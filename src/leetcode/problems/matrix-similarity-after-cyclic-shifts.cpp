#include "leetcode/problems/matrix-similarity-after-cyclic-shifts.h"

namespace leetcode::problem_2946 {

namespace {

bool areSimilarImpl(std::vector<std::vector<int>>& mat, int k) {
  int m = static_cast<int>(mat.size());
  int n = static_cast<int>(mat[0].size());
  int shift = k % n;
  if (shift == 0) {
    return true;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int src;
      if (i % 2 == 0) {
        // even row: shift left by shift
        src = (j + shift) % n;
      } else {
        // odd row: shift right by shift
        src = (j - shift + n) % n;
      }
      if (mat[i][j] != mat[i][src]) {
        return false;
      }
    }
  }
  return true;
}

}  // namespace

bool MatrixSimilarityAfterCyclicShiftsSolution::areSimilar(
    std::vector<std::vector<int>>& mat, int k) {
  return getSolution()(mat, k);
}

MatrixSimilarityAfterCyclicShiftsSolution::MatrixSimilarityAfterCyclicShiftsSolution() {
  setMetaInfo({.id = 2946,
               .title = "Matrix Similarity After Cyclic Shifts",
               .url = "https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/"});
  registerStrategy(
      {.name = "simulate-shift-comparison",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Matrix", "Simulation"}},
      areSimilarImpl);
}

}  // namespace leetcode::problem_2946
