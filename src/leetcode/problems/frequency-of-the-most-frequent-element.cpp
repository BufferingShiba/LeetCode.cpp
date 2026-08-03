#include "leetcode/problems/frequency-of-the-most-frequent-element.h"

#include <algorithm>

namespace leetcode {
namespace problem_1838 {

// Strategy: sort + sliding window.
// Sort nums. For each right pointer r (as the target element), maintain the
// maximum window [l, r] such that the total cost to raise all elements in the
// window to nums[r] is at most k. Cost = nums[r]*len - sum(window).
// This works because it is always optimal (cheapest) to raise the largest
// neighbors of a target, hence after sorting the optimal set of elements to
// make equal forms a contiguous window ending at the target.
static int solution1(vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  long long sum = 0;
  int l = 0;
  int ans = 0;
  for (int r = 0; r < static_cast<int>(nums.size()); ++r) {
    sum += nums[r];
    // Cost to make [l, r] all equal to nums[r].
    while (static_cast<long long>(nums[r]) * (r - l + 1) - sum > k) {
      sum -= nums[l];
      ++l;
    }
    ans = std::max(ans, r - l + 1);
  }
  return ans;
}

FrequencyOfTheMostFrequentElementSolution::FrequencyOfTheMostFrequentElementSolution() {
  setMetaInfo({
      .id = 1838,
      .title = "Frequency of the Most Frequent Element",
      .url = "https://leetcode.com/problems/frequency-of-the-most-frequent-element"
  });
  registerStrategy({.name = "Sliding Window",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(log n)",
                    .tags = {"Array", "Sliding Window", "Sorting"}},
                   solution1);
}

int FrequencyOfTheMostFrequentElementSolution::maxFrequency(vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_1838
}  // namespace leetcode
