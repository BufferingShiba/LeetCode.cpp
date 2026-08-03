#include "leetcode/problems/search-in-rotated-sorted-array-ii.h"

namespace leetcode {
namespace problem_81 {

namespace {

bool searchImpl(std::vector<int>& nums, int target) {
  int lo = 0;
  int hi = static_cast<int>(nums.size()) - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] == target) {
      return true;
    }
    if (nums[lo] == nums[mid]) {
      // 无法判断哪半边有序，跳过左边界的一个重复值
      ++lo;
    } else if (nums[mid] > nums[lo]) {
      // 左半边有序
      if (target >= nums[lo] && target < nums[mid]) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    } else {
      // 右半边有序
      if (target > nums[mid] && target <= nums[hi]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
  }
  return false;
}

}  // namespace

SearchInRotatedSortedArrayIiSolution::SearchInRotatedSortedArrayIiSolution() {
  setMetaInfo({.id = 81,
               .title = "Search in Rotated Sorted Array II",
               .url =
                   "https://leetcode.com/problems/search-in-rotated-sorted-array-ii/"});
  registerStrategy(
      {.name = "binary search with duplicate handling",
       .expected = "Accepted",
       .time_complexity = "O(log n) average, O(n) worst",
       .space_complexity = "O(1)",
       .tags = {"Array", "Binary Search"}},
      searchImpl);
}

bool SearchInRotatedSortedArrayIiSolution::search(std::vector<int>& nums,
                                                   int target) {
  return getSolution()(nums, target);
}

}  // namespace problem_81
}  // namespace leetcode
