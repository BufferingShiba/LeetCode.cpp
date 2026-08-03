#include "leetcode/problems/min-cost-climbing-stairs.h"

namespace leetcode {
namespace problem_746 {
namespace {

int minCostClimbingStairsImpl(std::vector<int>& cost) {
  const int n = static_cast<int>(cost.size());
  if (n == 1) {
    return cost[0];
  }
  int prev = cost[0];          // dp[i-2]
  int curr = cost[1];          // dp[i-1]
  for (int i = 2; i < n; ++i) {
    int next = cost[i] + std::min(prev, curr);
    prev = curr;
    curr = next;
  }
  return std::min(prev, curr);
}

}  // namespace

MinCostClimbingStairsSolution::MinCostClimbingStairsSolution() {
  setMetaInfo({.id = 746,
               .title = "Min Cost Climbing Stairs",
               .url = "https://leetcode.com/problems/min-cost-climbing-stairs/"});
  registerStrategy({.name = "DP-O(1)",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Dynamic Programming"}},
                   minCostClimbingStairsImpl);
}

int MinCostClimbingStairsSolution::minCostClimbingStairs(std::vector<int>& cost) {
  return getSolution()(cost);
}

}  // namespace problem_746
}  // namespace leetcode
