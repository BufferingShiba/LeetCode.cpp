#include "leetcode/problems/find-all-duplicates-in-an-array.h"

namespace leetcode::problem_442 {

namespace {

std::vector<int> findDuplicatesImpl(std::vector<int>& nums) {
  std::vector<int> result;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    int idx = std::abs(nums[i]) - 1;
    if (nums[idx] < 0) {
      result.push_back(idx + 1);
    } else {
      nums[idx] = -nums[idx];
    }
  }
  return result;
}

}  // namespace

FindAllDuplicatesInAnArraySolution::FindAllDuplicatesInAnArraySolution() {
  setMetaInfo({.id = 442,
               .title = "Find All Duplicates in an Array",
               .url = "https://leetcode.com/problems/find-all-duplicates-in-an-array/"});

  registerStrategy(
      {.name = "NegationMark",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table"}},
      findDuplicatesImpl);

  setDefaultStrategy();
}

std::vector<int> FindAllDuplicatesInAnArraySolution::findDuplicates(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_442
