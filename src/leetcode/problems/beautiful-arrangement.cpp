#include "leetcode/problems/beautiful-arrangement.h"

#include <vector>

namespace leetcode::problem_526 {

static int countArrangementImpl(int n) {
  int totalMasks = 1 << n;
  std::vector<int> dp(totalMasks, 0);
  dp[0] = 1;  // empty arrangement

  for (int mask = 0; mask < totalMasks; ++mask) {
    if (dp[mask] == 0) continue;
    // number of positions already filled
    int pos = __builtin_popcount(mask) + 1;
    for (int num = 1; num <= n; ++num) {
      int bit = 1 << (num - 1);
      if (mask & bit) continue;  // already used
      if (num % pos == 0 || pos % num == 0) {
        dp[mask | bit] += dp[mask];
      }
    }
  }

  return dp[totalMasks - 1];
}

BeautifulArrangementSolution::BeautifulArrangementSolution() {
  setMetaInfo({.id = 526,
               .title = "Beautiful Arrangement",
               .url = "https://leetcode.com/problems/beautiful-arrangement/"});
  registerStrategy(
      {.name = "DP + Bitmask",
       .expected = "Accepted",
       .time_complexity = "O(n * 2^n)",
       .space_complexity = "O(2^n)",
       .tags = {"Dynamic Programming", "Bit Manipulation", "Bitmask"}},
      countArrangementImpl);
  setDefaultStrategy();
}

int BeautifulArrangementSolution::countArrangement(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_526
