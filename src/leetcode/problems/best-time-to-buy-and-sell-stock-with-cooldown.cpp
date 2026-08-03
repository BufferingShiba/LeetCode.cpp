#include "leetcode/problems/best-time-to-buy-and-sell-stock-with-cooldown.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_309 {

// 三状态 DP：hold / sold / rest
// hold[i] = max(hold[i-1], rest[i-1] - prices[i])
// sold[i] = hold[i-1] + prices[i]
// rest[i] = max(rest[i-1], sold[i-1])
static int maxProfitDP(std::vector<int>& prices) {
  int n = static_cast<int>(prices.size());
  if (n <= 1) return 0;

  int hold = -prices[0];  // 第 0 天买入
  int sold = 0;           // 第 0 天无法卖出
  int rest = 0;           // 第 0 天观望

  for (int i = 1; i < n; ++i) {
    int prev_hold = hold;
    int prev_sold = sold;
    int prev_rest = rest;

    hold = std::max(prev_hold, prev_rest - prices[i]);
    sold = prev_hold + prices[i];
    rest = std::max(prev_rest, prev_sold);
  }

  return std::max(sold, rest);
}

BestTimeToBuyAndSellStockWithCooldownSolution::
    BestTimeToBuyAndSellStockWithCooldownSolution() {
  setMetaInfo({.id = 309,
               .title = "Best Time to Buy and Sell Stock with Cooldown",
               .url = "https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/"});

  registerStrategy({.name = "DP (3-state)",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Dynamic Programming"}},
                   maxProfitDP);
}

int BestTimeToBuyAndSellStockWithCooldownSolution::maxProfit(
    std::vector<int>& prices) {
  return getSolution()(prices);
}

}  // namespace leetcode::problem_309
