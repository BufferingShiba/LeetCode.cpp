#include "leetcode/problems/sort-array-by-parity.h"

namespace leetcode {
namespace problem_905 {

static std::vector<int> sortArrayByParityImpl(std::vector<int>& nums) {
  int left = 0;
  int right = static_cast<int>(nums.size()) - 1;
  while (left < right) {
    while (left < right && nums[left] % 2 == 0) {
      ++left;
    }
    while (left < right && nums[right] % 2 == 1) {
      --right;
    }
    if (left < right) {
      std::swap(nums[left], nums[right]);
      ++left;
      --right;
    }
  }
  return nums;
}

SortArrayByParitySolution::SortArrayByParitySolution() {
  setMetaInfo({.id = 905,
               .title = "Sort Array By Parity",
               .url = "https://leetcode.com/problems/sort-array-by-parity/"});
  registerStrategy(
      {"TwoPointersInPlace", "Accepted", "O(n)", "O(1)",
       std::vector<std::string>{"Array", "Two Pointers", "Sorting"}},
      sortArrayByParityImpl);
}

std::vector<int> SortArrayByParitySolution::sortArrayByParity(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_905
}  // namespace leetcode
