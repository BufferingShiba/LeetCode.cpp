#include "leetcode/problems/sort-integers-by-binary-reflection.h"

#include <algorithm>

namespace leetcode {
namespace problem_3769 {
namespace {

int binaryReflection(int x) {
  int m = 0;
  while (x > 0) {
    m = (m << 1) | (x & 1);
    x >>= 1;
  }
  return m;
}

std::vector<int> sortByReflectionImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end(), [](int a, int b) {
    int ra = binaryReflection(a);
    int rb = binaryReflection(b);
    if (ra != rb) return ra < rb;
    return a < b;
  });
  return nums;
}

}  // namespace

SortIntegersByBinaryReflectionSolution::SortIntegersByBinaryReflectionSolution() {
  setMetaInfo({3769, "Sort Integers by Binary Reflection",
               "https://leetcode.com/problems/sort-integers-by-binary-reflection/"});
  registerStrategy(
      {"sort-by-binary-reflection", "Accepted", "O(n log n)", "O(1)",
       {"Array", "Sorting"}},
      sortByReflectionImpl);
}

std::vector<int> SortIntegersByBinaryReflectionSolution::sortByReflection(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3769
}  // namespace leetcode
