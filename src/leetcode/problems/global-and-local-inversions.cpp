#include "leetcode/problems/global-and-local-inversions.h"

#include <cmath>

namespace leetcode {
namespace problem_775 {

namespace {

bool isIdealPermutationImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  for (int i = 0; i < n; ++i) {
    if (std::abs(nums[i] - i) > 1) {
      return false;
    }
  }
  return true;
}

}  // namespace

GlobalAndLocalInversionsSolution::GlobalAndLocalInversionsSolution() {
  setMetaInfo({.id = 775,
               .title = "Global and Local Inversions",
               .url = "https://leetcode.com/problems/global-and-local-inversions/"});

  registerStrategy(
      {.name = "IdealPermutationCheck",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      isIdealPermutationImpl);
}

bool GlobalAndLocalInversionsSolution::isIdealPermutation(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_775
}  // namespace leetcode
