#include "leetcode/problems/find-the-maximum-number-of-marked-indices.h"

#include <algorithm>

namespace leetcode::problem_2576 {

namespace {

// Greedy: sort, then pair the smaller half with the larger half via two pointers.
int maxNumOfMarkedIndicesImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  const int n = static_cast<int>(nums.size());
  int i = 0;
  int j = n / 2;
  int count = 0;
  while (i < n / 2 && j < n) {
    if (2LL * nums[i] <= nums[j]) {
      count += 2;
      ++i;
      ++j;
    } else {
      ++j;
    }
  }
  return count;
}

}  // namespace

int FindTheMaximumNumberOfMarkedIndicesSolution::maxNumOfMarkedIndices(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

FindTheMaximumNumberOfMarkedIndicesSolution::FindTheMaximumNumberOfMarkedIndicesSolution() {
  setMetaInfo({2576, "Find the Maximum Number of Marked Indices",
               "https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/"});
  registerStrategy(
      {.name = "greedy-sort-two-pointers", .expected = "Accepted",
       .time_complexity = "O(n log n)", .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Greedy", "Sorting"}},
      maxNumOfMarkedIndicesImpl);
}

}  // namespace leetcode::problem_2576
