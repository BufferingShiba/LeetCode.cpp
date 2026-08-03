#include "leetcode/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color.h"

namespace {

bool winnerOfGameImpl(std::string colors) {
  int a_moves = 0;
  int b_moves = 0;
  int n = static_cast<int>(colors.size());
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && colors[j] == colors[i]) {
      ++j;
    }
    int len = j - i;
    int moves = (len >= 3) ? (len - 2) : 0;
    if (colors[i] == 'A') {
      a_moves += moves;
    } else {
      b_moves += moves;
    }
    i = j;
  }
  return a_moves > b_moves;
}

}  // namespace

namespace leetcode {
namespace problem_2038 {

RemoveColoredPiecesIfBothNeighborsAreTheSameColorSolution::
    RemoveColoredPiecesIfBothNeighborsAreTheSameColorSolution() {
  setMetaInfo({.id = 2038,
               .title = "Remove Colored Pieces if Both Neighbors are the Same Color",
               .url = "https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/"});
  registerStrategy({.name = "Greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "String", "Greedy", "Game Theory"}},
                   winnerOfGameImpl);
  setDefaultStrategy();
}

bool RemoveColoredPiecesIfBothNeighborsAreTheSameColorSolution::winnerOfGame(
    std::string colors) {
  return getSolution()(colors);
}

}  // namespace problem_2038
}  // namespace leetcode
