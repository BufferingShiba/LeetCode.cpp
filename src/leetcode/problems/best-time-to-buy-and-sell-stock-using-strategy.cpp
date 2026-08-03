#include "leetcode/problems/best-time-to-buy-and-sell-stock-using-strategy.h"

#include <algorithm>
#include <cstdint>

namespace leetcode {
namespace problem_3652 {
namespace {

long long slidingWindow(std::vector<int>& prices, std::vector<int>& strategy, int k) {
  const int n = static_cast<int>(prices.size());
  const int half = k / 2;
  std::vector<long long> prefixFirst(n + 1, 0);
  std::vector<long long> prefixSecond(n + 1, 0);
  long long original = 0;

  for (int i = 0; i < n; ++i) {
    const long long current = static_cast<long long>(strategy[i]) * prices[i];
    const long long firstDelta = -current;
    const long long secondDelta = static_cast<long long>(prices[i]) - current;
    original += current;
    prefixFirst[i + 1] = prefixFirst[i] + firstDelta;
    prefixSecond[i + 1] = prefixSecond[i] + secondDelta;
  }

  long long bestDelta = 0;
  for (int start = 0; start + k <= n; ++start) {
    const long long firstHalf = prefixFirst[start + half] - prefixFirst[start];
    const long long secondHalf = prefixSecond[start + k] - prefixSecond[start + half];
    bestDelta = std::max(bestDelta, firstHalf + secondHalf);
  }
  return original + bestDelta;
}

}  // namespace

BestTimeToBuyAndSellStockUsingStrategySolution::BestTimeToBuyAndSellStockUsingStrategySolution() {
  setMetaInfo({.id = 3652,
               .title = "Best Time to Buy and Sell Stock using Strategy",
               .url = "https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/"});
  registerStrategy({.name = "prefix_delta_window",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Prefix Sum", "Sliding Window"}},
                   slidingWindow);
}

long long BestTimeToBuyAndSellStockUsingStrategySolution::maxProfit(
    std::vector<int>& prices, std::vector<int>& strategy, int k) {
  return getSolution()(prices, strategy, k);
}

}  // namespace problem_3652
}  // namespace leetcode
