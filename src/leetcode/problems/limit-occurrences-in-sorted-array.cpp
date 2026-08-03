#include "leetcode/problems/limit-occurrences-in-sorted-array.h"

#include <vector>

namespace leetcode::problem_3940 {

namespace {

std::vector<int> LimitOccurrencesTwoPointers(std::vector<int>& nums, int k) {
  if (nums.size() <= static_cast<size_t>(k)) {
    return nums;
  }
  size_t write = 0;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (write < static_cast<size_t>(k) ||
        nums[i] != nums[write - static_cast<size_t>(k)]) {
      nums[write++] = nums[i];
    }
  }
  nums.resize(write);
  return nums;
}

}  // namespace

LimitOccurrencesInSortedArraySolution::LimitOccurrencesInSortedArraySolution() {
  setMetaInfo({.id = 3940,
               .title = "Limit Occurrences in Sorted Array",
               .url = "https://leetcode.com/problems/limit-occurrences-in-sorted-array/"});

  registerStrategy({.name = "Two Pointers",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Two Pointers"}},
                   LimitOccurrencesTwoPointers);
}

std::vector<int> LimitOccurrencesInSortedArraySolution::limitOccurrences(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_3940
