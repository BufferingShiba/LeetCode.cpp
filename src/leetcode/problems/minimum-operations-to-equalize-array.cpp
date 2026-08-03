#include "leetcode/problems/minimum-operations-to-equalize-array.h"

namespace leetcode {
namespace problem_3674 {

static int minOperationsImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  for (int i = 1; i < n; ++i) {
    if (nums[i] != nums[0]) {
      return 1;
    }
  }
  return 0;
}

MinimumOperationsToEqualizeArraySolution::MinimumOperationsToEqualizeArraySolution() {
  setMetaInfo({.id = 3674,
               .title = "Minimum Operations to Equalize Array",
               .url = "https://leetcode.com/problems/minimum-operations-to-equalize-array/"});
  registerStrategy({.name = "single-pass",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Bit Manipulation", "Brainteaser"}},
                   minOperationsImpl);
}

int MinimumOperationsToEqualizeArraySolution::minOperations(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3674
}  // namespace leetcode
