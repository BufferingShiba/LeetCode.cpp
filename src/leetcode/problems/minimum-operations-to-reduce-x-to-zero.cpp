#include "leetcode/problems/minimum-operations-to-reduce-x-to-zero.h"

namespace leetcode::problem_1658 {

namespace {

int minOperationsImpl(std::vector<int>& nums, int x) {
  const int n = static_cast<int>(nums.size());
  long long total = 0;
  for (int v : nums) total += v;

  const long long target = total - x;  // 剩余子数组所需的和
  if (target < 0) return -1;
  if (target == 0) return n;  // 需要移除全部元素

  // 滑动窗口：寻找和恰为 target 的最长连续子数组
  long long window_sum = 0;
  int ans = -1;
  int left = 0;
  for (int right = 0; right < n; ++right) {
    window_sum += nums[right];
    while (window_sum > target) {
      window_sum -= nums[left];
      ++left;
    }
    if (window_sum == target) {
      ans = std::max(ans, right - left + 1);
    }
  }
  return ans == -1 ? -1 : n - ans;
}

}  // namespace

MinimumOperationsToReduceXToZeroSolution::MinimumOperationsToReduceXToZeroSolution() {
  setMetaInfo({.id = 1658,
               .title = "Minimum Operations to Reduce X to Zero",
               .url = "https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/"});
  registerStrategy(
      {.name = "sliding_window",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sliding Window"}},
      minOperationsImpl);
}

int MinimumOperationsToReduceXToZeroSolution::minOperations(std::vector<int>& nums,
                                                             int x) {
  return getSolution()(nums, x);
}

}  // namespace leetcode::problem_1658
