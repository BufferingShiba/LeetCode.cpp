#include "leetcode/problems/maximum-width-ramp.h"

namespace leetcode {
namespace problem_962 {

static int solution1(vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  // Build a decreasing stack of candidate starting indices.
  // For an index i to be useful as the left end, nums[i] must be smaller
  // than every value to its left (strictly decreasing prefix).
  vector<int> stack;
  for (int i = 0; i < n; ++i) {
    if (stack.empty() || nums[i] < nums[stack.back()]) {
      stack.push_back(i);
    }
  }

  int maxWidth = 0;
  // Scan from the right; pop from stack while the candidate pair is valid.
  for (int j = n - 1; j >= 0; --j) {
    while (!stack.empty() && nums[stack.back()] <= nums[j]) {
      maxWidth = std::max(maxWidth, j - stack.back());
      stack.pop_back();
    }
  }
  return maxWidth;
}

MaximumWidthRampSolution::MaximumWidthRampSolution() {
  setMetaInfo({
      .id = 962,
      .title = "Maximum Width Ramp",
      .url = "https://leetcode.com/problems/maximum-width-ramp"
  });
  registerStrategy(
      {.name = "Monotonic Stack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Monotonic Stack", "Two Pointers"}},
      solution1);
}

int MaximumWidthRampSolution::maxWidthRamp(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_962
}  // namespace leetcode
