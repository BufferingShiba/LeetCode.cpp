#include "leetcode/problems/minimum-right-shifts-to-sort-the-array.h"

namespace leetcode {
namespace problem_2855 {

namespace {

int minimumRightShiftsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int dropPos = -1;
  for (int i = 0; i + 1 < n; ++i) {
    if (nums[i] > nums[i + 1]) {
      if (dropPos != -1) {
        return -1;  // more than one drop point
      }
      dropPos = i;
    }
  }
  if (dropPos == -1) {
    return 0;  // already sorted
  }
  // Array must be a valid cyclic rotation of a sorted array:
  // the wrap-around boundary (last -> first) must also be increasing.
  if (nums[n - 1] >= nums[0]) {
    return -1;
  }
  // Right shift so that nums[dropPos+1] becomes the new front.
  return n - 1 - dropPos;
}

}  // namespace

MinimumRightShiftsToSortTheArraySolution::
    MinimumRightShiftsToSortTheArraySolution() {
  setMetaInfo({.id = 2855,
               .title = "Minimum Right Shifts to Sort the Array",
               .url = "https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array/"});
  registerStrategy(
      {"linear_scan", "Accepted", "O(n)", "O(1)", {"Array"}},
      [](std::vector<int>& nums) { return minimumRightShiftsImpl(nums); });
}

int MinimumRightShiftsToSortTheArraySolution::minimumRightShifts(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2855
}  // namespace leetcode
