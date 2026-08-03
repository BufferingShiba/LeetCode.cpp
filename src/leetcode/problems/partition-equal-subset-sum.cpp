#include "leetcode/problems/partition-equal-subset-sum.h"

#include <numeric>

namespace leetcode {
namespace problem_416 {

static bool solution1(vector<int>& nums) {
  int total = std::accumulate(nums.begin(), nums.end(), 0);
  if (total % 2 != 0) {
    return false;
  }
  int target = total / 2;
  std::vector<bool> dp(target + 1, false);
  dp[0] = true;
  for (int num : nums) {
    for (int j = target; j >= num; --j) {
      if (dp[j - num]) {
        dp[j] = true;
      }
    }
    if (dp[target]) {
      return true;
    }
  }
  return dp[target];
}

PartitionEqualSubsetSumSolution::PartitionEqualSubsetSumSolution() {
  setMetaInfo({
      .id = 416,
      .title = "Partition Equal Subset Sum",
      .url = "https://leetcode.com/problems/partition-equal-subset-sum"
  });
  registerStrategy({.name = "0/1 Knapsack（子集和 DP）",
                    .time_complexity = "O(N*target)",
                    .space_complexity = "O(target)"},
                   solution1);
}

bool PartitionEqualSubsetSumSolution::canPartition(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_416
}  // namespace leetcode
