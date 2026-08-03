#include "leetcode/problems/sort-array-by-parity-ii.h"

namespace leetcode::problem_922 {

namespace {

std::vector<int> sortArrayByParityIIImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int i = 0;  // 偶数索引指针
  int j = 1;  // 奇数索引指针

  while (i < n && j < n) {
    // 偶数位置已经是偶数，前进
    while (i < n && (nums[i] & 1) == 0) {
      i += 2;
    }
    // 奇数位置已经是奇数，前进
    while (j < n && (nums[j] & 1) == 1) {
      j += 2;
    }
    // 如果都还没有越界，说明需要交换
    if (i < n && j < n) {
      std::swap(nums[i], nums[j]);
      i += 2;
      j += 2;
    }
  }

  return nums;
}

}  // namespace

SortArrayByParityIiSolution::SortArrayByParityIiSolution() {
  setMetaInfo({.id = 922,
               .title = "Sort Array By Parity II",
               .url = "https://leetcode.com/problems/sort-array-by-parity-ii/"});

  registerStrategy(
      {.name = "In-place Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Sorting"}},
      sortArrayByParityIIImpl);

  setDefaultStrategy();
}

std::vector<int> SortArrayByParityIiSolution::sortArrayByParityII(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_922
