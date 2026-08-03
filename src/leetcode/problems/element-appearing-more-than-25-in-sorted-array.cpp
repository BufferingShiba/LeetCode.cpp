#include "leetcode/problems/element-appearing-more-than-25-in-sorted-array.h"

namespace leetcode {
namespace problem_1287 {

namespace {

int findSpecialIntegerImpl(std::vector<int>& arr) {
  const int n = static_cast<int>(arr.size());
  const int target = n / 4;
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && arr[j] == arr[i]) {
      ++j;
    }
    if (j - i > target) {
      return arr[i];
    }
    i = j;
  }
  return -1;
}

}  // namespace

ElementAppearingMoreThan25InSortedArraySolution::
    ElementAppearingMoreThan25InSortedArraySolution() {
  setMetaInfo({.id = 1287,
               .title = "Element Appearing More Than 25% In Sorted Array",
               .url = "https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/"});
  registerStrategy(
      {.name = "single_pass_scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      findSpecialIntegerImpl);
}

int ElementAppearingMoreThan25InSortedArraySolution::findSpecialInteger(
    std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_1287
}  // namespace leetcode
