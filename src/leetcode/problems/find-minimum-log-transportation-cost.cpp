#include "leetcode/problems/find-minimum-log-transportation-cost.h"

namespace leetcode {
namespace problem_3560 {

namespace {

long long minCuttingCostImpl(int n, int m, int k) {
  const long long kk = k;
  const long long nn = n;
  const long long mm = m;
  if (nn <= kk && mm <= kk) {
    return 0;
  }
  if (nn > kk) {
    return kk * (nn - kk);
  }
  return kk * (mm - kk);
}

}  // namespace

long long FindMinimumLogTransportationCostSolution::minCuttingCost(
    int n, int m, int k) {
  return getSolution()(n, m, k);
}

FindMinimumLogTransportationCostSolution::FindMinimumLogTransportationCostSolution() {
  setMetaInfo({.id = 3560,
               .title = "Find Minimum Log Transportation Cost",
               .url = "https://leetcode.com/problems/find-minimum-log-"
                       "transportation-cost/"});
  registerStrategy(
      {.name = "MathO1",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"},
       .notes =
           "If both logs fit (<=k) cost is 0; otherwise cut the over-long log "
           "into k and (L-k), costing k*(L-k)."},
      minCuttingCostImpl);
}

}  // namespace problem_3560
}  // namespace leetcode
