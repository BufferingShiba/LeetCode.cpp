#include "leetcode/problems/sum-of-all-subset-xor-totals.h"

namespace leetcode::problem_1863 {

namespace {

int subsetXORSumImpl(std::vector<int>& nums) {
  int or_all = 0;
  for (int v : nums) {
    or_all |= v;
  }
  return or_all << (static_cast<int>(nums.size()) - 1);
}

}  // namespace

SumOfAllSubsetXorTotalsSolution::SumOfAllSubsetXorTotalsSolution() {
  setMetaInfo({.id = 1863,
               .title = "Sum of All Subset XOR Totals",
               .url =
                   "https://leetcode.com/problems/sum-of-all-subset-xor-totals/"});
  registerStrategy(
      {.name = "bitwise-or-times-half",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Bit Manipulation", "Combinatorics", "Math"}},
      subsetXORSumImpl);
}

int SumOfAllSubsetXorTotalsSolution::subsetXORSum(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_1863
