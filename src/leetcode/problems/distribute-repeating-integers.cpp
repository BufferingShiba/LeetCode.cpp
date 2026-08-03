#include "leetcode/problems/distribute-repeating-integers.h"

#include <algorithm>
#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_1655 {

namespace {

bool canDistributeImpl(std::vector<int>& nums, std::vector<int>& quantity) {
  int m = static_cast<int>(quantity.size());
  int full = 1 << m;

  // Count frequencies of each unique value (nums values <= 1000).
  std::vector<int> freq(1001, 0);
  for (int v : nums) freq[v]++;
  std::vector<int> freqs;
  for (int v = 1; v <= 1000; ++v) {
    if (freq[v] > 0) freqs.push_back(freq[v]);
  }
  // Process larger frequencies first (prunes the search space).
  std::sort(freqs.rbegin(), freqs.rend());

  // need[sub] = sum of quantities for the subset of customers in sub.
  std::vector<int> need(full, 0);
  for (int sub = 1; sub < full; ++sub) {
    int low = sub & (-sub);
    int bit = __builtin_ctz(low);
    need[sub] = need[sub ^ low] + quantity[bit];
  }

  // dp[mask] = true if we can exactly satisfy the customer set mask so far.
  std::vector<char> dp(full, 0);
  dp[0] = 1;

  for (int f : freqs) {
    std::vector<char> next = dp;
    for (int mask = 0; mask < full; ++mask) {
      if (!dp[mask]) continue;
      int rem = (full - 1) ^ mask;
      for (int sub = rem; sub > 0; sub = (sub - 1) & rem) {
        if (need[sub] <= f) {
          next[mask | sub] = 1;
        }
      }
    }
    dp.swap(next);
    if (dp[full - 1]) return true;
  }

  return dp[full - 1];
}

}  // namespace

DistributeRepeatingIntegersSolution::DistributeRepeatingIntegersSolution() {
  setMetaInfo({
      .id = 1655,
      .title = "Distribute Repeating Integers",
      .url = "https://leetcode.com/problems/distribute-repeating-integers/",
  });
  registerStrategy(
      {
          .name = "BitmaskDP",
          .expected = "Accepted",
          .time_complexity = "O(u * 3^m)",
          .space_complexity = "O(2^m)",
          .tags = {"Array", "Hash Table", "Dynamic Programming", "Backtracking", "Bit Manipulation"},
      },
      canDistributeImpl);
}

bool DistributeRepeatingIntegersSolution::canDistribute(
    std::vector<int>& nums, std::vector<int>& quantity) {
  return getSolution()(nums, quantity);
}

}  // namespace problem_1655
}  // namespace leetcode
