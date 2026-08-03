#include "leetcode/problems/minimum-cost-for-tickets.h"

namespace leetcode {
namespace problem_983 {

namespace {

int mincostTicketsImpl(std::vector<int>& days, std::vector<int>& costs) {
  const int lastDay = days.back();
  std::vector<bool> travel(lastDay + 1, false);
  for (int d : days) travel[d] = true;

  std::vector<int> dp(lastDay + 1, 0);
  for (int d = 1; d <= lastDay; ++d) {
    if (!travel[d]) {
      dp[d] = dp[d - 1];
      continue;
    }
    int best = dp[d - 1] + costs[0];
    best = std::min(best, dp[std::max(0, d - 7)] + costs[1]);
    best = std::min(best, dp[std::max(0, d - 30)] + costs[2]);
    dp[d] = best;
  }
  return dp[lastDay];
}

}  // namespace

MinimumCostForTicketsSolution::MinimumCostForTicketsSolution() {
  this->setMetaInfo({.id = 983,
                     .title = "Minimum Cost For Tickets",
                     .url = "https://leetcode.com/problems/minimum-cost-for-tickets/"});
  this->registerStrategy(
      {.name = "dp-by-day",
       .expected = "Accepted",
       .time_complexity = "O(D)",
       .space_complexity = "O(D)",
       .tags = {"Array", "Dynamic Programming"}},
      mincostTicketsImpl);
}

int MinimumCostForTicketsSolution::mincostTickets(std::vector<int>& days,
                                                  std::vector<int>& costs) {
  return this->getSolution()(days, costs);
}

}  // namespace problem_983
}  // namespace leetcode
