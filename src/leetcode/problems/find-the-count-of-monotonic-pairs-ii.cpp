#include "leetcode/problems/find-the-count-of-monotonic-pairs-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3251 {
namespace {

constexpr int kMod = 1000000007;

// dp[i][b] = number of valid prefixes where arr1[i] == b.
// Transition: dp[i+1][b] = sum_{a <= min(b, b + nums[i] - nums[i+1])} dp[i][a].
int countOfPairsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int maxVal = 0;
  for (int v : nums) maxVal = std::max(maxVal, v);

  std::vector<long long> dp(maxVal + 1, 0);
  for (int b = 0; b <= nums[0]; ++b) dp[b] = 1;

  for (int i = 1; i < n; ++i) {
    std::vector<long long> prefix(maxVal + 1, 0);
    long long running = 0;
    for (int x = 0; x <= maxVal; ++x) {
      running = (running + dp[x]) % kMod;
      prefix[x] = running;
    }

    const int diff = nums[i - 1] - nums[i];
    std::vector<long long> next(maxVal + 1, 0);
    for (int b = 0; b <= nums[i]; ++b) {
      int m = b + std::min(0, diff);
      if (m < 0) continue;
      if (m > maxVal) m = maxVal;
      next[b] = prefix[m];
    }
    dp.swap(next);
  }

  long long ans = 0;
  for (int b = 0; b <= nums[n - 1]; ++b) ans = (ans + dp[b]) % kMod;
  return static_cast<int>(ans);
}

}  // namespace

FindTheCountOfMonotonicPairsIiSolution::FindTheCountOfMonotonicPairsIiSolution() {
  setMetaInfo({.id = 3251,
               .title = "Find the Count of Monotonic Pairs II",
               .url =
                   "https://leetcode.com/problems/find-the-count-of-monotonic-"
                   "pairs-ii/"});
  registerStrategy(
      {.name = "dp",
       .expected = "Accepted",
       .time_complexity = "O(n * max(nums))",
       .space_complexity = "O(max(nums))",
       .tags = {"Dynamic Programming", "Prefix Sum"}},
      countOfPairsImpl);
}

int FindTheCountOfMonotonicPairsIiSolution::countOfPairs(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3251
}  // namespace leetcode
