#include "leetcode/problems/longest-fibonacci-subarray.h"

#include <algorithm>
#include <cstdint>

namespace leetcode {
namespace problem_3708 {

namespace {

int longestSubarrayImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  if (n <= 2) {
    return n;
  }

  int maxLen = 2;
  int curLen = 2;

  for (int i = 2; i < n; ++i) {
    // Use int64_t to avoid overflow when nums[i-1] + nums[i-2] > 2^31-1
    if (static_cast<int64_t>(nums[i - 1]) + nums[i - 2] == nums[i]) {
      ++curLen;
      maxLen = std::max(maxLen, curLen);
    } else {
      curLen = 2;
    }
  }

  return maxLen;
}

}  // namespace

LongestFibonacciSubarraySolution::LongestFibonacciSubarraySolution() {
  setMetaInfo({.id = 3708,
               .title = "Longest Fibonacci Subarray",
               .url = "https://leetcode.com/problems/longest-fibonacci-subarray/"});

  registerStrategy(
      {.name = "Linear Scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sliding Window"}},
      longestSubarrayImpl);
}

int LongestFibonacciSubarraySolution::longestSubarray(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3708
}  // namespace leetcode
