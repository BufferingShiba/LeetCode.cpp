#include "leetcode/problems/find-occurrences-of-an-element-in-an-array.h"

namespace leetcode::problem_3159 {

namespace {

std::vector<int> occurrencesOfElementImpl(std::vector<int>& nums,
                                          std::vector<int>& queries,
                                          int x) {
  std::vector<int> positions;
  positions.reserve(nums.size());
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] == x) {
      positions.push_back(i);
    }
  }
  std::vector<int> answer;
  answer.reserve(queries.size());
  for (int q : queries) {
    if (q <= static_cast<int>(positions.size())) {
      answer.push_back(positions[q - 1]);
    } else {
      answer.push_back(-1);
    }
  }
  return answer;
}

}  // namespace

FindOccurrencesOfAnElementInAnArraySolution::
    FindOccurrencesOfAnElementInAnArraySolution() {
  setMetaInfo({.id = 3159,
               .title = "Find Occurrences of an Element in an Array",
               .url =
                   "https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/"});
  registerStrategy(
      {.name = "positions_collection",
       .expected = "Accepted",
       .time_complexity = "O(n + q)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      occurrencesOfElementImpl);
}

std::vector<int>
FindOccurrencesOfAnElementInAnArraySolution::occurrencesOfElement(
    std::vector<int>& nums, std::vector<int>& queries, int x) {
  return getSolution()(nums, queries, x);
}

}  // namespace leetcode::problem_3159
