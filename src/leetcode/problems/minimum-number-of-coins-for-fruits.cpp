#include "leetcode/problems/minimum-number-of-coins-for-fruits.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2944 {

namespace {

constexpr int kInf = 1 << 30;

int minimumCoinsImpl(std::vector<int>& prices) {
  const int n = static_cast<int>(prices.size());
  // dp[i]: 购买 0-indexed 水果 i (花费 prices[i]) 后, 配合后续购买,
  // 覆盖水果 [i, n) 的最小总成本.
  //
  // 规则: 购买第 (i+1) 个水果(索引 i) 可获得随后的 (i+1) 个水果免费,
  // 即免费覆盖索引 [i+1, 2i+1] (1-indexed 位次 p 奖励后续 p 个水果).
  //
  // 若购买 i 已能覆盖到底 (2i+1 >= n-1), 则 dp[i] = prices[i];
  // 否则下一个必须购买的索引 j 落在 [i+1, 2i+2] 内
  // (j<=2i+1 为免费范围内延长奖励, j=2i+2 为第一个未被覆盖的水果),
  // dp[i] = prices[i] + min(dp[j]).
  std::vector<int> dp(n, kInf);

  for (int i = n - 1; i >= 0; --i) {
    if (2 * i + 1 >= n - 1) {
      dp[i] = prices[i];
      continue;
    }
    const int hi = std::min(2 * i + 2, n - 1);
    int best = kInf;
    for (int j = i + 1; j <= hi; ++j) {
      best = std::min(best, dp[j]);
    }
    dp[i] = prices[i] + best;
  }

  return dp[0];
}

}  // namespace

MinimumNumberOfCoinsForFruitsSolution::MinimumNumberOfCoinsForFruitsSolution() {
  setMetaInfo({.id = 2944,
               .title = "Minimum Number of Coins for Fruits",
               .url = "https://leetcode.com/problems/minimum-number-of-coins-for-fruits/"});
  registerStrategy(
      {.name = "DPWindow",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"Dynamic Programming", "Queue"}},
      minimumCoinsImpl);
}

int MinimumNumberOfCoinsForFruitsSolution::minimumCoins(std::vector<int>& prices) {
  return getSolution()(prices);
}

}  // namespace problem_2944
}  // namespace leetcode
