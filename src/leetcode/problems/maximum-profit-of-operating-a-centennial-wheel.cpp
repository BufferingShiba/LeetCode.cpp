#include "leetcode/problems/maximum-profit-of-operating-a-centennial-wheel.h"

#include <algorithm>

namespace leetcode::problem_1599 {

namespace {

int minOperationsMaxProfitImpl(std::vector<int>& customers, int boardingCost,
                               int runningCost) {
  int waiting = 0;
  int total_boarded = 0;
  int max_profit = 0;
  int best_rotation = -1;
  int n = static_cast<int>(customers.size());

  int rotation = 0;
  // Continue while there are customers yet to arrive or people waiting
  while (rotation < n || waiting > 0) {
    // New customers arrive before this rotation
    if (rotation < n) {
      waiting += customers[rotation];
    }

    // Board up to 4 people
    int boarded = std::min(4, waiting);
    waiting -= boarded;
    total_boarded += boarded;

    // Current profit after this rotation
    int profit = total_boarded * boardingCost - (rotation + 1) * runningCost;

    if (profit > max_profit) {
      max_profit = profit;
      best_rotation = rotation + 1;
    }

    ++rotation;
  }

  return best_rotation;
}

}  // namespace

MaximumProfitOfOperatingACentennialWheelSolution::
    MaximumProfitOfOperatingACentennialWheelSolution() {
  setMetaInfo({.id = 1599,
               .title = "Maximum Profit of Operating a Centennial Wheel",
               .url = "https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/"});

  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n + total_customers/4)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Simulation"}},
      minOperationsMaxProfitImpl);

  setDefaultStrategy();
}

int MaximumProfitOfOperatingACentennialWheelSolution::minOperationsMaxProfit(
    std::vector<int>& customers, int boardingCost, int runningCost) {
  return getSolution()(customers, boardingCost, runningCost);
}

}  // namespace leetcode::problem_1599
