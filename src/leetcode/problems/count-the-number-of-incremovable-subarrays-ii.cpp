#include "leetcode/problems/count-the-number-of-incremovable-subarrays-ii.h"

#include <algorithm>

namespace leetcode {
namespace problem_2972 {

long long CountTheNumberOfIncremovableSubarraysIiSolution::
    SolveIncremovableSubarrayCount(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n == 1) {
    return 1;
  }

  // L: last index of the longest strictly increasing prefix.
  int L = 0;
  while (L < n - 1 && nums[L] < nums[L + 1]) {
    ++L;
  }
  // Whole array strictly increasing => every subarray is incremovable.
  if (L == n - 1) {
    return static_cast<long long>(n) * (n + 1) / 2;
  }

  // R: first index of the longest strictly increasing suffix.
  int R = n - 1;
  while (R > 0 && nums[R - 1] < nums[R]) {
    --R;
  }

  // Count removals [i, j]. The remaining nums[0..i-1] and nums[j+1..n-1]
  // must both be strictly increasing and nums[i-1] < nums[j+1] when both
  // sides are non-empty.
  long long ans = 0;

  // i == 0: left part empty, j ranges over [max(0, R-1), n-1].
  ans += static_cast<long long>(n - (R - 1));

  // i >= 1: left prefix must be strictly inc => i - 1 <= L => i <= L + 1.
  // p is the smallest candidate j in the middle range for the current i.
  int p = std::max(1, R - 1);
  for (int i = 1; i <= L + 1 && i < n; ++i) {
    if (p < i) {
      p = i;
    }
    if (p < R - 1) {
      p = R - 1;
    }
    // Move p right while the boundary condition fails (suffix increasing,
    // so p moves monotonically as i grows).
    while (p <= n - 2 && nums[i - 1] >= nums[p + 1]) {
      ++p;
    }
    if (p <= n - 2) {
      // j in [p, n-2] all satisfy the boundary, plus j = n-1 is always ok.
      ans += static_cast<long long>(n - 2 - p + 1 + 1);
    } else {
      // Only j = n-1 remains.
      ans += 1;
    }
  }

  return ans;
}

}  // namespace problem_2972
}  // namespace leetcode
