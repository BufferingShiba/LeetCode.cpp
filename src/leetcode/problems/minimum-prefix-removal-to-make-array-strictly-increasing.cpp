#include "leetcode/problems/minimum-prefix-removal-to-make-array-strictly-increasing.h"

namespace leetcode::problem_3818 {

static int minimumPrefixLengthImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  if (n <= 1) return 0;
  for (int i = n - 2; i >= 0; --i) {
    if (nums[i] >= nums[i + 1]) {
      return i + 1;
    }
  }
  return 0;
}

MinimumPrefixRemovalToMakeArrayStrictlyIncreasingSolution::
    MinimumPrefixRemovalToMakeArrayStrictlyIncreasingSolution() {
  setMetaInfo({.id = 3818,
               .title = "Minimum Prefix Removal to Make Array Strictly Increasing",
               .url = "https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/"});
  registerStrategy({.name = "linear_scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array"}},
                   minimumPrefixLengthImpl);
  setDefaultStrategy();
}

int MinimumPrefixRemovalToMakeArrayStrictlyIncreasingSolution::minimumPrefixLength(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3818
