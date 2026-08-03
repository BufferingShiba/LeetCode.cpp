#include "leetcode/problems/check-if-two-chessboard-squares-have-the-same-color.h"

namespace leetcode {
namespace problem_3274 {

namespace {

bool checkTwoChessboardsImpl(const std::string& coordinate1,
                             const std::string& coordinate2) {
  auto color = [](const std::string& c) {
    return ((c[0] - 'a') + (c[1] - '1')) % 2;
  };
  return color(coordinate1) == color(coordinate2);
}

}  // namespace

CheckIfTwoChessboardSquaresHaveTheSameColorSolution::
    CheckIfTwoChessboardSquaresHaveTheSameColorSolution() {
  registerStrategies();
}

bool CheckIfTwoChessboardSquaresHaveTheSameColorSolution::checkTwoChessboards(
    std::string coordinate1, std::string coordinate2) {
  return getSolution()(coordinate1, coordinate2);
}

void CheckIfTwoChessboardSquaresHaveTheSameColorSolution::registerStrategies() {
  setMetaInfo({.id = 3274,
               .title = "Check if Two Chessboard Squares Have the Same Color",
               .url = "https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/"});
  registerStrategy(
      {.name = "Parity",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "String"}},
      checkTwoChessboardsImpl);
}

}  // namespace problem_3274
}  // namespace leetcode
