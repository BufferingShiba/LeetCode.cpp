#include "leetcode/problems/count-paths-with-the-given-xor-value.h"

namespace leetcode {
namespace problem_3393 {

static int solution1(vector<vector<int>>& grid, int k) {
  const int MOD = 1000000007;
  int m = grid.size();
  int n = grid[0].size();
  // dp[i][j][x] = number of paths to reach (i,j) with XOR value x.
  // grid values and k are < 16, so XOR of such values stays in [0,16).
  vector<vector<vector<int>>> dp(
      m, vector<vector<int>>(n, vector<int>(16, 0)));
  dp[0][0][grid[0][0]] = 1;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 && j == 0) continue;
      for (int x = 0; x < 16; ++x) {
        int ways = 0;
        if (i > 0) ways = (ways + dp[i - 1][j][x]) % MOD;
        if (j > 0) ways = (ways + dp[i][j - 1][x]) % MOD;
        int nx = x ^ grid[i][j];
        dp[i][j][nx] = (dp[i][j][nx] + ways) % MOD;
      }
    }
  }
  return dp[m - 1][n - 1][k];
}

CountPathsWithTheGivenXorValueSolution::CountPathsWithTheGivenXorValueSolution() {
  setMetaInfo({
      .id = 3393,
      .title = "Count Paths With the Given XOR Value",
      .url = "https://leetcode.com/problems/count-paths-with-the-given-xor-value"
  });
  registerStrategy({.name = "Brute Force", .expected = "Accepted",
                    .time_complexity = "O(m*n*16)",
                    .space_complexity = "O(m*n*16)",
                    .tags = {"DP"}},
                   solution1);
}

int CountPathsWithTheGivenXorValueSolution::countPathsWithXorValue(vector<vector<int>>& grid, int k) {
  return getSolution()(grid, k);
}

}  // namespace problem_3393
}  // namespace leetcode
