#include "leetcode/problems/tallest-billboard.h"

#include <algorithm>
#include <climits>
#include <unordered_map>

namespace leetcode {
namespace problem_956 {

// DP over difference.
// dp[absDiff] = max of the common (shorter) height achievable with that
// absolute difference between the two supports.
// For each rod x, from a state (s, h) with abs diff = s and common height = h:
//   1) skip          -> (s, h)
//   2) add to taller -> (s + x, h)
//   3) add to shorter-> (|s - x|, h + min(s, x))
static int tallestBillboardImpl(std::vector<int>& rods) {
  std::unordered_map<int, int> dp;
  dp[0] = 0;

  for (int x : rods) {
    std::unordered_map<int, int> ndp = dp;
    for (const auto& [s, h] : dp) {
      // add to taller side
      int n1 = s + x;
      ndp[n1] = std::max(ndp[n1], h);
      // add to shorter side
      int n2 = s > x ? s - x : x - s;
      int h2 = h + std::min(s, x);
      ndp[n2] = std::max(ndp[n2], h2);
    }
    dp.swap(ndp);
  }

  return dp[0];
}

TallestBillboardSolution::TallestBillboardSolution() {
  setMetaInfo({.id = 956,
               .title = "Tallest Billboard",
               .url = "https://leetcode.com/problems/tallest-billboard/"});
  registerStrategy(
      {.name = "Difference DP",
       .expected = "Accepted",
       .time_complexity = "O(n * sum)",
       .space_complexity = "O(sum)",
       .tags = {"Array", "Dynamic Programming"}},
      tallestBillboardImpl);
}

int TallestBillboardSolution::tallestBillboard(std::vector<int>& rods) {
  return getSolution()(rods);
}

}  // namespace problem_956
}  // namespace leetcode
