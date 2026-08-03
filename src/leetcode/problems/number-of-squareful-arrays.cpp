#include "leetcode/problems/number-of-squareful-arrays.h"

#include <algorithm>
#include <cmath>
#include <vector>

namespace leetcode {
namespace problem_996 {

namespace {

bool isPerfectSquare(long long x) {
  long long r = static_cast<long long>(std::sqrt(static_cast<double>(x)));
  // Adjust to exact integer sqrt
  while (r * r > x) --r;
  while ((r + 1) * (r + 1) <= x) ++r;
  return r * r == x;
}

int numSquarefulPermsImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  if (n <= 1) return 0;  // no adjacent pair exists

  std::sort(nums.begin(), nums.end());

  // Precompute adjacency: ok[i][j] = true iff nums[i]+nums[j] is perfect square
  std::vector<std::vector<bool>> ok(n, std::vector<bool>(n, false));
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      long long sum = static_cast<long long>(nums[i]) + nums[j];
      if (isPerfectSquare(sum)) {
        ok[i][j] = ok[j][i] = true;
      }
    }
  }

  int totalMasks = 1 << n;
  std::vector<std::vector<int>> dp(totalMasks, std::vector<int>(n, 0));

  // Initialize: single element paths (only the first of each value group)
  for (int i = 0; i < n; ++i) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;
    dp[1 << i][i] = 1;
  }

  // DP over masks
  for (int mask = 0; mask < totalMasks; ++mask) {
    for (int last = 0; last < n; ++last) {
      if (dp[mask][last] == 0) continue;
      for (int nxt = 0; nxt < n; ++nxt) {
        if (mask & (1 << nxt)) continue;   // already used
        if (!ok[last][nxt]) continue;       // not squareful

        // Dedup: for identical values, enforce index-ascending order
        if (nxt > 0 && nums[nxt] == nums[nxt - 1] &&
            !(mask & (1 << (nxt - 1)))) {
          continue;
        }

        dp[mask | (1 << nxt)][nxt] += dp[mask][last];
      }
    }
  }

  int ans = 0;
  int fullMask = totalMasks - 1;
  for (int i = 0; i < n; ++i) {
    ans += dp[fullMask][i];
  }
  return ans;
}

}  // namespace

NumberOfSquarefulArraysSolution::NumberOfSquarefulArraysSolution() {
  setMetaInfo({.id = 996,
               .title = "Number of Squareful Arrays",
               .url = "https://leetcode.com/problems/number-of-squareful-arrays/"});
  registerStrategy({.name = "Bitmask DP",
                    .expected = "Accepted",
                    .time_complexity = "O(2^n * n^2)",
                    .space_complexity = "O(2^n * n)",
                    .tags = {"Array", "Hash Table", "Math", "Dynamic Programming",
                             "Backtracking", "Bit Manipulation", "Bitmask"}},
                   numSquarefulPermsImpl);
}

int NumberOfSquarefulArraysSolution::numSquarefulPerms(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_996
}  // namespace leetcode
