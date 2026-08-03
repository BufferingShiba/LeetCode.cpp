#include "leetcode/problems/minimum-size-subarray-in-infinite-array.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_2875 {

namespace {

// Find the shortest subarray in the doubled array (nums + nums)
// whose sum equals `target`. Returns INT_MAX if not found.
int shortestSubarrayWithSum(const std::vector<int>& nums, long long target) {
  int n = static_cast<int>(nums.size());
  int left = 0;
  long long window_sum = 0;
  int ans = INT_MAX;

  for (int right = 0; right < 2 * n; ++right) {
    window_sum += nums[right % n];
    while (window_sum > target && left <= right) {
      window_sum -= nums[left % n];
      ++left;
    }
    if (window_sum == target) {
      int len = right - left + 1;
      if (len < ans) ans = len;
      // shrink from left to seek a possibly shorter window
      window_sum -= nums[left % n];
      ++left;
    }
  }
  return ans;
}

int minSizeSubarrayImpl(std::vector<int>& nums, int target) {
  int n = static_cast<int>(nums.size());

  long long total = 0;
  for (int x : nums) total += x;

  long long q = target / total;
  long long r = target % total;

  // Case: target is a multiple of total
  if (r == 0) {
    return static_cast<int>(q * n);
  }

  long long ans = LLONG_MAX;

  // Candidate 1: q full copies + a subarray summing to r
  int len1 = shortestSubarrayWithSum(nums, r);
  if (len1 != INT_MAX) {
    long long cand = q * n + len1;
    if (cand < ans) ans = cand;
  }

  // Candidate 2: q-1 full copies + a subarray summing to total + r
  if (q >= 1) {
    int len2 = shortestSubarrayWithSum(nums, total + r);
    if (len2 != INT_MAX) {
      long long cand = (q - 1) * n + len2;
      if (cand < ans) ans = cand;
    }
  }

  return (ans == LLONG_MAX) ? -1 : static_cast<int>(ans);
}

}  // namespace

MinimumSizeSubarrayInInfiniteArraySolution::
    MinimumSizeSubarrayInInfiniteArraySolution() {
  setMetaInfo({.id = 2875,
               .title = "Minimum Size Subarray in Infinite Array",
               .url = "https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/"});
  registerStrategy(
      {.name = "sliding_window_modulo",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "Sliding Window", "Prefix Sum"}},
      minSizeSubarrayImpl);
}

int MinimumSizeSubarrayInInfiniteArraySolution::minSizeSubarray(
    std::vector<int>& nums, int target) {
  return getSolution()(nums, target);
}

}  // namespace problem_2875
}  // namespace leetcode
