#include "leetcode/problems/twisted-mirror-path-count.h"

namespace leetcode {
namespace problem_3665 {
namespace {

constexpr long long kMod = 1000000007LL;
constexpr int kUncomputed = -2;

// Robot enters mirror cell (r,c) with entering direction dir (0=right, 1=down),
// then gets turned to the perpendicular direction and moved into the adjacent
// cell on that side of the mirror. Mirrors chain; returns the flat index of the
// stable landing cell (>=0), or -1 if the chain goes out of bounds.
int reflectInto(int r, int c, int dir, const std::vector<std::vector<int>>& grid,
                int m, int n, std::vector<int>& memoR, std::vector<int>& memoD) {
  std::vector<int>& memo = (dir == 0) ? memoR : memoD;
  int base = r * n + c;
  if (memo[base] != kUncomputed) return memo[base];

  int nr = r, nc = c;
  if (dir == 0) {      // entered moving right -> turned down -> below mirror
    nr = r + 1;
  } else {             // entered moving down -> turned right -> right of mirror
    nc = c + 1;
  }

  int res;
  if (nr >= m || nc >= n) {
    res = -1;
  } else if (grid[nr][nc] == 0) {
    res = nr * n + nc;
  } else {
    res = reflectInto(nr, nc, 1 - dir, grid, m, n, memoR, memoD);
  }
  memo[base] = res;
  return res;
}

int uniquePathsImpl(std::vector<std::vector<int>>& grid) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());
  int end = m * n - 1;

  std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 0));
  std::vector<int> memoR(m * n, kUncomputed);  // entered moving right
  std::vector<int> memoD(m * n, kUncomputed);  // entered moving down

  dp[0][0] = 1;
  long long ans = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == m - 1 && j == n - 1) continue;
      long long val = dp[i][j];
      if (val == 0) continue;

      for (int dir = 0; dir < 2; ++dir) {
        int ni = i, nj = j;
        if (dir == 0) {       // try moving right
          nj = j + 1;
        } else {              // try moving down
          ni = i + 1;
        }

        int land;
        if (ni >= m || nj >= n) {
          land = -1;
        } else if (grid[ni][nj] == 0) {
          land = ni * n + nj;
        } else {
          land = reflectInto(ni, nj, dir, grid, m, n, memoR, memoD);
        }

        if (land < 0) continue;  // invalid path
        if (land == end) {
          ans = (ans + val) % kMod;
        } else {
          int li = land / n, lj = land % n;
          dp[li][lj] = (dp[li][lj] + val) % kMod;
        }
      }
    }
  }
  return static_cast<int>(ans % kMod);
}

}  // namespace

int TwistedMirrorPathCountSolution::uniquePaths(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

TwistedMirrorPathCountSolution::TwistedMirrorPathCountSolution() {
  setMetaInfo({
      .id = 3665,
      .title = "Twisted Mirror Path Count",
      .url = "https://leetcode.com/problems/twisted-mirror-path-count/",
  });
  registerStrategy({
      .name = "DP with chained mirror resolution",
      .expected = "O(m*n)",
      .time_complexity = "O(m*n)",
      .space_complexity = "O(m*n)",
      .tags = {"Array", "Dynamic Programming", "Matrix"},
  }, uniquePathsImpl);
}

}  // namespace problem_3665
}  // namespace leetcode
