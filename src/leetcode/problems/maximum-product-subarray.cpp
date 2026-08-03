#include "leetcode/problems/maximum-product-subarray.h"

#include <algorithm>

namespace leetcode {
namespace problem_152 {

// DP: track max product and min product ending at current position.
// A negative number can swap max and min. Keep curMax and curMin, update global answer.
static int solution1(vector<int>& nums) {
  int curMax = nums[0];
  int curMin = nums[0];
  int ans = nums[0];
  for (size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] < 0) std::swap(curMax, curMin);
    curMax = std::max(nums[i], curMax * nums[i]);
    curMin = std::min(nums[i], curMin * nums[i]);
    ans = std::max(ans, curMax);
  }
  return ans;
}

MaximumProductSubarraySolution::MaximumProductSubarraySolution() {
  setMetaInfo({
      .id = 152,
      .title = "Maximum Product Subarray",
      .url = "https://leetcode.com/problems/maximum-product-subarray"
  });
  registerStrategy({.name = "DP", .expected = "Accepted",
                    .time_complexity = "O(n)", .space_complexity = "O(1)",
                    .tags = {"Array", "Dynamic Programming"}},
                   solution1);
}

int MaximumProductSubarraySolution::maxProduct(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_152
}  // namespace leetcode
