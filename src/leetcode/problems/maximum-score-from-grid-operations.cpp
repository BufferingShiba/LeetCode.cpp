#include "leetcode/problems/maximum-score-from-grid-operations.h"

#include <algorithm>
#include <cstdint>

namespace leetcode::problem_3225 {

namespace {

long long maximumScoreImpl(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  if (n <= 1) {
    return 0LL;
  }
  const int n1 = n + 1;  // heights range 0..n

  // pref[c][i] = sum of grid[0..i-1][c]
  std::vector<std::vector<long long>> pref(n, std::vector<long long>(n1, 0));
  for (int c = 0; c < n; ++c) {
    for (int i = 0; i < n; ++i) {
      pref[c][i + 1] = pref[c][i] + static_cast<long long>(grid[i][c]);
    }
  }

  // dp[a][b]: after deciding heights for columns 0..c, best score with
  // h_{c-1}=a, h_c=b. A white cell with black neighbours on both sides is
  // counted exactly once via max(h_prev, h_next).

  // Base: columns 0 and 1. Column 0 has no left neighbour (hl=0).
  std::vector<std::vector<long long>> dp(n1, std::vector<long long>(n1, 0));
  for (int a = 0; a < n1; ++a) {
    for (int b = 0; b < n1; ++b) {
      dp[a][b] = (b > a) ? pref[0][b] - pref[0][a] : 0LL;
    }
  }

  // Adding h_col = d finalizes column (col-1)'s score, which depends on
  // h_{col-2}=a, h_{col-1}=b, h_col=d via M=max(a,d):
  //   contrib = (M>b) ? fcol[M]-fcol[b] : 0.
  // ndp[b][d] = max_a{ dp[a][b] + contrib } where fcol=pref[col-1].
  // Split a by a<=d (M=d) and a>d (M=a).
  for (int col = 2; col < n; ++col) {
    const auto& fcol = pref[col - 1];

    // best1[b][k] = max_{a<=k} dp[a][b]
    // best2[b][k] = max_{a>=k} (dp[a][b] + (a>b ? fcol[a]-fcol[b] : 0))
    std::vector<std::vector<long long>> best1(n1, std::vector<long long>(n1, 0));
    std::vector<std::vector<long long>> best2(n1, std::vector<long long>(n1 + 1));
    const long long NEG = -4e18;
    for (int b = 0; b < n1; ++b) {
      best1[b][0] = dp[0][b];
      for (int a = 1; a < n1; ++a) {
        best1[b][a] = std::max(best1[b][a - 1], dp[a][b]);
      }
      best2[b][n1] = NEG;
      for (int a = n; a >= 0; --a) {
        long long term = dp[a][b] + (a > b ? fcol[a] - fcol[b] : 0LL);
        best2[b][a] = std::max(term, best2[b][a + 1]);
      }
    }

    std::vector<std::vector<long long>> ndp(n1, std::vector<long long>(n1, 0));
    for (int b = 0; b < n1; ++b) {
      for (int d = 0; d < n1; ++d) {
        long long candA = best1[b][d] + (d > b ? fcol[d] - fcol[b] : 0LL);  // a<=d
        long long candB = best2[b][d + 1];                                   // a>d
        ndp[b][d] = std::max(candA, candB);
      }
    }
    dp.swap(ndp);
  }

  // Finalize column n-1: no right neighbour (hr=0). M=max(a,0)=a.
  long long ans = 0;
  for (int a = 0; a < n1; ++a) {
    for (int b = 0; b < n1; ++b) {
      long long extra = (a > b) ? pref[n - 1][a] - pref[n - 1][b] : 0LL;
      ans = std::max(ans, dp[a][b] + extra);
    }
  }
  return ans;
}

}  // unnamed namespace

MaximumScoreFromGridOperationsSolution::MaximumScoreFromGridOperationsSolution() {
  setMetaInfo({.id = 3225,
               .title = "Maximum Score From Grid Operations",
               .url =
                   "https://leetcode.com/problems/maximum-score-from-grid-operations/"});
  registerStrategy(
      {.name = "ThreeWindowDP",
       .expected = "Accepted",
       .time_complexity = "O(n^3)",
       .space_complexity = "O(n^2)",
       .tags = {"Array", "Dynamic Programming", "Matrix", "Prefix Sum"}},
      &maximumScoreImpl);
}

long long MaximumScoreFromGridOperationsSolution::maximumScore(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_3225
