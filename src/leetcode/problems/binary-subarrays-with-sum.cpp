#include "leetcode/problems/binary-subarrays-with-sum.h"

namespace leetcode::problem_930 {

static int numSubarraysWithSumImpl(std::vector<int>& nums, int goal) {
  // Helper: count subarrays with sum <= k
  auto atMost = [](std::vector<int>& nums, int k) -> int {
    if (k < 0) return 0;
    int left = 0;
    int sum = 0;
    int count = 0;
    for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
      sum += nums[right];
      while (sum > k) {
        sum -= nums[left];
        ++left;
      }
      // All subarrays ending at `right` with start in [left, right] have sum <= k
      count += right - left + 1;
    }
    return count;
  };

  return atMost(nums, goal) - atMost(nums, goal - 1);
}

BinarySubarraysWithSumSolution::BinarySubarraysWithSumSolution() {
  setMetaInfo({.id = 930,
               .title = "Binary Subarrays With Sum",
               .url = "https://leetcode.com/problems/binary-subarrays-with-sum/"});
  registerStrategy(
      {.name = "Sliding Window (At Most K)",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sliding Window", "Prefix Sum"}},
      numSubarraysWithSumImpl);
}

int BinarySubarraysWithSumSolution::numSubarraysWithSum(std::vector<int>& nums,
                                                        int goal) {
  return getSolution()(nums, goal);
}

}  // namespace leetcode::problem_930
