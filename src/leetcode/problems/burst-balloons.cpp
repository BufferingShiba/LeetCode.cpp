#include "leetcode/problems/burst-balloons.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_312 {

namespace {

int maxCoinsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  // Pad the balloon array with virtual 1s at both ends.
  std::vector<int> padd(n + 2, 1);
  for (int i = 0; i < n; ++i) {
    padd[i + 1] = nums[i];
  }

  // dp[i][j]: max coins from bursting all balloons inside open interval (i, j),
  // where i and j are boundaries that are not burst.
  std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));

  for (int len = 2; len < n + 2; ++len) {
    for (int i = 0; i + len < n + 2; ++i) {
      const int j = i + len;
      for (int k = i + 1; k < j; ++k) {
        dp[i][j] = std::max(
            dp[i][j],
            dp[i][k] + dp[k][j] + padd[i] * padd[k] * padd[j]);
      }
    }
  }

  return dp[0][n + 1];
}

}  // namespace

BurstBalloonsSolution::BurstBalloonsSolution() {
  setMetaInfo({.id = 312,
               .title = "Burst Balloons",
               .url = "https://leetcode.com/problems/burst-balloons/"});
  registerStrategy(
      {.name = "interval-dp",
       .expected = "Accepted",
       .time_complexity = "O(n^3)",
       .space_complexity = "O(n^2)",
       .tags = {"Array", "Dynamic Programming"}},
      maxCoinsImpl);
}

int BurstBalloonsSolution::maxCoins(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_312
