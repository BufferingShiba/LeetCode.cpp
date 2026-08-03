#include "leetcode/problems/minesweeper.h"

namespace leetcode {
namespace problem_529 {

namespace {

// 8-direction neighbors
constexpr int kDx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int kDy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int countAdjacentMines(const std::vector<std::vector<char>>& board, int r, int c) {
  int m = static_cast<int>(board.size());
  int n = static_cast<int>(board[0].size());
  int cnt = 0;
  for (int d = 0; d < 8; ++d) {
    int nr = r + kDx[d];
    int nc = c + kDy[d];
    if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'M') {
      ++cnt;
    }
  }
  return cnt;
}

void dfsReveal(std::vector<std::vector<char>>& board, int r, int c) {
  int m = static_cast<int>(board.size());
  int n = static_cast<int>(board[0].size());
  if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E') {
    return;
  }
  int mines = countAdjacentMines(board, r, c);
  if (mines > 0) {
    board[r][c] = static_cast<char>('0' + mines);
  } else {
    board[r][c] = 'B';
    for (int d = 0; d < 8; ++d) {
      dfsReveal(board, r + kDx[d], c + kDy[d]);
    }
  }
}

std::vector<std::vector<char>> updateBoardImpl(std::vector<std::vector<char>>& board, std::vector<int>& click) {
  int r = click[0];
  int c = click[1];
  if (board[r][c] == 'M') {
    board[r][c] = 'X';
    return board;
  }
  // board[r][c] == 'E'
  dfsReveal(board, r, c);
  return board;
}

}  // namespace

MinesweeperSolution::MinesweeperSolution() {
  setMetaInfo({.id = 529, .title = "Minesweeper", .url = "https://leetcode.com/problems/minesweeper/"});
  registerStrategy(
      {.name = "DFS",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"Array", "Depth-First Search", "Matrix"}},
      updateBoardImpl);
}

std::vector<std::vector<char>> MinesweeperSolution::updateBoard(
    std::vector<std::vector<char>>& board, std::vector<int>& click) {
  return getSolution()(board, click);
}

}  // namespace problem_529
}  // namespace leetcode
