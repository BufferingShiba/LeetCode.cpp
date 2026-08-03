#include "leetcode/problems/maximize-consecutive-elements-in-an-array-after-modification.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode::problem_3041 {

namespace {

int maxSelectedElementsImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());

  // dp[x] is the best length of a consecutive sequence ending at x.
  // For an input value v, the element can be assigned to v or v + 1.
  std::unordered_map<int, int> dp;
  int answer = 0;
  for (const int value : nums) {
    // Read dp[value] before overwriting it: this transition assigns the
    // current element to value + 1.
    dp[value + 1] = dp[value] + 1;
    // This transition assigns the current element to value itself.
    dp[value] = dp[value - 1] + 1;
    answer = std::max({answer, dp[value], dp[value + 1]});
  }
  return answer;
}

}  // namespace

int MaximizeConsecutiveElementsInAnArrayAfterModificationSolution::maxSelectedElements(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

MaximizeConsecutiveElementsInAnArrayAfterModificationSolution::
    MaximizeConsecutiveElementsInAnArrayAfterModificationSolution() {
  setMetaInfo({.id = 3041,
               .title = "Maximize Consecutive Elements in an Array After Modification",
               .url = "https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/"});
  registerStrategy({.name = "sorted-dp", .expected = "Accepted", .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)", .tags = {"Array", "Dynamic Programming", "Sorting"}},
                   maxSelectedElementsImpl);
}

}  // namespace leetcode::problem_3041
