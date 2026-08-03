#include "leetcode/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i.h"

namespace leetcode {
namespace problem_3239 {
namespace {

int minFlipsImpl(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  int rowFlips = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n / 2; ++j) {
      if (grid[i][j] != grid[i][n - 1 - j]) {
        ++rowFlips;
      }
    }
  }

  int colFlips = 0;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m / 2; ++i) {
      if (grid[i][j] != grid[m - 1 - i][j]) {
        ++colFlips;
      }
    }
  }

  return rowFlips < colFlips ? rowFlips : colFlips;
}

}  // namespace

MinimumNumberOfFlipsToMakeBinaryGridPalindromicISolution::
    MinimumNumberOfFlipsToMakeBinaryGridPalindromicISolution() {
  setMetaInfo({.id = 3239,
               .title = "Minimum Number of Flips to Make Binary Grid "
                        "Palindromic I",
               .url = "https://leetcode.com/problems/minimum-number-of-flips-"
                      "to-make-binary-grid-palindromic-i/"});

  registerStrategy(
      {.name = "row_col_compare",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Matrix"}},
      minFlipsImpl);
}

int MinimumNumberOfFlipsToMakeBinaryGridPalindromicISolution::minFlips(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_3239
}  // namespace leetcode
