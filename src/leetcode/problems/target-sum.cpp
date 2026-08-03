#include "leetcode/problems/target-sum.h"

#include <numeric>

namespace leetcode::problem_494 {

namespace {

int findTargetSumWaysImpl(std::vector<int>& nums, int target) {
  int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

  // (totalSum + target) must be non-negative and even
  if (totalSum + target < 0 || (totalSum + target) % 2 != 0) {
    return 0;
  }

  int subsetSum = (totalSum + target) / 2;

  // dp[j] = number of ways to achieve sum j
  std::vector<int> dp(subsetSum + 1, 0);
  dp[0] = 1;

  for (int num : nums) {
    for (int j = subsetSum; j >= num; --j) {
      dp[j] += dp[j - num];
    }
  }

  return dp[subsetSum];
}

}  // namespace

TargetSumSolution::TargetSumSolution() {
  setMetaInfo({.id = 494, .title = "Target Sum", .url = "https://leetcode.com/problems/target-sum/"});
  registerStrategy(
      {.name = "Subset Sum DP",
       .expected = "Accepted",
       .time_complexity = "O(n * sum)",
       .space_complexity = "O(sum)",
       .tags = {"Array", "Dynamic Programming", "Backtracking"}},
      findTargetSumWaysImpl);
}

int TargetSumSolution::findTargetSumWays(std::vector<int>& nums, int target) {
  return getSolution()(nums, target);
}

}  // namespace leetcode::problem_494
