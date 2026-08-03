#include "leetcode/problems/find-the-count-of-monotonic-pairs-i.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3250 {

namespace {

constexpr int kMod = 1'000'000'007;

int countOfPairsImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int max_val = *std::max_element(nums.begin(), nums.end());

  // dp[v] = number of valid sequences for current prefix ending with x_i = v
  std::vector<int> dp(max_val + 1, 0);
  for (int v = 0; v <= nums[0]; ++v) {
    dp[v] = 1;
  }

  for (int i = 1; i < n; ++i) {
    int prev_max = nums[i - 1];
    int cur_max = nums[i];
    int d = std::max(0, nums[i] - nums[i - 1]);

    // Prefix sum of dp for fast range sum queries
    std::vector<int> prefix(prev_max + 2, 0);
    for (int v = 0; v <= prev_max; ++v) {
      prefix[v + 1] = (prefix[v] + dp[v]) % kMod;
    }

    std::vector<int> new_dp(cur_max + 1, 0);
    for (int v2 = d; v2 <= cur_max; ++v2) {
      // v1 <= v2 - d, and v1 <= prev_max
      int max_v1 = std::min(v2 - d, prev_max);
      if (max_v1 >= 0) {
        new_dp[v2] = prefix[max_v1 + 1];  // sum_{v=0}^{max_v1} dp[v]
      }
    }

    dp.swap(new_dp);
  }

  int total = 0;
  for (int v = 0; v <= nums.back(); ++v) {
    total = (total + dp[v]) % kMod;
  }
  return total;
}

}  // namespace

FindTheCountOfMonotonicPairsISolution::FindTheCountOfMonotonicPairsISolution() {
  setMetaInfo({.id = 3250,
               .title = "Find the Count of Monotonic Pairs I",
               .url = "https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i/"});

  registerStrategy(
      {.name = "DP with Prefix Sum",
       .expected = "Accepted",
       .time_complexity = "O(n * M)",
       .space_complexity = "O(M)",
       .tags = {"Array", "Math", "Dynamic Programming", "Combinatorics", "Prefix Sum"}},
      countOfPairsImpl);

  setDefaultStrategy();
}

int FindTheCountOfMonotonicPairsISolution::countOfPairs(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3250
}  // namespace leetcode
