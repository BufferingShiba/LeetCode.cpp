#include "leetcode/problems/snakes-and-ladders.h"

#include <queue>
#include <vector>

namespace leetcode {
namespace problem_909 {

static int snakesAndLaddersImpl(std::vector<std::vector<int>>& board) {
  int n = static_cast<int>(board.size());
  int target = n * n;

  std::vector<bool> visited(target + 1, false);
  std::queue<std::pair<int, int>> q;
  q.push({1, 0});
  visited[1] = true;

  while (!q.empty()) {
    auto [curr, moves] = q.front();
    q.pop();

    if (curr == target) {
      return moves;
    }

    for (int dice = 1; dice <= 6; ++dice) {
      int next = curr + dice;
      if (next > target) break;

      // Convert square number to (row, col)
      int k = next - 1;
      int row_from_bottom = k / n;
      int col_in_row = k % n;
      int r = n - 1 - row_from_bottom;
      int c = (row_from_bottom % 2 == 0) ? col_in_row : (n - 1 - col_in_row);

      if (board[r][c] != -1) {
        next = board[r][c];  // snake or ladder
      }

      if (!visited[next]) {
        visited[next] = true;
        q.push({next, moves + 1});
      }
    }
  }

  return -1;
}

SnakesAndLaddersSolution::SnakesAndLaddersSolution() {
  setMetaInfo(
      {.id = 909,
       .title = "Snakes and Ladders",
       .url = "https://leetcode.com/problems/snakes-and-ladders/"});
  registerStrategy(
      {.name = "BFS",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"Array", "Breadth-First Search", "Matrix"}},
      snakesAndLaddersImpl);
}

int SnakesAndLaddersSolution::snakesAndLadders(
    std::vector<std::vector<int>>& board) {
  return getSolution()(board);
}

}  // namespace problem_909
}  // namespace leetcode
