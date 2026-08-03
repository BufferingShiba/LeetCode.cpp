#include "leetcode/problems/remove-duplicates-from-sorted-array.h"

namespace leetcode::problem_26 {

namespace {

int removeDuplicatesImpl(std::vector<int>& nums) {
  if (nums.empty()) {
    return 0;
  }
  int i = 0;
  for (int j = 1; j < static_cast<int>(nums.size()); ++j) {
    if (nums[j] != nums[i]) {
      ++i;
      nums[i] = nums[j];
    }
  }
  return i + 1;
}

}  // namespace

RemoveDuplicatesFromSortedArray::RemoveDuplicatesFromSortedArray() {
  setMetaInfo({.id = 26,
               .title = "Remove Duplicates from Sorted Array",
               .url = "https://leetcode.com/problems/remove-duplicates-from-sorted-array/"});
  registerStrategy({.name = "Two Pointers",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Two Pointers"}},
                   removeDuplicatesImpl);
}

int RemoveDuplicatesFromSortedArray::removeDuplicates(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_26
