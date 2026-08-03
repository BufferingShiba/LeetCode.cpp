#include "leetcode/problems/find-winner-on-a-tic-tac-toe-game.h"

#include <string>
#include <vector>

namespace leetcode::problem_1275 {

namespace {

std::string tictactoeImpl(std::vector<std::vector<int>>& moves) {
  // grid[i][j]: 0 = empty, 1 = A, -1 = B
  std::vector<std::vector<int>> grid(3, std::vector<int>(3, 0));
  const std::vector<std::string> winner = {"A", "B"};

  for (int i = 0; i < static_cast<int>(moves.size()); ++i) {
    int r = moves[i][0], c = moves[i][1];
    int val = (i % 2 == 0) ? 1 : -1;
    grid[r][c] = val;

    // Check row, column, and diagonals through (r, c)
    bool row = true, col = true, diag = true, anti = true;
    for (int k = 0; k < 3; ++k) {
      if (grid[r][k] != val) row = false;
      if (grid[k][c] != val) col = false;
      if (grid[k][k] != val) diag = false;
      if (grid[k][2 - k] != val) anti = false;
    }
    if (row || col || diag || anti) {
      return winner[i % 2];
    }
  }

  return moves.size() == 9 ? "Draw" : "Pending";
}

}  // namespace

FindWinnerOnATicTacToeGameSolution::FindWinnerOnATicTacToeGameSolution() {
  setMetaInfo({.id = 1275,
               .title = "Find Winner on a Tic Tac Toe Game",
               .url = "https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/"});
  registerStrategy(
      {.name = "simulation",
       .expected = "Accepted",
       .time_complexity = "O(m)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "Matrix", "Simulation"},
       .notes = "Simulate each move and check row/col/diag after each placement."},
      tictactoeImpl);
}

std::string FindWinnerOnATicTacToeGameSolution::tictactoe(
    std::vector<std::vector<int>>& moves) {
  return getSolution()(moves);
}

}  // namespace leetcode::problem_1275
