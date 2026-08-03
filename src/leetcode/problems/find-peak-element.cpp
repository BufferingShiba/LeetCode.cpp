#include "leetcode/problems/find-peak-element.h"

namespace leetcode::problem_162 {

namespace {

// Binary search: maintain an interval [lo, hi] guaranteed to contain a peak.
// If nums[mid] < nums[mid + 1], a peak lies in the right half (mid+1 .. hi);
// otherwise a peak lies in the left half (lo .. mid). Ends when lo == hi.
int findPeakElementImpl(std::vector<int>& nums) {
  int lo = 0;
  int hi = static_cast<int>(nums.size()) - 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] < nums[mid + 1]) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}

}  // namespace

FindPeakElementSolution::FindPeakElementSolution() {
  this->setMetaInfo({.id = 162,
                     .title = "Find Peak Element",
                     .url = "https://leetcode.com/problems/find-peak-element/"});
  this->registerStrategy(
      {.name = "BinarySearch",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Binary Search"}},
      findPeakElementImpl);
}

int FindPeakElementSolution::findPeakElement(std::vector<int>& nums) {
  return this->getSolution()(nums);
}

}  // namespace leetcode::problem_162
