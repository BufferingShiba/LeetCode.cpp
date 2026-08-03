#include <vector>

#include "leetcode/problems/minimum-total-space-wasted-with-k-resizing-operations.h"

namespace leetcode {
namespace problem_1959 {

namespace {

int minSpaceWastedKResizingImpl(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  // prefix[i] = sum of nums[0..i-1]
  std::vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + nums[i];
  }

  // cost[l][r]: minimal wasted space for interval [l, r) using a single size.
  // That is max(nums[l..r-1]) * (r - l) - sum(nums[l..r-1]).
  std::vector<std::vector<long long>> cost(
      n, std::vector<long long>(n + 1, 0));
  for (int l = 0; l < n; ++l) {
    long long mx = 0;
    for (int r = l + 1; r <= n; ++r) {
      mx = std::max(mx, static_cast<long long>(nums[r - 1]));
      cost[l][r] = mx * (r - l) - (prefix[r] - prefix[l]);
    }
  }

  const long long INF = static_cast<long long>(1e18);
  // dp[j][i]: minimal wasted space for prefix [0, i) using at most j resizes.
  std::vector<std::vector<long long>> dp(
      k + 1, std::vector<long long>(n + 1, INF));
  for (int i = 0; i <= n; ++i) {
    dp[0][i] = cost[0][i];
  }

  for (int j = 1; j <= k; ++j) {
    for (int i = 0; i <= n; ++i) {
      dp[j][i] = dp[j - 1][i];
      for (int l = 0; l < i; ++l) {
        dp[j][i] = std::min(dp[j][i], dp[j - 1][l] + cost[l][i]);
      }
    }
  }

  return static_cast<int>(std::min(dp[k][n], static_cast<long long>(INT_MAX)));
}

}  // namespace

MinimumTotalSpaceWastedWithKResizingOperationsSolution::
    MinimumTotalSpaceWastedWithKResizingOperationsSolution() {
  setMetaInfo(
      {.id = 1959,
       .title = "Minimum Total Space Wasted With K Resizing Operations",
       .url = "https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/"});
  registerStrategy(
      {.name = "dp",
       .expected = "Accepted",
       .time_complexity = "O(n^2 * k)",
       .space_complexity = "O(n^2 + n*k)",
       .tags = {"Dynamic Programming", "Prefix Sum"}},
      minSpaceWastedKResizingImpl);
}

int MinimumTotalSpaceWastedWithKResizingOperationsSolution::
    minSpaceWastedKResizing(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_1959
}  // namespace leetcode
