#include "leetcode/problems/kth-largest-element-in-an-array.h"

namespace leetcode {
namespace problem_215 {

namespace {

// Hoare-style quickselect. Finds the element that would be at index `target`
// in ascending sorted order (in-place).
int quickSelectImpl(std::vector<int>& nums, int left, int right,
                    int target) {
  while (left < right) {
    int pivot = nums[right];
    int i = left;  // partition boundary
    for (int j = left; j < right; ++j) {
      if (nums[j] < pivot) {
        std::swap(nums[i], nums[j]);
        ++i;
      }
    }
    std::swap(nums[i], nums[right]);
    if (i == target) {
      return nums[i];
    } else if (i < target) {
      left = i + 1;
    } else {
      right = i - 1;
    }
  }
  return nums[left];
}

int findKthLargestImpl(std::vector<int>& nums, int k) {
  // k-th largest is the (n - k)-th smallest (0-indexed).
  const int target = static_cast<int>(nums.size()) - k;
  return quickSelectImpl(nums, 0, static_cast<int>(nums.size()) - 1, target);
}

}  // namespace

int KthLargestElementInAnArraySolution::findKthLargest(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

KthLargestElementInAnArraySolution::KthLargestElementInAnArraySolution() {
  setMetaInfo({.id = 215,
               .title = "Kth Largest Element in an Array",
               .url = "https://leetcode.com/problems/kth-largest-element-in-an-array/"});
  registerStrategy({.name = "quickselect",
                    .expected = "Accepted",
                    .time_complexity = "O(n) average, O(n^2) worst",
                    .space_complexity = "O(1)",
                    .tags = {"divide-and-conquer", "quickselect"}},
                   findKthLargestImpl);
}

}  // namespace problem_215
}  // namespace leetcode
