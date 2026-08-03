#include "leetcode/problems/largest-element-in-an-array-after-merge-operations.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_2789 {

namespace {

long long maxArrayValueImpl(std::vector<int>& nums) {
  long long cur = nums.back();
  long long ans = cur;
  for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) {
    if (static_cast<long long>(nums[i]) <= cur) {
      cur += nums[i];
    } else {
      cur = nums[i];
    }
    ans = std::max(ans, cur);
  }
  return ans;
}

}  // namespace

LargestElementInAnArrayAfterMergeOperationsSolution::
    LargestElementInAnArrayAfterMergeOperationsSolution() {
  setMetaInfo({.id = 2789,
               .title = "Largest Element in an Array after Merge Operations",
               .url = "https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/"});
  registerStrategy(
      {.name = "GreedyMergeFromRight",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      maxArrayValueImpl);
}

long long LargestElementInAnArrayAfterMergeOperationsSolution::maxArrayValue(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2789
