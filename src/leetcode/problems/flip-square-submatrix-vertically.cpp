#include "leetcode/problems/flip-square-submatrix-vertically.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3643 {
namespace {

std::vector<std::vector<int>> reverseSubmatrixImpl(
    std::vector<std::vector<int>>& grid, int x, int y, int k) {
  for (int col = y; col < y + k; ++col) {
    int top = x;
    int bottom = x + k - 1;
    while (top < bottom) {
      std::swap(grid[top][col], grid[bottom][col]);
      ++top;
      --bottom;
    }
  }
  return grid;
}

}  // namespace

FlipSquareSubmatrixVerticallySolution::FlipSquareSubmatrixVerticallySolution() {
  setMetaInfo({.id = 3643,
               .title = "Flip Square Submatrix Vertically",
               .url = "https://leetcode.com/problems/flip-square-submatrix-vertically/"});
  registerStrategy({.name = "Column-by-Column Vertically Flip",
                    .expected = "Accepted",
                    .time_complexity = "O(k^2)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Two Pointers", "Matrix"}},
                   reverseSubmatrixImpl);
}

std::vector<std::vector<int>>
FlipSquareSubmatrixVerticallySolution::reverseSubmatrix(
    std::vector<std::vector<int>>& grid, int x, int y, int k) {
  return getSolution()(grid, x, y, k);
}

}  // namespace problem_3643
}  // namespace leetcode
