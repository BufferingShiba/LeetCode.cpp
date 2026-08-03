#include "leetcode/problems/length-of-longest-subarray-with-at-most-k-frequency.h"

#include <unordered_map>

namespace leetcode {
namespace problem_2958 {
namespace {

int maxSubarrayLengthImpl(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  std::unordered_map<int, int> freq;
  int ans = 0;
  int left = 0;
  for (int right = 0; right < n; ++right) {
    ++freq[nums[right]];
    while (freq[nums[right]] > k) {
      --freq[nums[left]];
      ++left;
    }
    ans = std::max(ans, right - left + 1);
  }
  return ans;
}

}  // namespace

LengthOfLongestSubarrayWithAtMostKFrequencySolution::
    LengthOfLongestSubarrayWithAtMostKFrequencySolution() {
  setMetaInfo({.id = 2958,
               .title = "Length of Longest Subarray With at Most K Frequency",
               .url = "https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/"});
  registerStrategy(
      {.name = "sliding-window",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Sliding Window"}},
      maxSubarrayLengthImpl);
}

int
LengthOfLongestSubarrayWithAtMostKFrequencySolution::maxSubarrayLength(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2958
}  // namespace leetcode
