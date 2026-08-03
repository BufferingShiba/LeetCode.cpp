#include "leetcode/problems/divide-array-into-equal-pairs.h"

#include <unordered_map>

namespace leetcode::problem_2206 {

namespace {

bool divideArrayImpl(std::vector<int>& nums) {
  std::unordered_map<int, int> count;
  for (int num : nums) {
    ++count[num];
  }
  for (const auto& entry : count) {
    if (entry.second % 2 != 0) {
      return false;
    }
  }
  return true;
}

}  // namespace

DivideArrayIntoEqualPairsSolution::DivideArrayIntoEqualPairsSolution() {
  setMetaInfo({.id = 2206,
               .title = "Divide Array Into Equal Pairs",
               .url = "https://leetcode.com/problems/divide-array-into-equal-pairs/"});
  registerStrategy({.name = "Counting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table", "Counting"}},
                   divideArrayImpl);
}

bool DivideArrayIntoEqualPairsSolution::divideArray(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2206
