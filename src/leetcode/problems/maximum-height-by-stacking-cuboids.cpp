#include "leetcode/problems/maximum-height-by-stacking-cuboids.h"

#include <algorithm>

namespace leetcode {
namespace problem_1691 {

namespace {

// Approach: Sort each cuboid's dimensions ascending, then use max dim as height.
// After sorting all cuboids, stacking reduces to a longest-chain DP.
static int maxHeightImpl(std::vector<std::vector<int>>& cuboids) {
  const int n = static_cast<int>(cuboids.size());
  for (auto& c : cuboids) {
    std::sort(c.begin(), c.end());
  }
  std::sort(cuboids.begin(), cuboids.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              if (a[0] != b[0]) return a[0] < b[0];
              if (a[1] != b[1]) return a[1] < b[1];
              return a[2] < b[2];
            });

  std::vector<int> dp(n, 0);
  int best = 0;
  for (int i = n - 1; i >= 0; --i) {
    dp[i] = cuboids[i][2];
    for (int j = i + 1; j < n; ++j) {
      if (cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] &&
          cuboids[i][2] <= cuboids[j][2]) {
        dp[i] = std::max(dp[i], cuboids[i][2] + dp[j]);
      }
    }
    best = std::max(best, dp[i]);
  }
  return best;
}

}  // namespace

MaximumHeightByStackingCuboids::MaximumHeightByStackingCuboids() {
  setMetaInfo({.id = 1691,
               .title = "Maximum Height by Stacking Cuboids",
               .url = "https://leetcode.com/problems/maximum-height-by-stacking-cuboids/"});
  registerStrategy(
      {.name = "SortAndLISDp",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"DP", "Sorting"}},
      maxHeightImpl);
}

int MaximumHeightByStackingCuboids::maxHeight(
    std::vector<std::vector<int>>& cuboids) {
  return getSolution()(cuboids);
}

}  // namespace problem_1691
}  // namespace leetcode
