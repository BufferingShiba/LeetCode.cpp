#include "leetcode/problems/surrounded-regions.h"

#include <vector>

namespace leetcode {
namespace problem_130 {

namespace {

void solveImpl(std::vector<std::vector<char>>& board) {
  const int m = static_cast<int>(board.size());
  if (m == 0) {
    return;
  }
  const int n = static_cast<int>(board[0].size());
  if (n == 0) {
    return;
  }

  const int dr[4] = {1, -1, 0, 0};
  const int dc[4] = {0, 0, 1, -1};

  std::vector<std::vector<int>> stack;
  stack.reserve(m * n);

  auto isBorder = [&](int r, int c) {
    return r == 0 || r == m - 1 || c == 0 || c == n - 1;
  };

  auto pushIfBorderO = [&](int r, int c) {
    if (board[r][c] == 'O') {
      board[r][c] = 'S';  // safe marker
      stack.push_back({r, c});
    }
  };

  // Enqueue all border 'O' cells and mark as safe.
  for (int c = 0; c < n; ++c) {
    pushIfBorderO(0, c);
    pushIfBorderO(m - 1, c);
  }
  for (int r = 0; r < m; ++r) {
    pushIfBorderO(r, 0);
    pushIfBorderO(r, n - 1);
  }

  // Iterative DFS flood fill from border 'O' cells.
  while (!stack.empty()) {
    auto cell = stack.back();
    stack.pop_back();
    int r = cell[0];
    int c = cell[1];
    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
        continue;
      }
      if (board[nr][nc] == 'O') {
        board[nr][nc] = 'S';
        stack.push_back({nr, nc});
      }
    }
  }

  // Flip remaining 'O' to 'X', and restore 'S' to 'O'.
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (board[r][c] == 'O') {
        board[r][c] = 'X';
      } else if (board[r][c] == 'S') {
        board[r][c] = 'O';
      }
    }
  }
}

}  // namespace

SurroundedRegionsSolution::SurroundedRegionsSolution() {
  setMetaInfo({.id = 130,
               .title = "Surrounded Regions",
               .url =
                   "https://leetcode.com/problems/surrounded-regions/"});
  registerStrategy(
      {.name = "BorderDFSFloodFill",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"Depth-First Search", "Matrix", "Flood Fill"},
       .notes =
           "Mark border-connected 'O' as safe, then flip remaining 'O'."},
      solveImpl);
}

void SurroundedRegionsSolution::solve(std::vector<std::vector<char>>& board) {
  return getSolution()(board);
}

}  // namespace problem_130
}  // namespace leetcode
