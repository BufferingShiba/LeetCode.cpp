#include "leetcode/problems/knight-probability-in-chessboard.h"

#include <vector>

namespace leetcode {
namespace problem_688 {

static double solution1(int n, int k, int row, int column) {
  const int dirs[8][2] = {
      {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
      {1, -2},  {1, 2},  {2, -1},  {2, 1}};

  std::vector<std::vector<double>> dp(n, std::vector<double>(n, 0.0));
  dp[row][column] = 1.0;

  for (int step = 0; step < k; ++step) {
    std::vector<std::vector<double>> next(n, std::vector<double>(n, 0.0));
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (dp[r][c] == 0.0) continue;
        for (int d = 0; d < 8; ++d) {
          int nr = r + dirs[d][0];
          int nc = c + dirs[d][1];
          if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
            next[nr][nc] += dp[r][c] / 8.0;
          }
        }
      }
    }
    dp = std::move(next);
  }

  double ans = 0.0;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      ans += dp[r][c];
    }
  }
  return ans;
}

KnightProbabilityInChessboardSolution::KnightProbabilityInChessboardSolution() {
  setMetaInfo({
      .id = 688,
      .title = "Knight Probability in Chessboard",
      .url = "https://leetcode.com/problems/knight-probability-in-chessboard"
  });
  registerStrategy({.name = "Dynamic Programming"}, solution1);
}

double KnightProbabilityInChessboardSolution::knightProbability(int n, int k, int row, int column) {
  return getSolution()(n, k, row, column);
}

}  // namespace problem_688
}  // namespace leetcode
