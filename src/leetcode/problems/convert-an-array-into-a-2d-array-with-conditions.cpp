#include "leetcode/problems/convert-an-array-into-a-2d-array-with-conditions.h"

#include <unordered_map>

namespace leetcode::problem_2610 {

namespace {

std::vector<std::vector<int>> findMatrixImpl(std::vector<int>& nums) {
  std::vector<std::vector<int>> ans;
  std::unordered_map<int, int> rowIndex;

  for (int x : nums) {
    int idx = rowIndex[x];
    if (idx >= static_cast<int>(ans.size())) {
      ans.push_back({});
    }
    ans[idx].push_back(x);
    rowIndex[x] = idx + 1;
  }

  return ans;
}

}  // namespace

std::vector<std::vector<int>> ConvertAnArrayIntoA2dArrayWithConditionsSolution::findMatrix(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

ConvertAnArrayIntoA2dArrayWithConditionsSolution::ConvertAnArrayIntoA2dArrayWithConditionsSolution() {
  setMetaInfo({.id = 2610,
               .title = "Convert an Array Into a 2D Array With Conditions",
               .url = "https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/"});

  registerStrategy({.name = "HashTable + Greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table"}},
                   findMatrixImpl);
}

}  // namespace leetcode::problem_2610
