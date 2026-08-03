#include "leetcode/problems/minimum-operations-to-achieve-at-least-k-peaks.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3892 {

using Func = std::function<int(std::vector<int>&, int)>;

namespace {

constexpr long long kInf = 1e18;

// DP on linear subarray cost[l..r] (inclusive).
// Returns min cost to select exactly `need` non-adjacent elements, or -1 if impossible.
long long dpSelect(const std::vector<long long>& cost, int l, int r, int need) {
  if (need == 0) return 0;
  int m = r - l + 1;
  if (m <= 0) return -1;
  int maxPossible = (m + 1) / 2;
  if (need > maxPossible) return -1;

  std::vector<long long> dp_prev2(need + 1, kInf);  // i-2
  std::vector<long long> dp_prev1(need + 1, kInf);  // i-1
  std::vector<long long> dp_cur(need + 1, kInf);    // current i

  // i = 0 (empty set)
  dp_prev2[0] = 0;

  // i = 1 (first element at index l)
  dp_prev1[0] = 0;
  dp_prev1[1] = cost[l];

  for (int i = 2; i <= m; ++i) {
    std::fill(dp_cur.begin(), dp_cur.end(), kInf);
    int idx = l + i - 1;
    for (int j = 0; j <= need; ++j) {
      // skip element idx
      dp_cur[j] = dp_prev1[j];
      // take element idx
      if (j >= 1 && dp_prev2[j - 1] < kInf) {
        long long val = dp_prev2[j - 1] + cost[idx];
        if (val < dp_cur[j]) dp_cur[j] = val;
      }
    }
    dp_prev2 = dp_prev1;
    dp_prev1 = dp_cur;
  }

  long long result = (m >= 1) ? dp_prev1[need] : dp_prev2[need];
  return (result >= kInf) ? -1 : result;
}

int minOperationsImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());
  if (k == 0) return 0;

  // At most floor(n/2) peaks can exist (peaks cannot be adjacent in a circular array).
  int maxPeaks = n / 2;
  if (k > maxPeaks) return -1;

  // Cost to make each position a peak (assuming neighbors unchanged).
  std::vector<long long> cost(n);
  for (int i = 0; i < n; ++i) {
    int prev = nums[(i - 1 + n) % n];
    int next = nums[(i + 1) % n];
    int target = std::max(prev, next) + 1;
    cost[i] = std::max(0LL, static_cast<long long>(target) - nums[i]);
  }

  long long ans = kInf;

  // Case 1: do NOT pick position 0.
  // Need exactly k peaks from indices [1, n-1] (non-circular).
  {
    long long sub = dpSelect(cost, 1, n - 1, k);
    if (sub >= 0) ans = std::min(ans, sub);
  }

  // Case 2: pick position 0.
  // Need exactly (k-1) peaks from indices [2, n-2] (non-circular, excluding neighbours of 0).
  if (k >= 1) {
    long long sub = 0;
    int need = k - 1;
    if (need == 0) {
      sub = 0;
    } else {
      sub = dpSelect(cost, 2, n - 2, need);
      if (sub < 0) sub = kInf;
    }
    if (sub < kInf) {
      ans = std::min(ans, cost[0] + sub);
    }
  }

  return (ans >= kInf) ? -1 : static_cast<int>(ans);
}

}  // namespace

MinimumOperationsToAchieveAtLeastKPeaksSolution::MinimumOperationsToAchieveAtLeastKPeaksSolution() {
  setMetaInfo({.id = 3892,
               .title = "Minimum Operations to Achieve At Least K Peaks",
               .url = "https://leetcode.com/problems/minimum-operations-to-achieve-at-least-k-peaks/"});
  registerStrategy({.name = "DP",
                    .expected = "Accepted",
                    .time_complexity = "O(n*k)",
                    .space_complexity = "O(k)",
                    .tags = {"Array", "Dynamic Programming"}},
                   minOperationsImpl);
}

int MinimumOperationsToAchieveAtLeastKPeaksSolution::minOperations(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3892
}  // namespace leetcode
