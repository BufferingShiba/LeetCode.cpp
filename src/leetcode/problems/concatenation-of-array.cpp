#include "leetcode/problems/concatenation-of-array.h"

namespace leetcode::problem_1929 {

static std::vector<int> getConcatenationImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  std::vector<int> ans(2 * n);
  for (int i = 0; i < n; ++i) {
    ans[i] = nums[i];
    ans[i + n] = nums[i];
  }
  return ans;
}

ConcatenationOfArraySolution::ConcatenationOfArraySolution() {
  setMetaInfo({.id = 1929, .title = "Concatenation of Array",
               .url = "https://leetcode.com/problems/concatenation-of-array/"});
  registerStrategy({.name = "OnePass",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Simulation"}},
                   getConcatenationImpl);
}

std::vector<int> ConcatenationOfArraySolution::getConcatenation(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_1929
