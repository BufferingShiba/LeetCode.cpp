#include <algorithm>
#include <cstdlib>
#include <vector>

#include "leetcode/problems/maximum-number-of-jumps-to-reach-the-last-index.h"

namespace leetcode {
namespace problem_2770 {
namespace {

int maximumJumpsImpl(std::vector<int>& nums, int target) {
  const int n = static_cast<int>(nums.size());
  std::vector<int> dp(n, -1);
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (dp[j] != -1 && std::abs(static_cast<long long>(nums[i]) - nums[j]) <=
                             static_cast<long long>(target)) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
  }
  return dp[n - 1];
}

}  // namespace

MaximumNumberOfJumpsToReachTheLastIndexSolution::
    MaximumNumberOfJumpsToReachTheLastIndexSolution() {
  setMetaInfo({.id = 2770,
               .title = "Maximum Number of Jumps to Reach the Last Index",
               .url = "https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/"});
  registerStrategy({.name = "DP",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Dynamic Programming"}},
                   maximumJumpsImpl);
  setDefaultStrategy();
}

int MaximumNumberOfJumpsToReachTheLastIndexSolution::maximumJumps(
    std::vector<int>& nums, int target) {
  return getSolution()(nums, target);
}

}  // namespace problem_2770
}  // namespace leetcode
