#include "leetcode/problems/two-furthest-houses-with-different-colors.h"

#include <algorithm>

namespace leetcode::problem_2078 {

namespace {

int maxDistanceGreedy(std::vector<int>& colors) {
  const int n = static_cast<int>(colors.size());
  int ans = 0;
  // Furthest pair must involve an endpoint.
  for (int i = 0; i < n; ++i) {
    if (colors[i] != colors[0]) {
      ans = std::max(ans, i);
    }
    if (colors[i] != colors[n - 1]) {
      ans = std::max(ans, n - 1 - i);
    }
  }
  return ans;
}

}  // namespace

TwoFurthestHousesWithDifferentColorsSolution::
    TwoFurthestHousesWithDifferentColorsSolution() {
  setMetaInfo({.id = 2078,
               .title = "Two Furthest Houses With Different Colors",
               .url = "https://leetcode.com/problems/two-furthest-houses-with-different-colors/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      maxDistanceGreedy);
}

int TwoFurthestHousesWithDifferentColorsSolution::maxDistance(
    std::vector<int>& colors) {
  return getSolution()(colors);
}

}  // namespace leetcode::problem_2078
