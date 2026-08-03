#include "leetcode/problems/next-permutation.h"

namespace leetcode {
namespace problem_31 {

namespace {

void nextPermutationImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int i = n - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]) {
    --i;
  }
  if (i >= 0) {
    int j = n - 1;
    while (nums[j] <= nums[i]) {
      --j;
    }
    std::swap(nums[i], nums[j]);
  }
  std::reverse(nums.begin() + i + 1, nums.end());
}

}  // namespace

NextPermutationSolution::NextPermutationSolution() {
  this->setMetaInfo({.id = 31,
                     .title = "Next Permutation",
                     .url = "https://leetcode.com/problems/next-permutation/"});
  this->registerStrategy(
      {
          "TwoPassReverse", "Accepted", "O(n)", "O(1)",
          {"Array", "Two Pointers"},
          "Find rightmost ascent, swap with successor, reverse the suffix."},
      nextPermutationImpl);
}

void NextPermutationSolution::nextPermutation(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_31
}  // namespace leetcode
