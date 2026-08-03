#include "leetcode/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i.h"

namespace leetcode {
namespace problem_3191 {

namespace {

// Greedy + difference-array effect tracking.
// Scan left to right. If the current element is 0, we must flip the
// triple starting at i (indices i, i+1, i+2), since no future operation
// can reach position i. Accumulate the effective flips so far and take
// the parity to decide the current bit after all flips.
int minOperationsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int ans = 0;
  int flip = 0;              // effective number of flips affecting current bit
  // diff tracks when a flip started at position i stops affecting at i+3.
  std::vector<int> diff(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    flip += diff[i];
    const int cur = nums[i] ^ (flip & 1);
    if (cur == 0) {
      // Must flip triple starting at i; only possible if i + 2 < n.
      if (i + 2 >= n) {
        return -1;
      }
      ++ans;
      ++flip;
      if (i + 3 < n) {
        diff[i + 3] -= 1;
      }
    }
  }
  return ans;
}

}  // namespace

int MinimumOperationsToMakeBinaryArrayElementsEqualToOneISolution::minOperations(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

MinimumOperationsToMakeBinaryArrayElementsEqualToOneISolution::
    MinimumOperationsToMakeBinaryArrayElementsEqualToOneISolution() {
  setMetaInfo(
      {.id = 3191,
       .title = "Minimum Operations to Make Binary Array Elements Equal to One I",
       .url = "https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/"});

  registerStrategy(
      {.name = "greedy-diff",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy", "Bit Manipulation"}},
      minOperationsImpl);
}

}  // namespace problem_3191
}  // namespace leetcode
