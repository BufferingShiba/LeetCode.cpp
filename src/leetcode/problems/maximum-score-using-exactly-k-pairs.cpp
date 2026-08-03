#include "leetcode/problems/maximum-score-using-exactly-k-pairs.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_3836 {

static long long maxScoreImpl(std::vector<int>& nums1,
                               std::vector<int>& nums2, int k) {
  int n = static_cast<int>(nums1.size());
  int m = static_cast<int>(nums2.size());

  const long long NEG_INF = -1'000'000'000'000'000'000LL;  // -1e18

  // dp[t][i][j]: max score picking t pairs from nums1[0..i-1] and nums2[0..j-1]
  std::vector<std::vector<std::vector<long long>>> dp(
      k + 1,
      std::vector<std::vector<long long>>(
          n + 1, std::vector<long long>(m + 1, NEG_INF)));

  // Base: 0 pairs always yields score 0
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[0][i][j] = 0;
    }
  }

  for (int t = 1; t <= k; ++t) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        // Option 1: skip nums1[i-1]
        long long best = dp[t][i - 1][j];
        // Option 2: skip nums2[j-1]
        best = std::max(best, dp[t][i][j - 1]);
        // Option 3: pair nums1[i-1] with nums2[j-1]
        if (dp[t - 1][i - 1][j - 1] != NEG_INF) {
          long long cand =
              dp[t - 1][i - 1][j - 1] +
              static_cast<long long>(nums1[i - 1]) * nums2[j - 1];
          best = std::max(best, cand);
        }
        dp[t][i][j] = best;
      }
    }
  }

  return dp[k][n][m];
}

MaximumScoreUsingExactlyKPairsSolution::
    MaximumScoreUsingExactlyKPairsSolution() {
  setMetaInfo({.id = 3836,
               .title = "Maximum Score Using Exactly K Pairs",
               .url = "https://leetcode.com/problems/maximum-score-using-exactly-k-pairs/"});

  registerStrategy(
      {.name = "DP_3D",
       .expected = "Accepted",
       .time_complexity = "O(k * n * m)",
       .space_complexity = "O(k * n * m)",
       .tags = {"Array", "Dynamic Programming"}},
      maxScoreImpl);
}

long long MaximumScoreUsingExactlyKPairsSolution::maxScore(
    std::vector<int>& nums1, std::vector<int>& nums2, int k) {
  return getSolution()(nums1, nums2, k);
}

}  // namespace problem_3836
}  // namespace leetcode
