#include "leetcode/problems/split-array-into-maximum-number-of-subarrays.h"

namespace leetcode {
namespace problem_2871 {

namespace {

int maxSubarraysImpl(std::vector<int>& nums) {
  // Compute total AND of the whole array.
  int total_and = nums[0];
  for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
    total_and &= nums[i];
  }

  // If total AND > 0, we cannot split further without increasing the sum.
  if (total_and > 0) {
    return 1;
  }

  // total_and == 0: greedily split whenever the running AND becomes 0.
  int count = 0;
  int cur_and = -1;  // all bits set
  for (int num : nums) {
    cur_and &= num;
    if (cur_and == 0) {
      ++count;
      cur_and = -1;  // reset for the next subarray
    }
  }

  // At least one subarray exists.
  return count == 0 ? 1 : count;
}

}  // namespace

SplitArrayIntoMaximumNumberOfSubarraysSolution::SplitArrayIntoMaximumNumberOfSubarraysSolution() {
  setMetaInfo({.id = 2871,
               .title = "Split Array Into Maximum Number of Subarrays",
               .url = "https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/"});

  registerStrategy(
      {.name = "greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy", "Bit Manipulation"}},
      maxSubarraysImpl);
}

int SplitArrayIntoMaximumNumberOfSubarraysSolution::maxSubarrays(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2871
}  // namespace leetcode
