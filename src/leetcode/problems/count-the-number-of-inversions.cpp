#include "leetcode/problems/count-the-number-of-inversions.h"

#include <vector>
#include <algorithm>

namespace leetcode {
namespace problem_3193 {

namespace {

const int MOD = 1000000007;

int numberOfPermutationsImpl(int n, std::vector<std::vector<int>>& requirements) {
  // req[pos] = required inversion count for prefix ending at pos, or -1 if none.
  std::vector<int> req(n, -1);
  int maxCnt = 0;
  for (const auto& r : requirements) {
    req[r[0]] = r[1];
    maxCnt = std::max(maxCnt, r[1]);
  }

  // dp[j] = number of ways for prefix of current length with exactly j inversions.
  std::vector<long long> dp(maxCnt + 1, 0);
  dp[0] = 1;  // empty prefix has 0 inversions.

  // Process element insertion position by position. At step i (0-based we place the
  // (i+1)-th element, inserting it adds between 0 and i new inversions.
  // For i = 0, adding the first element adds 0 inversions -> handled by i loop from 1.
  for (int i = 1; i < n; ++i) {
    // prefix sums of dp to enable O(1) transitions.
    std::vector<long long> prefix(maxCnt + 1, 0);
    prefix[0] = dp[0] % MOD;
    for (int j = 1; j <= maxCnt; ++j) {
      prefix[j] = (prefix[j - 1] + dp[j]) % MOD;
    }

    std::vector<long long> next(maxCnt + 1, 0);
    // For each target inversion count j, next[j] = sum_{k=0}^{min(j,i)} dp[j-k]
    // equivalently = prefix[j] - (j-i > 0 ? prefix[j-i-1] : 0).
    for (int j = 0; j <= maxCnt; ++j) {
      int low = j - i;  // smallest dp index contributing: dp[j-k] with k <= i means j-k >= j-i
      long long val = prefix[j];
      if (low > 0) {
        val = (val - prefix[low - 1] + MOD) % MOD;
      }
      next[j] = val;
    }

    if (req[i] != -1) {
      // Pin to the required count.
      std::vector<long long> pinned(maxCnt + 1, 0);
      pinned[req[i]] = next[req[i]];
      next.swap(pinned);
    }
    dp.swap(next);
  }

  int target = req[n - 1];
  return static_cast<int>(dp[target] % MOD);
}

}  // namespace

CountTheNumberOfInversionsSolution::CountTheNumberOfInversionsSolution() {
  setMetaInfo({.id = 3193,
               .title = "Count the Number of Inversions",
               .url = "https://leetcode.com/problems/count-the-number-of-inversions/"});
  registerStrategy({.name = "dp_prefix_sum",
                    .expected = "Accepted",
                    .time_complexity = "O(n * maxCnt)",
                    .space_complexity = "O(maxCnt)",
                    .tags = {"Dynamic Programming", "Prefix Sum"}},
                   numberOfPermutationsImpl);
}

int CountTheNumberOfInversionsSolution::numberOfPermutations(int n, std::vector<std::vector<int>>& requirements) {
  return getSolution()(n, requirements);
}

}  // namespace problem_3193
}  // namespace leetcode
