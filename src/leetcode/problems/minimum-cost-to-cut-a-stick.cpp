#include "leetcode/problems/minimum-cost-to-cut-a-stick.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_1547 {

namespace {

int minCostImpl(int n, std::vector<int>& cuts) {
  std::sort(cuts.begin(), cuts.end());

  // Build extended array: [0, cuts..., n]
  std::vector<int> a;
  a.reserve(cuts.size() + 2);
  a.push_back(0);
  a.insert(a.end(), cuts.begin(), cuts.end());
  a.push_back(n);

  int m = static_cast<int>(a.size());
  std::vector<std::vector<int>> dp(m, std::vector<int>(m, 0));

  // Interval DP: process by increasing length
  for (int len = 2; len < m; ++len) {
    for (int i = 0; i + len < m; ++i) {
      int j = i + len;
      int min_cost = INT_MAX;
      for (int k = i + 1; k < j; ++k) {
        min_cost = std::min(min_cost, dp[i][k] + dp[k][j]);
      }
      dp[i][j] = min_cost + (a[j] - a[i]);
    }
  }

  return dp[0][m - 1];
}

}  // namespace

MinimumCostToCutAStickSolution::MinimumCostToCutAStickSolution() {
  setMetaInfo({.id = 1547,
               .title = "Minimum Cost to Cut a Stick",
               .url = "https://leetcode.com/problems/minimum-cost-to-cut-a-stick/"});

  registerStrategy(
      {.name = "Interval DP",
       .expected = "Accepted",
       .time_complexity = "O(m^3)",
       .space_complexity = "O(m^2)",
       .tags = {"Array", "Dynamic Programming", "Sorting"}},
      minCostImpl);

  setDefaultStrategy();
}

int MinimumCostToCutAStickSolution::minCost(int n, std::vector<int>& cuts) {
  return getSolution()(n, cuts);
}

}  // namespace problem_1547
}  // namespace leetcode
