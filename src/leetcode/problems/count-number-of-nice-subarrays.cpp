#include "leetcode/problems/count-number-of-nice-subarrays.h"

namespace leetcode {
namespace problem_1248 {

namespace {

// Count number of subarrays having at most `k` odd numbers (sliding window).
int numberOfSubarraysAtMost(std::vector<int>& nums, int k) {
  if (k < 0) {
    return 0;
  }
  int n = static_cast<int>(nums.size());
  int left = 0;
  int oddCount = 0;
  int result = 0;
  for (int right = 0; right < n; ++right) {
    if (nums[right] % 2 != 0) {
      ++oddCount;
    }
    while (oddCount > k) {
      if (nums[left] % 2 != 0) {
        --oddCount;
      }
      ++left;
    }
    result += (right - left + 1);
  }
  return result;
}

int numberOfSubarraysImpl(std::vector<int>& nums, int k) {
  return numberOfSubarraysAtMost(nums, k) - numberOfSubarraysAtMost(nums, k - 1);
}

}  // namespace

CountNumberOfNiceSubarraysSolution::CountNumberOfNiceSubarraysSolution() {
  setMetaInfo({.id = 1248,
               .title = "Count Number of Nice Subarrays",
               .url = "https://leetcode.com/problems/count-number-of-nice-subarrays/"});
  registerStrategy({.name = "sliding-window-atmost",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Sliding Window", "Two Pointers"}},
                   numberOfSubarraysImpl);
}

int CountNumberOfNiceSubarraysSolution::numberOfSubarrays(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_1248
}  // namespace leetcode
