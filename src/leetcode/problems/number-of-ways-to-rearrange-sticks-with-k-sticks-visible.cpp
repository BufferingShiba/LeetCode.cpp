#include "leetcode/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible.h"

#include <vector>

namespace leetcode::problem_1866 {

namespace {

constexpr int kMod = 1'000'000'007;

int rearrangeSticksImpl(int n, int k) {
  // dp[j] = number of ways for current i with exactly j visible sticks
  std::vector<int> dp(k + 1, 0);
  dp[0] = 1;  // dp[0][0] = 1

  for (int i = 1; i <= n; ++i) {
    // Update dp[j] for j from min(i, k) down to 1
    int limit = std::min(i, k);
    for (int j = limit; j >= 1; --j) {
      dp[j] = static_cast<int>((static_cast<long long>(dp[j - 1]) +
                                 static_cast<long long>(i - 1) * dp[j]) %
                                kMod);
    }
    dp[0] = 0;  // dp[i][0] = 0 for i > 0
  }

  return dp[k];
}

}  // namespace

NumberOfWaysToRearrangeSticksWithKSticksVisibleSolution::
    NumberOfWaysToRearrangeSticksWithKSticksVisibleSolution() {
  setMetaInfo({.id = 1866,
               .title = "Number of Ways to Rearrange Sticks With K Sticks Visible",
               .url = "https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/"});

  registerStrategy(
      {.name = "DP (unsigned Stirling numbers of the first kind)",
       .expected = "Accepted",
       .time_complexity = "O(n * k)",
       .space_complexity = "O(k)",
       .tags = {"Math", "Dynamic Programming", "Combinatorics"}},
      rearrangeSticksImpl);
}

int NumberOfWaysToRearrangeSticksWithKSticksVisibleSolution::rearrangeSticks(int n, int k) {
  return getSolution()(n, k);
}

}  // namespace leetcode::problem_1866
