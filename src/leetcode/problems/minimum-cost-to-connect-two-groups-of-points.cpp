#include "leetcode/problems/minimum-cost-to-connect-two-groups-of-points.h"

#include <algorithm>
#include <limits>
#include <vector>

namespace leetcode {
namespace problem_1595 {
namespace {

int connectTwoGroupsImpl(std::vector<std::vector<int>>& cost) {
  const int n = static_cast<int>(cost.size());
  const int m = static_cast<int>(cost[0].size());
  const int full = (1 << m) - 1;

  const int INF = std::numeric_limits<int>::max() / 2;

  // dp[mask] = min cost after processing some first-group rows,
  //            where the covered set of group-2 points is `mask`.
  std::vector<int> dp(1 << m, INF);
  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
    std::vector<int> ndp(1 << m, INF);
    for (int mask = 0; mask <= full; ++mask) {
      if (dp[mask] == INF) continue;
      const int comp = full ^ mask;  // group-2 bits not yet covered

      // Option A: point i adds a non-empty set T of previously-uncovered bits.
      // Connecting to more than these new bits only adds non-negative cost with
      // no coverage benefit, so we never consider redundant old connections here.
      for (int T = comp; T > 0; T = (T - 1) & comp) {
        int costT = 0;
        for (int j = 0; j < m; ++j) {
          if (T & (1 << j)) costT += cost[i][j];
        }
        const int nmask = mask | T;
        if (dp[mask] + costT < ndp[nmask]) {
          ndp[nmask] = dp[mask] + costT;
        }
      }

      // Option B: point i covers nothing new; it must still connect to at
      // least one (already covered) point, so pay its cheapest such connection.
      if (mask != 0) {
        int cheapest = INF;
        for (int j = 0; j < m; ++j) {
          if (mask & (1 << j)) cheapest = std::min(cheapest, cost[i][j]);
        }
        if (dp[mask] + cheapest < ndp[mask]) {
          ndp[mask] = dp[mask] + cheapest;
        }
      }
    }
    dp.swap(ndp);
  }

  return dp[full];
}

}  // namespace

MinimumCostToConnectTwoGroupsOfPointsSolution::MinimumCostToConnectTwoGroupsOfPointsSolution() {
  setMetaInfo({.id = 1595,
               .title = "Minimum Cost to Connect Two Groups of Points",
               .url = "https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/"});
  registerStrategy(
      {
          .name = "BitmaskDP",
          .expected = "Accepted",
          .time_complexity = "O(n * 3^m)",
          .space_complexity = "O(2^m)",
          .tags = {"Array", "Dynamic Programming", "Bit Manipulation", "Matrix", "Bitmask"},
      },
      connectTwoGroupsImpl);
}

}  // namespace problem_1595
}  // namespace leetcode
