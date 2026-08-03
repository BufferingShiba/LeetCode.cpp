#include "leetcode/problems/battleships-in-a-board.h"

namespace leetcode::problem_419 {

static int countBattleshipsImpl(std::vector<std::vector<char>>& board) {
  int m = static_cast<int>(board.size());
  int n = static_cast<int>(board[0].size());
  int count = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == 'X') {
        // Count only the "head" (top-leftmost cell) of each battleship.
        bool noXAbove = (i == 0 || board[i - 1][j] != 'X');
        bool noXLeft = (j == 0 || board[i][j - 1] != 'X');
        if (noXAbove && noXLeft) {
          ++count;
        }
      }
    }
  }

  return count;
}

BattleshipsInABoardSolution::BattleshipsInABoardSolution() {
  setMetaInfo({.id = 419,
               .title = "Battleships in a Board",
               .url = "https://leetcode.com/problems/battleships-in-a-board/"});
  registerStrategy({.name = "OnePassHeadCount",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Matrix"}},
                   countBattleshipsImpl);
  setDefaultStrategy();
}

int BattleshipsInABoardSolution::countBattleships(
    std::vector<std::vector<char>>& board) {
  return getSolution()(board);
}

}  // namespace leetcode::problem_419
