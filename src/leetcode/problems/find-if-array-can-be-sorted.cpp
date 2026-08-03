#include "leetcode/problems/find-if-array-can-be-sorted.h"

#include <algorithm>

namespace leetcode {
namespace problem_3011 {

static bool canSortArrayImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  if (n <= 1) return true;

  int prev_max = 0;       // 上一段的最大值
  int cur_min = nums[0];  // 当前段的最小值
  int cur_max = nums[0];  // 当前段的最大值
  int cur_bits = __builtin_popcount(nums[0]);

  for (int i = 1; i < n; ++i) {
    int bits = __builtin_popcount(nums[i]);
    if (bits == cur_bits) {
      // 同一段内，更新 min/max
      cur_min = std::min(cur_min, nums[i]);
      cur_max = std::max(cur_max, nums[i]);
    } else {
      // 段切换：检查前一段 max <= 当前段 min
      if (prev_max > cur_min) return false;
      prev_max = cur_max;
      cur_min = cur_max = nums[i];
      cur_bits = bits;
    }
  }

  // 最后一段与前面的段检查
  return prev_max <= cur_min;
}

FindIfArrayCanBeSortedSolution::FindIfArrayCanBeSortedSolution() {
  setMetaInfo({.id = 3011,
               .title = "Find if Array Can Be Sorted",
               .url = "https://leetcode.com/problems/find-if-array-can-be-sorted/"});

  registerStrategy(
      {.name = "segmented_scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Bit Manipulation", "Sorting"}},
      canSortArrayImpl);
}

bool FindIfArrayCanBeSortedSolution::canSortArray(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3011
}  // namespace leetcode
