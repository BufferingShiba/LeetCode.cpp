#include "leetcode/problems/find-minimum-in-rotated-sorted-array.h"

namespace leetcode::problem_153 {

namespace {

int findMinBinarySearch(std::vector<int>& nums) {
  int left = 0;
  int right = static_cast<int>(nums.size()) - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[right]) {
      // mid is in the left (larger) segment; min is on the right
      left = mid + 1;
    } else {
      // mid is in the right (smaller) segment; min is at mid or to its left
      right = mid;
    }
  }

  return nums[left];
}

}  // namespace

FindMinimumInRotatedSortedArraySolution::FindMinimumInRotatedSortedArraySolution() {
  setMetaInfo({.id = 153,
               .title = "Find Minimum in Rotated Sorted Array",
               .url = "https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/"});

  registerStrategy({.name = "Binary Search",
                    .expected = "Accepted",
                    .time_complexity = "O(log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Binary Search"}},
                   findMinBinarySearch);

  setDefaultStrategy();
}

int FindMinimumInRotatedSortedArraySolution::findMin(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_153
