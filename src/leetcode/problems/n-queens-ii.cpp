#include "leetcode/problems/n-queens-ii.h"

#include <vector>

namespace leetcode {
namespace problem_52 {

namespace {

int totalNQueensImpl(int n) {
  std::vector<bool> cols(n, false);
  std::vector<bool> diag1(2 * n - 1, false);  // row + col
  std::vector<bool> diag2(2 * n - 1, false);  // row - col + n - 1

  int count = 0;

  // Lambda for backtracking; row is the current row to place a queen.
  auto backtrack = [&](auto&& self, int row) -> void {
    if (row == n) {
      ++count;
      return;
    }
    for (int col = 0; col < n; ++col) {
      int d1 = row + col;
      int d2 = row - col + n - 1;
      if (cols[col] || diag1[d1] || diag2[d2]) continue;
      cols[col] = diag1[d1] = diag2[d2] = true;
      self(self, row + 1);
      cols[col] = diag1[d1] = diag2[d2] = false;
    }
  };

  backtrack(backtrack, 0);
  return count;
}

}  // namespace

NQueensIiSolution::NQueensIiSolution() {
  setMetaInfo({.id = 52, .title = "N-Queens II", .url = "https://leetcode.com/problems/n-queens-ii/"});
  registerStrategy(
      {.name = "Backtracking",
       .expected = "Accepted",
       .time_complexity = "O(N!)",
       .space_complexity = "O(N)",
       .tags = {"Backtracking"}},
      totalNQueensImpl);
}

}  // namespace problem_52
}  // namespace leetcode
