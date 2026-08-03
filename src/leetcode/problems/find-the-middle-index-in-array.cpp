#include "leetcode/problems/find-the-middle-index-in-array.h"

#include <vector>

namespace leetcode::problem_1991 {

namespace {

int findMiddleIndexImpl(std::vector<int>& nums) {
  int total = 0;
  for (int x : nums) {
    total += x;
  }
  int left = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (left == total - left - nums[i]) {
      return i;
    }
    left += nums[i];
  }
  return -1;
}

}  // namespace

FindTheMiddleIndexInArraySolution::FindTheMiddleIndexInArraySolution() {
  setMetaInfo({.id = 1991,
               .title = "Find the Middle Index in Array",
               .url = "https://leetcode.com/problems/find-the-middle-index-in-array/"});
  registerStrategy(
      {.name = "prefix_sum",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Prefix Sum"}},
      findMiddleIndexImpl);
}

int FindTheMiddleIndexInArraySolution::findMiddleIndex(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_1991
