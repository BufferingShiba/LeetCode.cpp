#include "leetcode/problems/last-stone-weight-ii.h"

#include <algorithm>
#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_1049 {
namespace {

int lastStoneWeightIIImpl(std::vector<int>& stones) {
  const int total = std::accumulate(stones.begin(), stones.end(), 0);
  const int half = total / 2;
  std::vector<bool> dp(half + 1, false);
  dp[0] = true;
  int best = 0;
  for (int stone : stones) {
    for (int j = half; j >= stone; --j) {
      if (dp[j - stone]) {
        dp[j] = true;
        best = std::max(best, j);
      }
    }
  }
  return total - 2 * best;
}

}  // namespace

LastStoneWeightIiSolution::LastStoneWeightIiSolution() {
  setMetaInfo({.id = 1049,
               .title = "Last Stone Weight II",
               .url = "https://leetcode.com/problems/last-stone-weight-ii/"});
  registerStrategy(
      {.name = "subset-sum-dp",
       .expected = "Accepted",
       .time_complexity = "O(n * sum)",
       .space_complexity = "O(sum)",
       .tags = {"Array", "Dynamic Programming"}},
      lastStoneWeightIIImpl);
}

int LastStoneWeightIiSolution::lastStoneWeightII(std::vector<int>& stones) {
  return getSolution()(stones);
}

}  // namespace problem_1049
}  // namespace leetcode
