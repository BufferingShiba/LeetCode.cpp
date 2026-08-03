#include "leetcode/problems/partition-to-k-equal-sum-subsets.h"

#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_698 {

namespace {

// Bitmask DP.
// dp[mask] = remaining units accumulated in the current subset after using
// the elements selected by mask (value in [0, target)). dp = -1 means
// unreachable.
bool canPartitionKSubsetsImpl(std::vector<int>& nums, int k) {
  int total = std::accumulate(nums.begin(), nums.end(), 0);
  if (k == 0 || total % k != 0) {
    return false;
  }
  int target = total / k;
  int n = static_cast<int>(nums.size());

  std::vector<int> dp(1 << n, -1);
  dp[0] = 0;

  for (int mask = 0; mask < (1 << n); ++mask) {
    if (dp[mask] == -1) {
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        continue;
      }
      int nxt = dp[mask] + nums[i];
      if (nxt > target) {
        continue;
      }
      dp[mask | (1 << i)] = nxt % target;
    }
  }

  return dp[(1 << n) - 1] == 0;
}

}  // namespace

PartitionToKEqualSumSubsetsSolution::PartitionToKEqualSumSubsetsSolution() {
  setMetaInfo({.id = 698,
               .title = "Partition to K Equal Sum Subsets",
               .url =
                   "https://leetcode.com/problems/partition-to-k-equal-sum-subsets/"});
  registerStrategy(
      {.name = "bitmask-dp",
       .expected = "Accepted",
       .time_complexity = "O(n * 2^n)",
       .space_complexity = "O(2^n)",
       .tags = {"Dynamic Programming", "Bit Manipulation", "Bitmask",
                 "Array"}},
      canPartitionKSubsetsImpl);
}

bool PartitionToKEqualSumSubsetsSolution::canPartitionKSubsets(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_698
}  // namespace leetcode
