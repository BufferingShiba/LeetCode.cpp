#include "leetcode/problems/maximize-expression-of-three-elements.h"

#include <algorithm>

namespace leetcode {
namespace problem_3745 {

namespace {

int maximizeExpressionOfThreeImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  const int n = static_cast<int>(nums.size());
  return nums[n - 1] + nums[n - 2] - nums[0];
}

}  // namespace

MaximizeExpressionOfThreeElementsSolution::MaximizeExpressionOfThreeElementsSolution() {
  setMetaInfo({.id = 3745,
               .title = "Maximize Expression of Three Elements",
               .url = "https://leetcode.com/problems/maximize-expression-of-three-elements/"});
  registerStrategy({.name = "sort",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Greedy", "Sorting"}},
                   maximizeExpressionOfThreeImpl);
}

int MaximizeExpressionOfThreeElementsSolution::maximizeExpressionOfThree(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3745
}  // namespace leetcode
