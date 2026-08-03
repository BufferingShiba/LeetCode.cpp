#include "leetcode/problems/minimum-sideway-jumps.h"

#include <algorithm>
#include <limits>

namespace leetcode {
namespace problem_1824 {

namespace {

int minSideJumpsDP(std::vector<int>& obstacles) {
  const int n = static_cast<int>(obstacles.size());
  const int INF = std::numeric_limits<int>::max() / 2;

  // dp[lane] = minimum side jumps to reach current point in given lane (1/2/3).
  // Start at point 0 in lane 2.
  std::vector<int> dp = {INF, 1, 0, 1};  // index 0 unused, lanes 1..3.

  for (int i = 1; i < n; ++i) {
    // Invalidate lanes blocked by an obstacle at point i.
    if (obstacles[i] >= 1 && obstacles[i] <= 3) {
      dp[obstacles[i]] = INF;
    }

    // Relax side jumps among lanes that have no obstacle at point i.
    int best = std::min({dp[1], dp[2], dp[3]});
    for (int lane = 1; lane <= 3; ++lane) {
      if (obstacles[i] != lane) {
        dp[lane] = std::min(dp[lane], best + 1);
      }
    }
  }

  return std::min({dp[1], dp[2], dp[3]});
}

}  // namespace

MinimumSidewayJumpsSolution::MinimumSidewayJumpsSolution() {
  setMetaInfo({.id = 1824,
               .title = "Minimum Sideway Jumps",
               .url = "https://leetcode.com/problems/minimum-sideway-jumps/"});
  registerStrategy({.name = "DP",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Dynamic Programming"}},
                   minSideJumpsDP);
}

int MinimumSidewayJumpsSolution::minSideJumps(std::vector<int>& obstacles) {
  return getSolution()(obstacles);
}

}  // namespace problem_1824
}  // namespace leetcode
