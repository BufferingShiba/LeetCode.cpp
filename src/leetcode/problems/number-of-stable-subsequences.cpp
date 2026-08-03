#include "leetcode/problems/number-of-stable-subsequences.h"

#include <array>

namespace leetcode {
namespace problem_3686 {
namespace {

const long long kMod = 1000000007LL;

long long countStableSubsequencesImpl(std::vector<int>& nums) {
  // dp[x][l]: number of stable subsequences ending at parity x (0=even, 1=odd)
  // with a trailing run of exactly l equal parities (l = 1 or 2).
  // Empty subsequence is not counted.
  std::array<std::array<long long, 3>, 2> dp{};  // l in {1,2}, dp[...][0] unused

  for (int v : nums) {
    int p = v & 1;
    // Copy current state first (skip this element).
    auto nxt = dp;
    // {v} alone: starts a run of length 1 (also equivalent to appending to empty).
    nxt[p][1] = (nxt[p][1] + 1) % kMod;
    // Append to subsequences ending at the opposite parity -> new trailing run length 1.
    int op = 1 - p;
    nxt[p][1] = (nxt[p][1] + dp[op][1] + dp[op][2]) % kMod;
    // Append to subsequences ending at same parity with trailing run length 1 -> run length 2.
    nxt[p][2] = (nxt[p][2] + dp[p][1]) % kMod;
    // Appending to same-parity trailing run length 2 would create a triple -> forbidden, skip.
    dp = nxt;
  }

  long long ans = 0;
  for (int x = 0; x < 2; ++x) {
    ans = (ans + dp[x][1] + dp[x][2]) % kMod;
  }
  return ans;
}

}  // namespace

NumberOfStableSubsequencesSolution::NumberOfStableSubsequencesSolution() {
  setMetaInfo({.id = 3686,
               .title = "Number of Stable Subsequences",
               .url = "https://leetcode.com/problems/number-of-stable-subsequences/"});
  registerStrategy(
      {.name = "dp_trailing_run_count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Dynamic Programming"},
       .notes = "Track stable subsequences by last element parity and trailing run length (1 or 2); O(n) single pass."},
      countStableSubsequencesImpl);
}

int NumberOfStableSubsequencesSolution::countStableSubsequences(std::vector<int>& nums) {
  return static_cast<int>(getSolution()(nums));
}

}  // namespace problem_3686
}  // namespace leetcode
