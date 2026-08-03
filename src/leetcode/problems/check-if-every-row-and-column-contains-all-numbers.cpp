#include "leetcode/problems/check-if-every-row-and-column-contains-all-numbers.h"

#include <vector>

namespace leetcode {
namespace problem_2133 {

namespace {

bool checkValidImpl(std::vector<std::vector<int>>& matrix) {
  const int n = static_cast<int>(matrix.size());

  // Check rows.
  for (int r = 0; r < n; ++r) {
    std::vector<bool> seen(n + 1, false);
    for (int c = 0; c < n; ++c) {
      const int val = matrix[r][c];
      if (val < 1 || val > n || seen[val]) return false;
      seen[val] = true;
    }
  }

  // Check columns.
  for (int c = 0; c < n; ++c) {
    std::vector<bool> seen(n + 1, false);
    for (int r = 0; r < n; ++r) {
      const int val = matrix[r][c];
      if (val < 1 || val > n || seen[val]) return false;
      seen[val] = true;
    }
  }

  return true;
}

}  // namespace

CheckIfEveryRowAndColumnContainsAllNumbersSolution::
    CheckIfEveryRowAndColumnContainsAllNumbersSolution() {
  setMetaInfo({.id = 2133,
               .title = "Check if Every Row and Column Contains All Numbers",
               .url = "https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/"});

  registerStrategy(
      {"RowColumnScan", "Accepted", "O(n^2)", "O(n)",
       {"Array", "Hash Table", "Matrix"},
       "For each row and each column, use a boolean marker array to ensure "
       "every value in 1..n appears exactly once."},
      checkValidImpl);
}

bool CheckIfEveryRowAndColumnContainsAllNumbersSolution::checkValid(
    std::vector<std::vector<int>>& matrix) {
  return getSolution()(matrix);
}

}  // namespace problem_2133
}  // namespace leetcode
