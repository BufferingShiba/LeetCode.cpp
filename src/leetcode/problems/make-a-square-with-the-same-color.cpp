#include "leetcode/problems/make-a-square-with-the-same-color.h"

namespace leetcode {
namespace problem_3127 {

namespace {

bool canMakeSquareImpl(std::vector<std::vector<char>>& grid) {
  for (int r = 0; r < 2; ++r) {
    for (int c = 0; c < 2; ++c) {
      int white = 0;
      for (int dr = 0; dr < 2; ++dr) {
        for (int dc = 0; dc < 2; ++dc) {
          if (grid[r + dr][c + dc] == 'W') {
            ++white;
          }
        }
      }
      if (white >= 3 || white <= 1) {
        return true;
      }
    }
  }
  return false;
}

}  // namespace

MakeASquareWithTheSameColorSolution::MakeASquareWithTheSameColorSolution() {
  setMetaInfo({.id = 3127,
               .title = "Make a Square with the Same Color",
               .url = "https://leetcode.com/problems/make-a-square-with-the-same-color/"});
  registerStrategy({.name = "enumerate-2x2",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Matrix", "Enumeration"}},
                   canMakeSquareImpl);
}

bool MakeASquareWithTheSameColorSolution::canMakeSquare(
    std::vector<std::vector<char>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_3127
}  // namespace leetcode
