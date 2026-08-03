#include "leetcode/problems/maximum-number-of-items-from-sale-i.h"

namespace leetcode::problem_3946 {

namespace {

int maximumSaleItemsImpl(std::vector<std::vector<int>>& items, int budget) {
  const int n = static_cast<int>(items.size());

  std::vector<int> factor(n), price(n);
  int min_price = 0x3f3f3f3f;
  for (int i = 0; i < n; ++i) {
    factor[i] = items[i][0];
    price[i] = items[i][1];
    min_price = std::min(min_price, price[i]);
  }

  // bonus[i] = number of j (j != i) such that factor[i] divides factor[j].
  std::vector<int> bonus(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j && factor[j] % factor[i] == 0) {
        ++bonus[i];
      }
    }
  }

  // 0/1 knapsack: dp[w] = max sum of (1 + bonus[i]) over items with total weight w.
  const int MAX_BUDGET = 1500;
  std::vector<int> dp(MAX_BUDGET + 1, -1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    const int w = price[i];
    const int v = 1 + bonus[i];
    for (int c = budget; c >= w; --c) {
      if (dp[c - w] != -1) {
        dp[c] = std::max(dp[c], dp[c - w] + v);
      }
    }
  }

  int best = 0;
  for (int w = 0; w <= budget; ++w) {
    if (dp[w] != -1) {
      best = std::max(best, dp[w] + (budget - w) / min_price);
    }
  }
  return best;
}

}  // namespace

MaximumNumberOfItemsFromSaleISolution::MaximumNumberOfItemsFromSaleISolution() {
  setMetaInfo({.id = 3946,
               .title = "Maximum Number of Items From Sale I",
               .url =
                   "https://leetcode.com/problems/maximum-number-of-items-from-sale-i/"});
  registerStrategy(
      {.name = "knapsack_with_free_bonus",
       .expected = "Accepted",
       .time_complexity = "O(n * budget)",
       .space_complexity = "O(budget)",
       .tags = {"Array", "Dynamic Programming", "Greedy"}},
      maximumSaleItemsImpl);
}

int MaximumNumberOfItemsFromSaleISolution::maximumSaleItems(
    std::vector<std::vector<int>>& items, int budget) {
  return getSolution()(items, budget);
}

}  // namespace leetcode::problem_3946
