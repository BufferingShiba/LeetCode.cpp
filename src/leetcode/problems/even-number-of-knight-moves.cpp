#include "leetcode/problems/even-number-of-knight-moves.h"

#include <queue>
#include <vector>

namespace leetcode {
namespace problem_3996 {
namespace {

bool canReachImpl(std::vector<int>& start, std::vector<int>& target) {
  const int sx = start[0], sy = start[1];
  const int tx = target[0], ty = target[1];

  // BFS over the 8x8 board computing minimal moves to each cell.
  const int kMoves[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1},
                            {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
  std::vector<std::vector<int>> dist(8, std::vector<int>(8, -1));
  std::queue<std::pair<int, int>> q;
  dist[sx][sy] = 0;
  q.push({sx, sy});

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (x == tx && y == ty) {
      return dist[x][y] % 2 == 0;
    }
    for (int i = 0; i < 8; ++i) {
      int nx = x + kMoves[i][0];
      int ny = y + kMoves[i][1];
      if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || dist[nx][ny] != -1) {
        continue;
      }
      dist[nx][ny] = dist[x][y] + 1;
      q.push({nx, ny});
    }
  }
  return false;  // unreachable
}

}  // namespace

EvenNumberOfKnightMovesSolution::EvenNumberOfKnightMovesSolution() {
  setMetaInfo({3996, "Even Number of Knight Moves",
               "https://leetcode.com/problems/even-number-of-knight-moves/"});
  registerStrategy(
      {"bfs", "Accepted", "O(64)", "O(64)", {"BFS", "Graph"},
       "BFS over 8x8 board; even steps means dist is even."},
      [](std::vector<int>& start, std::vector<int>& target) -> bool {
        return canReachImpl(start, target);
      });
}

bool EvenNumberOfKnightMovesSolution::canReach(std::vector<int>& start,
                                               std::vector<int>& target) {
  return getSolution()(start, target);
}

}  // namespace problem_3996
}  // namespace leetcode
