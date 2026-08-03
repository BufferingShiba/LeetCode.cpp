#include "leetcode/problems/maximum-number-of-moves-to-kill-all-pawns.h"

#include <array>
#include <climits>
#include <functional>
#include <queue>
#include <utility>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3283 {

namespace {

// Knight moves: 8 directions.
constexpr std::array<std::pair<int, int>, 8> kDirs = {
    std::pair<int, int>{-2, -1}, std::pair<int, int>{-2, 1},
    std::pair<int, int>{-1, -2}, std::pair<int, int>{-1, 2},
    std::pair<int, int>{1, -2},  std::pair<int, int>{1, 2},
    std::pair<int, int>{2, -1},  std::pair<int, int>{2, 1}};

constexpr int kBoardSize = 50;

// BFS from a source cell (sx, sy), returns distances to all cells in a 50x50 grid.
std::vector<std::vector<int>> bfsDistances(int sx, int sy) {
  std::vector<std::vector<int>> dist(kBoardSize,
                                     std::vector<int>(kBoardSize, -1));
  std::queue<std::pair<int, int>> q;
  dist[sx][sy] = 0;
  q.push({sx, sy});
  while (!q.empty()) {
    auto [cx, cy] = q.front();
    q.pop();
    for (const auto& [dx, dy] : kDirs) {
      int nx = cx + dx;
      int ny = cy + dy;
      if (nx >= 0 && nx < kBoardSize && ny >= 0 && ny < kBoardSize &&
          dist[nx][ny] == -1) {
        dist[nx][ny] = dist[cx][cy] + 1;
        q.push({nx, ny});
      }
    }
  }
  return dist;
}

int maxMovesImpl(int kx, int ky, std::vector<std::vector<int>>& positions) {
  int n = static_cast<int>(positions.size());

  // distMat[source][i] = min knight moves from source to pawn i.
  // Sources: 0..n-1 are pawns, index n is the knight's initial position.
  std::vector<std::vector<int>> distMat(n + 1, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    auto d = bfsDistances(positions[i][0], positions[i][1]);
    for (int j = 0; j < n; ++j) {
      distMat[i][j] = d[positions[j][0]][positions[j][1]];
    }
  }
  {
    auto d = bfsDistances(kx, ky);
    for (int j = 0; j < n; ++j) {
      distMat[n][j] = d[positions[j][0]][positions[j][1]];
    }
  }

  const int full = (1 << n) - 1;
  // dp[mask][last]: max total moves Alice can achieve from state where mask is the
  // captured set and last is the index of last captured pawn (0..n-1).
  std::vector<std::vector<long long>> memo(
      1 << n, std::vector<long long>(n, -1));

  std::function<long long(int, int)> dfs = [&](int mask, int last) -> long long {
    if (mask == full) {
      return 0;
    }
    if (memo[mask][last] != -1) {
      return memo[mask][last];
    }
    int captured = __builtin_popcount(mask);
    bool aliceTurn = (captured % 2 == 0);
    long long best;
    if (aliceTurn) {
      best = -1;
      for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i))) {
          best = std::max(best, distMat[last][i] + dfs(mask | (1 << i), i));
        }
      }
    } else {
      best = LLONG_MAX;
      for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i))) {
          best = std::min(best, distMat[last][i] + dfs(mask | (1 << i), i));
        }
      }
    }
    memo[mask][last] = best;
    return best;
  };

  // Initial: nothing captured, knight at index n, Alice's turn.
  long long ans = -1;
  for (int i = 0; i < n; ++i) {
    ans = std::max(ans, distMat[n][i] + dfs(1 << i, i));
  }
  return static_cast<int>(ans);
}

}  // namespace

MaximumNumberOfMovesToKillAllPawnsSolution::
    MaximumNumberOfMovesToKillAllPawnsSolution() {
  setMetaInfo({.id = 3283,
               .title = "Maximum Number of Moves to Kill All Pawns",
               .url = "https://leetcode.com/problems/maximum-number-of-moves-to-kill-all-pawns/"});
  registerStrategy(
      {.name = "MinMaxBitmaskDP",
       .expected = "Accepted",
       .time_complexity = "O(n^2 * 2^n + n * 2500)",
       .space_complexity = "O(n * 2^n)",
       .tags = {"Array", "Breadth-First Search", "Bitmask", "Game Theory",
                "Math", "Bit Manipulation"}},
      maxMovesImpl);
}

int MaximumNumberOfMovesToKillAllPawnsSolution::maxMoves(
    int kx, int ky, std::vector<std::vector<int>>& positions) {
  return getSolution()(kx, ky, positions);
}

}  // namespace problem_3283
}  // namespace leetcode
