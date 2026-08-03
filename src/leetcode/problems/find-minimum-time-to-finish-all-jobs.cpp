#include "leetcode/problems/find-minimum-time-to-finish-all-jobs.h"
#include <algorithm>
#include <limits>

namespace leetcode {
namespace problem_1723 {

namespace {

int minimumTimeRequiredImpl(std::vector<int>& jobs, int k) {
  const int n = static_cast<int>(jobs.size());
  const int full = (1 << n) - 1;

  // sum[mask] = total time of all jobs in mask
  std::vector<long long> sum(1 << n, 0);
  for (int mask = 1; mask <= full; ++mask) {
    int bit = __builtin_ctz(mask);
    sum[mask] = sum[mask & (mask - 1)] + jobs[bit];
  }

  const long long INF = std::numeric_limits<long long>::max() / 4;
  // dp[w][mask]
  std::vector<std::vector<long long>> dp(k + 1,
      std::vector<long long>(1 << n, INF));
  dp[0][0] = 0;

  for (int w = 1; w <= k; ++w) {
    for (int mask = 1; mask <= full; ++mask) {
      // enumerate non-empty submask assigned to worker w
      for (int sub = mask; sub; sub = (sub - 1) & mask) {
        long long cand = std::max(dp[w - 1][mask ^ sub], sum[sub]);
        if (cand < dp[w][mask]) dp[w][mask] = cand;
      }
    }
  }

  return static_cast<int>(dp[k][full]);
}

}  // namespace

int FindMinimumTimeToFinishAllJobsSolution::minimumTimeRequired(
    std::vector<int>& jobs, int k) {
  return getSolution()(jobs, k);
}

FindMinimumTimeToFinishAllJobsSolution::FindMinimumTimeToFinishAllJobsSolution() {
  setMetaInfo({.id = 1723,
               .title = "Find Minimum Time to Finish All Jobs",
               .url = "https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/"});
  registerStrategy(
      {.name = "bitmask-dp",
       .expected = "Accepted",
       .time_complexity = "O(k * 3^n)",
       .space_complexity = "O(k * 2^n)",
       .tags = {"Bitmask DP", "Dynamic Programming"}},
      minimumTimeRequiredImpl);
}

}  // namespace problem_1723
}  // namespace leetcode
