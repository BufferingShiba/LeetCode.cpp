#include "leetcode/problems/maximum-count-of-positive-integer-and-negative-integer.h"

#include <algorithm>

namespace leetcode::problem_2529 {

namespace {
int maximumCountImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  const int neg = static_cast<int>(
      std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin());
  const int pos = n - static_cast<int>(
      std::upper_bound(nums.begin(), nums.end(), 0) - nums.begin());
  return std::max(neg, pos);
}
}  // namespace

int MaximumCountOfPositiveIntegerAndNegativeIntegerSolution::maximumCount(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

MaximumCountOfPositiveIntegerAndNegativeIntegerSolution::
    MaximumCountOfPositiveIntegerAndNegativeIntegerSolution() {
  setMetaInfo({.id = 2529,
               .title = "Maximum Count of Positive Integer and Negative Integer",
               .url = "https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/"});
  registerStrategy(
      {.name = "binary_search",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Binary Search", "Counting"}},
      maximumCountImpl);
}

}  // namespace leetcode::problem_2529
