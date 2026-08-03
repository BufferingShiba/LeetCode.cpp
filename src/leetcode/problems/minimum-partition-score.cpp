#include "leetcode/problems/minimum-partition-score.h"
#include <algorithm>
#include <climits>
#include <cstdint>
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3826 {
namespace {

// Triangular number: value of a subarray with sum s.
inline long long tri(long long s) { return s * (s + 1) / 2; }

// Divide and Conquer DP.
// dp[j][i] = min over p in [j-1, i-1] of dp[j-1][p] + tri(pref[i] - pref[p]),
// where pref[i] = sum of nums[0..i-1].
// The convex triangular cost yields a Monge array, so the optimal split point is
// monotone in i, enabling O(n log n) per row -> O(n k log n) total.
long long minPartitionScoreImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());
  std::vector<long long> pref(n + 1, 0);
  for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + nums[i];

  // prev[i] = dp with seg-1 segments over first i elements; init with seg = 1.
  std::vector<long long> prev(n + 1, 0), cur(n + 1, 0);
  for (int i = 0; i <= n; ++i) prev[i] = tri(pref[i]);

  std::function<void(int, int, int, int)> solveRow;
  solveRow = [&](int l, int r, int optL, int optR) {
    if (l > r) return;
    int mid = (l + r) / 2;
    long long best = LLONG_MAX;
    int bestP = -1;
    int pLow = std::max(optL, 1);
    int pHigh = std::min(optR, mid - 1);
    for (int p = pLow; p <= pHigh; ++p) {
      long long cand = prev[p] + tri(pref[mid] - pref[p]);
      if (cand < best) {
        best = cand;
        bestP = p;
      }
    }
    cur[mid] = best;
    solveRow(l, mid - 1, optL, bestP);
    solveRow(mid + 1, r, bestP, optR);
  };

  for (int seg = 2; seg <= k; ++seg) {
    std::fill(cur.begin(), cur.end(), LLONG_MAX);
    solveRow(seg, n, seg - 1, n - 1);
    prev.swap(cur);
  }
  return prev[n];
}

}  // namespace

MinimumPartitionScoreSolution::MinimumPartitionScoreSolution() {
  setMetaInfo({.id = 3826,
               .title = "Minimum Partition Score",
               .url = "https://leetcode.com/problems/minimum-partition-score/"});
  registerStrategy(
      {"DivideConquerDP", "Accepted", "O(n*k*log n)", "O(n)",
       {"Dynamic Programming", "Divide and Conquer", "Prefix Sum",
        "Monotonic Queue"},
       "dp[j][i] = min over p of dp[j-1][p] + tri(pref[i]-pref[p]); triangular "
       "cost is Monge so optimal p is monotone in i -> divide & conquer DP."},
      minPartitionScoreImpl);
}

long long MinimumPartitionScoreSolution::minPartitionScore(std::vector<int>& nums,
                                                           int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3826
}  // namespace leetcode
