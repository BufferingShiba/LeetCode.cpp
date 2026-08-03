#include "leetcode/problems/maximum-value-of-k-coins-from-piles.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2218 {

static int maxValueOfCoinsImpl(std::vector<std::vector<int>>& piles, int k) {
  std::vector<int> dp(k + 1, -1);
  dp[0] = 0;

  for (const auto& pile : piles) {
    int m = static_cast<int>(pile.size());
    // prefix sums for current pile
    std::vector<int> pre(m + 1, 0);
    for (int i = 0; i < m; ++i) {
      pre[i + 1] = pre[i] + pile[i];
    }

    // group knapsack: iterate j descending to avoid reuse within same pile
    for (int j = k; j >= 0; --j) {
      int max_t = std::min(j, m);
      for (int t = 1; t <= max_t; ++t) {
        if (dp[j - t] != -1) {
          dp[j] = std::max(dp[j], dp[j - t] + pre[t]);
        }
      }
    }
  }

  return dp[k];
}

MaximumValueOfKCoinsFromPilesSolution::MaximumValueOfKCoinsFromPilesSolution() {
  setMetaInfo({.id = 2218,
               .title = "Maximum Value of K Coins From Piles",
               .url = "https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/"});
  registerStrategy(
      {.name = "DP",
       .expected = "Accepted",
       .time_complexity = "O(k * S) where S = total number of coins",
       .space_complexity = "O(k)",
       .tags = {"Dynamic Programming", "Prefix Sum", "Array"}},
      maxValueOfCoinsImpl);
}

int MaximumValueOfKCoinsFromPilesSolution::maxValueOfCoins(
    std::vector<std::vector<int>>& piles, int k) {
  return getSolution()(piles, k);
}

}  // namespace problem_2218
}  // namespace leetcode
