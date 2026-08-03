#include "leetcode/problems/count-complete-subarrays-in-an-array.h"

namespace leetcode {
namespace problem_2799 {

static int solution1(vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  // Count total distinct elements in the whole array.
  bool present[2001] = {false};
  int total = 0;
  for (int v : nums) {
    if (!present[v]) {
      present[v] = true;
      ++total;
    }
  }

  // Sliding window: for each left boundary, find the minimal right boundary
  // such that the window keeps all 'total' distinct elements.
  long long ans = 0;
  int freq[2001] = {0};
  int distinct = 0;
  int r = 0;  // r points just past the last included element: window is [l, r).
  for (int l = 0; l < n; ++l) {
    while (r < n && distinct < total) {
      if (freq[nums[r]]++ == 0) ++distinct;
      ++r;
    }
    if (distinct < total) break;  // No further right boundary can complete the array.
    // Any right endpoint from r-1 to n-1 yields a complete subarray.
    ans += static_cast<long long>(n - r + 1);
    // Shrink the window from the left.
    if (--freq[nums[l]] == 0) --distinct;
  }
  return static_cast<int>(ans);
}

CountCompleteSubarraysInAnArraySolution::CountCompleteSubarraysInAnArraySolution() {
  setMetaInfo({
      .id = 2799,
      .title = "Count Complete Subarrays in an Array",
      .url = "https://leetcode.com/problems/count-complete-subarrays-in-an-array"
  });
  registerStrategy({.name = "Sliding Window",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Hash Table", "Two Pointers", "Sliding Window"}},
                   solution1);
}

int CountCompleteSubarraysInAnArraySolution::countCompleteSubarrays(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2799
}  // namespace leetcode
