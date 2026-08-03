#include "leetcode/problems/longest-strictly-increasing-or-strictly-decreasing-subarray.h"

namespace leetcode {
namespace problem_3105 {

namespace {

int longestMonotonicSubarrayImpl(std::vector<int>& nums) {
  int best = 1;
  int inc = 1;  // current strictly increasing run length
  int dec = 1;  // current strictly decreasing run length
  for (std::size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] > nums[i - 1]) {
      inc += 1;
      dec = 1;
    } else if (nums[i] < nums[i - 1]) {
      dec += 1;
      inc = 1;
    } else {
      inc = 1;
      dec = 1;
    }
    if (inc > best) best = inc;
    if (dec > best) best = dec;
  }
  return best;
}

}  // namespace

LongestStrictlyIncreasingOrStrictlyDecreasingSubarraySolution::
    LongestStrictlyIncreasingOrStrictlyDecreasingSubarraySolution() {
  setMetaInfo(
      {.id = 3105,
       .title = "Longest Strictly Increasing or Strictly Decreasing Subarray",
       .url = "https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/"});
  registerStrategy(
      {.name = "Linear Scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      longestMonotonicSubarrayImpl);
}

int LongestStrictlyIncreasingOrStrictlyDecreasingSubarraySolution::
    longestMonotonicSubarray(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3105
}  // namespace leetcode
