#include "leetcode/problems/special-permutations.h"

namespace leetcode {
namespace problem_2741 {

namespace {

static constexpr int MOD = 1000000007;

}  // namespace

static int specialPermImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int total = 1 << n;
  // dp[mask][last] = number of ways to form a permutation using elements in
  // `mask` with nums[last] as the last element.
  std::vector<std::vector<int>> dp(total, std::vector<int>(n, 0));

  // Base case: permutations of length 1.
  for (int i = 0; i < n; ++i) {
    dp[1 << i][i] = 1;
  }

  // Transition.
  for (int mask = 0; mask < total; ++mask) {
    for (int last = 0; last < n; ++last) {
      int cur = dp[mask][last];
      if (cur == 0) continue;
      for (int nxt = 0; nxt < n; ++nxt) {
        if (mask & (1 << nxt)) continue;  // already used
        if (nums[last] % nums[nxt] == 0 || nums[nxt] % nums[last] == 0) {
          int nxt_mask = mask | (1 << nxt);
          dp[nxt_mask][nxt] = (dp[nxt_mask][nxt] + cur) % MOD;
        }
      }
    }
  }

  int ans = 0;
  int full_mask = total - 1;
  for (int last = 0; last < n; ++last) {
    ans = (ans + dp[full_mask][last]) % MOD;
  }
  return ans;
}

SpecialPermutationsSolution::SpecialPermutationsSolution() {
  setMetaInfo({.id = 2741,
               .title = "Special Permutations",
               .url = "https://leetcode.com/problems/special-permutations/"});
  registerStrategy(
      {.name = "DP with Bitmask",
       .expected = "Accepted",
       .time_complexity = "O(n^2 * 2^n)",
       .space_complexity = "O(n * 2^n)",
       .tags = {"Array", "Dynamic Programming", "Bit Manipulation", "Bitmask"}},
      specialPermImpl);
}

int SpecialPermutationsSolution::specialPerm(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2741
}  // namespace leetcode
