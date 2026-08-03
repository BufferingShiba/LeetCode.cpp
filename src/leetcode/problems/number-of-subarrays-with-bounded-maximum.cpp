#include "leetcode/problems/number-of-subarrays-with-bounded-maximum.h"

namespace leetcode {
namespace problem_795 {

// 统计“子数组最大值 <= bound”的子数组个数（非空）。
static int countWithMaxAtMost(std::vector<int>& nums, int bound) {
  int total = 0;
  int cur = 0;  // 以当前位置结尾、且所有元素 <= bound 的最长连续段长度
  for (int v : nums) {
    if (v > bound) {
      cur = 0;
    } else {
      ++cur;
    }
    total += cur;
  }
  return total;
}

static int numSubarrayBoundedMaxImpl(std::vector<int>& nums, int left, int right) {
  // 子数组中的最大值落在 [left, right] 内
  // = count(max<=right) - count(max<=left-1)
  return countWithMaxAtMost(nums, right) - countWithMaxAtMost(nums, left - 1);
}

NumberOfSubarraysWithBoundedMaximumSolution::NumberOfSubarraysWithBoundedMaximumSolution() {
  setMetaInfo({
      .id = 795,
      .title = "Number of Subarrays with Bounded Maximum",
      .url = "https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum"
  });
  registerStrategy({
      .name = "Count <= right minus <= left-1",
      .expected = "Accepted",
      .time_complexity = "O(n)",
      .space_complexity = "O(1)",
      .tags = {"Array", "Two Pointers", "Counting"},
  }, numSubarrayBoundedMaxImpl);
}

int NumberOfSubarraysWithBoundedMaximumSolution::numSubarrayBoundedMax(std::vector<int>& nums, int left, int right) {
  return getSolution()(nums, left, right);
}

}  // namespace problem_795
}  // namespace leetcode
