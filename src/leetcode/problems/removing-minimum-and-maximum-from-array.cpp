#include "leetcode/problems/removing-minimum-and-maximum-from-array.h"

namespace leetcode::problem_2091 {

namespace {

int minimumDeletionsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int minIdx = 0;
  int maxIdx = 0;
  for (int i = 1; i < n; ++i) {
    if (nums[i] < nums[minIdx]) minIdx = i;
    if (nums[i] > nums[maxIdx]) maxIdx = i;
  }

  if (minIdx > maxIdx) std::swap(minIdx, maxIdx);

  // Option 1: both from front
  const int frontBoth = maxIdx + 1;
  // Option 2: both from back
  const int backBoth = n - minIdx;
  // Option 3: min from front, max from back
  const int split = (minIdx + 1) + (n - maxIdx);

  return std::min(frontBoth, std::min(backBoth, split));
}

}  // namespace

RemovingMinimumAndMaximumFromArraySolution::
    RemovingMinimumAndMaximumFromArraySolution() {
  setMetaInfo(
      {.id = 2091,
       .title = "Removing Minimum and Maximum From Array",
       .url =
           "https://leetcode.com/problems/removing-minimum-and-maximum-from-array/"});
  registerStrategy(
      {.name = "enumerate-three-cases",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      minimumDeletionsImpl);
}

int RemovingMinimumAndMaximumFromArraySolution::minimumDeletions(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2091
