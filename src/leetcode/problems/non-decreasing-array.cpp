#include "leetcode/problems/non-decreasing-array.h"

namespace leetcode {
namespace problem_665 {

static bool solution1(vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int modified = 0;
  for (int i = 0; i + 1 < n; ++i) {
    if (nums[i] <= nums[i + 1]) continue;
    if (++modified > 1) return false;
    // Need to fix the violation at i (nums[i] > nums[i+1]).
    // We must keep the prefix non-decreasing. Two options:
    //   - lower nums[i] to nums[i+1]  (requires i == 0 or nums[i-1] <= nums[i+1])
    //   - raise nums[i+1] to nums[i]
    if (i == 0 || nums[i - 1] <= nums[i + 1]) {
      nums[i] = nums[i + 1];
    } else {
      nums[i + 1] = nums[i];
    }
  }
  return true;
}

NonDecreasingArraySolution::NonDecreasingArraySolution() {
  setMetaInfo({
      .id = 665,
      .title = "Non-decreasing Array",
      .url = "https://leetcode.com/problems/non-decreasing-array"
  });
  registerStrategy({.name = "Greedy",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array"},
                    .notes = "Count violations and greedily fix each one."},
                   solution1);
}

bool NonDecreasingArraySolution::checkPossibility(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_665
}  // namespace leetcode
