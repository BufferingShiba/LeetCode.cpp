#include "leetcode/problems/determine-color-of-a-chessboard-square.h"

namespace leetcode {
namespace problem_1812 {

namespace {

bool squareIsWhiteImpl(std::string coordinates) {
  int col = coordinates[0] - 'a';
  int row = coordinates[1] - '1';
  return (col + row) % 2 == 1;
}

}  // namespace

DetermineColorOfAChessboardSquareSolution::
    DetermineColorOfAChessboardSquareSolution() {
  setMetaInfo({.id = 1812,
               .title = "Determine Color of a Chessboard Square",
               .url = "https://leetcode.com/problems/determine-color-of-a-chessboard-square/"});
  registerStrategy({.name = "parity",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "String"}},
                   squareIsWhiteImpl);
}

bool DetermineColorOfAChessboardSquareSolution::squareIsWhite(
    std::string coordinates) {
  return getSolution()(coordinates);
}

}  // namespace problem_1812
}  // namespace leetcode
