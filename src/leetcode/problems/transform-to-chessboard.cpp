#include "leetcode/problems/transform-to-chessboard.h"

#include <algorithm>

namespace leetcode {
namespace problem_782 {

namespace {

int movesToChessboardImpl(std::vector<std::vector<int>>& board) {
  const int n = static_cast<int>(board.size());

  // Every row/column must equal board[0][*] / board[*][0] or its complement.
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((board[0][0] ^ board[i][0] ^ board[i][j] ^ board[0][j]) == 1) {
        return -1;
      }
    }
  }

  int rowSum = 0;
  int colSum = 0;
  for (int i = 0; i < n; ++i) {
    rowSum += board[0][i];
    colSum += board[i][0];
  }

  if (rowSum != n / 2 && rowSum != (n + 1) / 2) return -1;
  if (colSum != n / 2 && colSum != (n + 1) / 2) return -1;

  int rowSwap = 0;
  int colSwap = 0;
  for (int i = 0; i < n; ++i) {
    rowSwap += board[i][0] == (i % 2);
    colSwap += board[0][i] == (i % 2);
  }

  if (n % 2) {
    if (rowSwap % 2) rowSwap = n - rowSwap;
    if (colSwap % 2) colSwap = n - colSwap;
  } else {
    rowSwap = std::min(rowSwap, n - rowSwap);
    colSwap = std::min(colSwap, n - colSwap);
  }

  return (rowSwap + colSwap) / 2;
}

}  // namespace

TransformToChessboardSolution::TransformToChessboardSolution() {
  setMetaInfo({.id = 782,
               .title = "Transform to Chessboard",
               .url = "https://leetcode.com/problems/transform-to-chessboard/"});

  registerStrategy(
      {.name = "greedy+bitmask",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Bit Manipulation", "Matrix", "Greedy"}},
      movesToChessboardImpl);
}

int TransformToChessboardSolution::movesToChessboard(std::vector<std::vector<int>>& board) {
  return getSolution()(board);
}

}  // namespace problem_782
}  // namespace leetcode
