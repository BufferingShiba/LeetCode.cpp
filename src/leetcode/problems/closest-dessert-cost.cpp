#include "leetcode/problems/closest-dessert-cost.h"

#include <algorithm>
#include <cstdlib>
#include <functional>

namespace leetcode {
namespace problem_1774 {

namespace {

void dfs(const std::vector<int>& toppingCosts, int idx, int current,
         int target, int& best) {
  // Update best: current is a possible topping combination cost
  if (std::abs(current - target) < std::abs(best - target)) {
    best = current;
  } else if (std::abs(current - target) == std::abs(best - target) &&
             current < best) {
    best = current;
  }

  if (idx == static_cast<int>(toppingCosts.size())) {
    return;
  }

  int toppingPrice = toppingCosts[idx];
  // Choose 0, 1, or 2 of this topping
  dfs(toppingCosts, idx + 1, current, target, best);
  dfs(toppingCosts, idx + 1, current + toppingPrice, target, best);
  dfs(toppingCosts, idx + 1, current + 2 * toppingPrice, target, best);
}

int closestCostImpl(std::vector<int>& baseCosts,
                    std::vector<int>& toppingCosts, int target) {
  int best = baseCosts[0];  // at least one base exists

  for (int base : baseCosts) {
    dfs(toppingCosts, 0, base, target, best);
  }

  return best;
}

}  // namespace

ClosestDessertCostSolution::ClosestDessertCostSolution() {
  setMetaInfo({.id = 1774,
               .title = "Closest Dessert Cost",
               .url = "https://leetcode.com/problems/closest-dessert-cost/"});

  registerStrategy(
      {.name = "Backtracking",
       .expected = "Accepted",
       .time_complexity = "O(n * 3^m)",
       .space_complexity = "O(m)",
       .tags = {"Array", "Dynamic Programming", "Backtracking"}},
      closestCostImpl);
}

int ClosestDessertCostSolution::closestCost(
    std::vector<int>& baseCosts, std::vector<int>& toppingCosts, int target) {
  return getSolution()(baseCosts, toppingCosts, target);
}

}  // namespace problem_1774
}  // namespace leetcode
