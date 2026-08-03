#include "leetcode/problems/single-element-in-a-sorted-array.h"

namespace leetcode {
namespace problem_540 {

namespace {

int singleNonDuplicateImpl(std::vector<int>& nums) {
  int lo = 0;
  int hi = static_cast<int>(nums.size()) - 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    // 单一元素总是位于偶数索引（0-based）。
    // 若 mid 为奇数，将其调整为左侧偶数位，便于统一判断配对。
    if (mid % 2 == 1) {
      --mid;
    }
    if (nums[mid] == nums[mid + 1]) {
      // 配对一致，说明单一元素在右侧。
      lo = mid + 2;
    } else {
      // 配对不一致，单一元素在左侧（含 mid）。
      hi = mid;
    }
  }
  return nums[lo];
}

}  // namespace

SingleElementInASortedArraySolution::SingleElementInASortedArraySolution() {
  setMetaInfo({
      .id = 540,
      .title = "Single Element in a Sorted Array",
      .url = "https://leetcode.com/problems/single-element-in-a-sorted-array/",
  });
  registerStrategy(
      {
          .name = "binary-search",
          .expected = "Accepted",
          .time_complexity = "O(log n)",
          .space_complexity = "O(1)",
          .tags = {"Array", "Binary Search"},
      },
      &singleNonDuplicateImpl);
}

int SingleElementInASortedArraySolution::singleNonDuplicate(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_540
}  // namespace leetcode
