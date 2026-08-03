#include "leetcode/problems/shopping-offers.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_638 {

namespace {

int dfsState(const std::vector<int>& price,
             const std::vector<std::vector<int>>& special,
             const std::vector<int>& needs,
             std::unordered_map<int, int>& memo) {
  const int n = static_cast<int>(needs.size());

  // Encode needs into a key (each needs[i] <= 10, fits in 4 bits).
  int key = 0;
  for (int i = 0; i < n; ++i) {
    key |= needs[i] << (4 * i);
  }
  auto it = memo.find(key);
  if (it != memo.end()) return it->second;

  // Baseline: buy every remaining item at the unit price.
  int cost = 0;
  for (int i = 0; i < n; ++i) {
    cost += price[i] * needs[i];
  }

  // Try every applicable special offer.
  for (const auto& offer : special) {
    bool valid = true;
    for (int i = 0; i < n; ++i) {
      if (offer[i] > needs[i]) {
        valid = false;
        break;
      }
    }
    if (!valid) continue;

    std::vector<int> next = needs;
    for (int i = 0; i < n; ++i) next[i] -= offer[i];
    cost = std::min(cost, offer[n] + dfsState(price, special, next, memo));
  }

  memo[key] = cost;
  return cost;
}

int shoppingOffersImpl(std::vector<int>& price,
                       std::vector<std::vector<int>>& special,
                       std::vector<int>& needs) {
  const int n = static_cast<int>(price.size());

  // Keep only special offers that are cheaper than buying the same items individually.
  std::vector<std::vector<int>> filtered;
  for (const auto& offer : special) {
    int individual = 0;
    for (int i = 0; i < n; ++i) {
      individual += price[i] * offer[i];
    }
    if (individual > offer[n]) {
      filtered.push_back(offer);
    }
  }

  std::unordered_map<int, int> memo;
  return dfsState(price, filtered, needs, memo);
}

}  // namespace

ShoppingOffersSolution::ShoppingOffersSolution() {
  setMetaInfo({.id = 638,
               .title = "Shopping Offers",
               .url = "https://leetcode.com/problems/shopping-offers/"});
  registerStrategy(
      {.name = "DFSWithMemoization",
       .expected = "Accepted",
       .time_complexity = "O(states * offers)",
       .space_complexity = "O(states * n)",
       .tags = {"Dynamic Programming", "Backtracking", "Memoization", "DFS"}},
      shoppingOffersImpl);
}

}  // namespace problem_638
}  // namespace leetcode
