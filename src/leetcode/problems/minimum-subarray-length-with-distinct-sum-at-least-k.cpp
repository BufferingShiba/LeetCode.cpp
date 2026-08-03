#include "leetcode/problems/minimum-subarray-length-with-distinct-sum-at-least-k.h"

#include <unordered_map>

namespace leetcode::problem_3795 {

namespace {

int minLengthImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());
  std::unordered_map<int, int> freq;
  long long distinct_sum = 0;  // 使用 long long 防止溢出（k 最大 1e9，但和可能更大）
  int min_len = n + 1;

  int left = 0;
  for (int right = 0; right < n; ++right) {
    int val = nums[right];
    freq[val]++;
    if (freq[val] == 1) {
      distinct_sum += val;
    }

    while (distinct_sum >= k) {
      int len = right - left + 1;
      if (len < min_len) {
        min_len = len;
      }
      int left_val = nums[left];
      freq[left_val]--;
      if (freq[left_val] == 0) {
        distinct_sum -= left_val;
      }
      ++left;
    }
  }

  return min_len <= n ? min_len : -1;
}

}  // namespace

MinimumSubarrayLengthWithDistinctSumAtLeastKSolution::
    MinimumSubarrayLengthWithDistinctSumAtLeastKSolution() {
  setMetaInfo({.id = 3795,
               .title = "Minimum Subarray Length With Distinct Sum At Least K",
               .url = "https://leetcode.com/problems/minimum-subarray-length-with-distinct-sum-at-least-k/"});

  registerStrategy(
      {.name = "Sliding Window",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Sliding Window"}},
      minLengthImpl);

  setDefaultStrategy();
}

int MinimumSubarrayLengthWithDistinctSumAtLeastKSolution::minLength(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_3795
