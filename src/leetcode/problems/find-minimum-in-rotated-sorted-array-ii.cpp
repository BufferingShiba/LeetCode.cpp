#include "leetcode/problems/find-minimum-in-rotated-sorted-array-ii.h"

#include <vector>

namespace leetcode {
namespace problem_154 {
namespace {

int findMinImpl(std::vector<int>& nums) {
  int low = 0;
  int high = static_cast<int>(nums.size()) - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] > nums[high]) {
      low = mid + 1;
    } else if (nums[mid] < nums[high]) {
      high = mid;
    } else {
      --high;
    }
  }
  return nums[low];
}

}  // namespace

FindMinimumInRotatedSortedArrayIiSolution::FindMinimumInRotatedSortedArrayIiSolution() {
  setMetaInfo({.id = 154,
               .title = "Find Minimum in Rotated Sorted Array II",
               .url = "https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/"});
  registerStrategy({
      .name = "BinarySearch",
      .expected = "Accepted",
      .time_complexity = "O(log n) average, O(n) worst (all equal)",
      .space_complexity = "O(1)",
      .tags = {"Array", "Binary Search"},
  }, findMinImpl);
}

int FindMinimumInRotatedSortedArrayIiSolution::findMin(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_154
}  // namespace leetcode
