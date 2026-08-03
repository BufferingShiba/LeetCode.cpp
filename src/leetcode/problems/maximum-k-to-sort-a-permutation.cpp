#include "leetcode/problems/maximum-k-to-sort-a-permutation.h"

namespace leetcode {
namespace problem_3644 {

namespace {

int sortPermutationImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int and_all = -1;  // all bits set

  for (int i = 0; i < n; ++i) {
    if (nums[i] != i) {
      and_all &= nums[i];
    }
  }

  // If no misplaced elements, return 0
  if (and_all == -1) {
    return 0;
  }
  return and_all;
}

}  // namespace

MaximumKToSortAPermutationSolution::MaximumKToSortAPermutationSolution() {
  setMetaInfo({.id = 3644,
               .title = "Maximum K to Sort a Permutation",
               .url = "https://leetcode.com/problems/maximum-k-to-sort-a-permutation/"});

  registerStrategy(
      {.name = "Bitwise AND of misplaced values",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Bit Manipulation"}},
      sortPermutationImpl);
}

int MaximumKToSortAPermutationSolution::sortPermutation(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3644
}  // namespace leetcode
