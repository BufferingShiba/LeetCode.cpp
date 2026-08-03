#include "leetcode/problems/concatenate-array-with-reverse.h"

namespace leetcode::problem_3925 {

static std::vector<int> concatWithReverseImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  std::vector<int> ans;
  ans.reserve(2 * n);
  ans.insert(ans.end(), nums.begin(), nums.end());
  ans.insert(ans.end(), nums.rbegin(), nums.rend());
  return ans;
}

ConcatenateArrayWithReverseSolution::ConcatenateArrayWithReverseSolution() {
  setMetaInfo({.id = 3925,
               .title = "Concatenate Array With Reverse",
               .url = "https://leetcode.com/problems/concatenate-array-with-reverse/"});
  registerStrategy(
      {.name = "Direct Construction",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Simulation"}},
      concatWithReverseImpl);
  setDefaultStrategy();
}

std::vector<int> ConcatenateArrayWithReverseSolution::concatWithReverse(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3925
