#include "leetcode/problems/best-time-to-buy-and-sell-stock.h"

namespace leetcode::problem_121 {

namespace {

int maxProfitImpl(std::vector<int>& prices) {
  int min_price = prices[0];
  int max_profit = 0;
  for (size_t i = 1; i < prices.size(); ++i) {
    if (prices[i] < min_price) {
      min_price = prices[i];
    } else {
      int profit = prices[i] - min_price;
      if (profit > max_profit) {
        max_profit = profit;
      }
    }
  }
  return max_profit;
}

}  // namespace

BestTimeToBuyAndSellStockSolution::BestTimeToBuyAndSellStockSolution() {
  setMetaInfo({.id = 121,
               .title = "Best Time to Buy and Sell Stock",
               .url = "https://leetcode.com/problems/best-time-to-buy-and-sell-stock/"});

  registerStrategy(
      {.name = "SinglePassMinPrice",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Dynamic Programming"}},
      maxProfitImpl);
}

int BestTimeToBuyAndSellStockSolution::maxProfit(std::vector<int>& prices) {
  return getSolution()(prices);
}

}  // namespace leetcode::problem_121
