#include "leetcode/problems/minimum-cost-to-reach-every-position.h"

#include <algorithm>

namespace leetcode::problem_3502 {

namespace {

// answer[i] = min(cost[0..i])：支付一次从已遇到最便宜的人开始，后续免费到达。
std::vector<int> minCostsImpl(std::vector<int>& cost) {
  std::vector<int> answer(cost.size());
  int best = cost[0];
  for (std::size_t i = 0; i < cost.size(); ++i) {
    best = std::min(best, cost[i]);
    answer[i] = best;
  }
  return answer;
}

}  // namespace

MinimumCostToReachEveryPositionSolution::MinimumCostToReachEveryPositionSolution() {
  setMetaInfo({.id = 3502,
               .title = "Minimum Cost to Reach Every Position",
               .url =
                   "https://leetcode.com/problems/minimum-cost-to-reach-every-position/"});
  registerStrategy(
      {.name = "prefix_min",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      minCostsImpl);
}

std::vector<int> MinimumCostToReachEveryPositionSolution::minCosts(
    std::vector<int>& cost) {
  return getSolution()(cost);
}

}  // namespace leetcode::problem_3502
