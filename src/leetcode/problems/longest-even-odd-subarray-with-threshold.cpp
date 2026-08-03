#include "leetcode/problems/longest-even-odd-subarray-with-threshold.h"

#include <vector>

namespace leetcode {
namespace problem_2760 {

namespace {

int longestAlternatingSubarrayImpl(std::vector<int>& nums, int threshold) {
  const int n = static_cast<int>(nums.size());
  int cur = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (cur > 0 && (nums[i] > threshold || nums[i] % 2 == nums[i - 1] % 2)) {
      cur = 0;
    }
    if (cur == 0) {
      if (nums[i] % 2 == 0 && nums[i] <= threshold) {
        cur = 1;
      }
    } else {
      ++cur;
    }
    if (cur > ans) ans = cur;
  }
  return ans;
}

}  // namespace

LongestEvenOddSubarrayWithThresholdSolution::
    LongestEvenOddSubarrayWithThresholdSolution() {
  setMetaInfo({.id = 2760,
               .title = "Longest Even Odd Subarray With Threshold",
               .url = "https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/"});
  registerStrategy(
      {.name = "sliding-window",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sliding Window"}},
      longestAlternatingSubarrayImpl);
}

int LongestEvenOddSubarrayWithThresholdSolution::
    longestAlternatingSubarray(std::vector<int>& nums, int threshold) {
  return getSolution()(nums, threshold);
}

}  // namespace problem_2760
}  // namespace leetcode
