#include "leetcode/problems/count-subarrays-where-max-element-appears-at-least-k-times.h"

namespace leetcode {
namespace problem_2962 {

namespace {

long long countSubarraysImpl(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  int mx = nums[0];
  for (int x : nums) {
    if (x > mx) mx = x;
  }

  long long ans = 0;
  int count = 0;
  int left = 0;
  for (int right = 0; right < n; ++right) {
    if (nums[right] == mx) ++count;
    while (count >= k) {
      if (nums[left] == mx) --count;
      ++left;
    }
    // Now [left..right] has exactly (k-1) mx at most; subarrays ending at
    // `right` with start in [0, left-1] each contain at least k mx.
    ans += left;
  }
  return ans;
}

}  // namespace

CountSubarraysWhereMaxElementAppearsAtLeastKTimesSolution::
    CountSubarraysWhereMaxElementAppearsAtLeastKTimesSolution() {
  setMetaInfo(
      {.id = 2962,
       .title = "Count Subarrays Where Max Element Appears at Least K Times",
       .url = "https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/"});

  registerStrategy(
      {.name = "sliding-window",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sliding Window"}},
      countSubarraysImpl);
}

long long CountSubarraysWhereMaxElementAppearsAtLeastKTimesSolution::
    countSubarrays(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2962
}  // namespace leetcode
