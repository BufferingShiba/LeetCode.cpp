#include "leetcode/problems/find-the-minimum-cost-array-permutation.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_3149 {

namespace {

constexpr int kInf = 1e9;

std::vector<int> findPermutationImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int full = (1 << n) - 1;

  // dp[mask][last] = min score to finish the tour from state (mask, last)
  std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, kInf));

  // base: all nodes visited, need to return to 0
  for (int last = 0; last < n; ++last) {
    dp[full][last] = std::abs(last - nums[0]);
  }

  // fill dp from full-1 down to 1
  for (int mask = full - 1; mask >= 1; --mask) {
    if (!(mask & 1)) continue;  // node 0 must be in mask
    for (int last = 0; last < n; ++last) {
      if (!(mask & (1 << last))) continue;
      int best = kInf;
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) continue;
        int cand = std::abs(last - nums[j]) + dp[mask | (1 << j)][j];
        if (cand < best) best = cand;
      }
      dp[mask][last] = best;
    }
  }

  // reconstruct the lexicographically smallest optimal permutation
  std::vector<int> perm;
  perm.reserve(n);
  perm.push_back(0);
  int mask = 1;   // only node 0
  int last = 0;

  while (mask != full) {
    for (int j = 0; j < n; ++j) {
      if (mask & (1 << j)) continue;
      if (dp[mask][last] == std::abs(last - nums[j]) + dp[mask | (1 << j)][j]) {
        perm.push_back(j);
        mask |= (1 << j);
        last = j;
        break;
      }
    }
  }

  return perm;
}

}  // namespace

FindTheMinimumCostArrayPermutationSolution::FindTheMinimumCostArrayPermutationSolution() {
  setMetaInfo({.id = 3149,
               .title = "Find the Minimum Cost Array Permutation",
               .url = "https://leetcode.com/problems/find-the-minimum-cost-array-permutation/"});
  registerStrategy(
      {.name = "bitmask_dp",
       .expected = "Accepted",
       .time_complexity = "O(n^2 * 2^n)",
       .space_complexity = "O(n * 2^n)",
       .tags = {"Array", "Dynamic Programming", "Bit Manipulation", "Bitmask"}},
      findPermutationImpl);
}

std::vector<int> FindTheMinimumCostArrayPermutationSolution::findPermutation(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3149
