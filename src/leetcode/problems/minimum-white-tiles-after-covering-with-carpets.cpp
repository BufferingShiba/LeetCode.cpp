#include "leetcode/problems/minimum-white-tiles-after-covering-with-carpets.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::problem_2209 {

static int minimumWhiteTilesImpl(std::string floor, int numCarpets, int carpetLen) {
  const int n = static_cast<int>(floor.size());

  // dp_prev[i] = minimum white tiles visible in prefix [0..i-1] using (j-1) carpets
  // dp_curr[i] = same using j carpets
  std::vector<int> dp_prev(n + 1, 0);
  std::vector<int> dp_curr(n + 1, 0);

  // j = 0: no carpets used, all white tiles are visible
  int prefix = 0;
  for (int i = 0; i <= n; ++i) {
    dp_curr[i] = prefix;
    if (i < n && floor[i] == '1') ++prefix;
  }

  for (int j = 1; j <= numCarpets; ++j) {
    dp_prev.swap(dp_curr);
    dp_curr[0] = 0;
    for (int i = 1; i <= n; ++i) {
      int uncovered = dp_curr[i - 1] + (floor[i - 1] == '1' ? 1 : 0);
      int covered = dp_prev[std::max(0, i - carpetLen)];
      dp_curr[i] = std::min(uncovered, covered);
    }
  }

  return dp_curr[n];
}

MinimumWhiteTilesAfterCoveringWithCarpetsSolution::
    MinimumWhiteTilesAfterCoveringWithCarpetsSolution() {
  setMetaInfo({.id = 2209,
               .title = "Minimum White Tiles After Covering With Carpets",
               .url = "https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/"});

  registerStrategy(
      {.name = "DP (1D rolling array)",
       .expected = "Accepted",
       .time_complexity = "O(n * k)",
       .space_complexity = "O(n)",
       .tags = {"String", "Dynamic Programming", "Prefix Sum"}},
      minimumWhiteTilesImpl);
}

int MinimumWhiteTilesAfterCoveringWithCarpetsSolution::minimumWhiteTiles(
    std::string floor, int numCarpets, int carpetLen) {
  return getSolution()(std::move(floor), numCarpets, carpetLen);
}

}  // namespace leetcode::problem_2209
