#include "leetcode/problems/find-first-and-last-position-of-element-in-sorted-array.h"

#include <algorithm>

namespace leetcode::problem_34 {

namespace {

std::vector<int> searchRangeImpl(std::vector<int>& nums, int target) {
  auto lb = std::lower_bound(nums.begin(), nums.end(), target);
  auto ub = std::upper_bound(nums.begin(), nums.end(), target);
  if (lb == ub) {
    return {-1, -1};
  }
  return {static_cast<int>(lb - nums.begin()),
          static_cast<int>(ub - nums.begin()) - 1};
}

}  // namespace

FindFirstAndLastPositionOfElementInSortedArraySolution::
    FindFirstAndLastPositionOfElementInSortedArraySolution() {
  setMetaInfo({.id = 34,
               .title = "Find First and Last Position of Element in Sorted Array",
               .url = "https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/"});
  registerStrategy(
      {"Binary Search LowerBound + UpperBound", "Accepted", "O(log n)",
       "O(1)", {"Array", "Binary Search"},
       "Use std::lower_bound and std::upper_bound to find the range."},
      searchRangeImpl);
}

std::vector<int>
FindFirstAndLastPositionOfElementInSortedArraySolution::searchRange(
    std::vector<int>& nums, int target) {
  return getSolution()(nums, target);
}

}  // namespace leetcode::problem_34
