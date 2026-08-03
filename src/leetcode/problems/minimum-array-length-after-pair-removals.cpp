#include "leetcode/problems/minimum-array-length-after-pair-removals.h"

namespace leetcode::problem_2856 {

namespace {

int minLengthAfterRemovalsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n <= 1) return n;

  int maxFreq = 1;
  int cur = 1;
  for (int i = 1; i < n; ++i) {
    if (nums[i] == nums[i - 1]) {
      ++cur;
    } else {
      maxFreq = std::max(maxFreq, cur);
      cur = 1;
    }
  }
  maxFreq = std::max(maxFreq, cur);

  if (maxFreq > n - maxFreq) {
    return 2 * maxFreq - n;
  }
  return n % 2;
}

}  // namespace

MinimumArrayLengthAfterPairRemovalsSolution::
    MinimumArrayLengthAfterPairRemovalsSolution() {
  setMetaInfo({.id = 2856,
               .title = "Minimum Array Length After Pair Removals",
               .url = "https://leetcode.com/problems/minimum-array-length-after-pair-removals/"});
  registerStrategy({.name = "greedy_count",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Counting", "Greedy"},
                    .notes = "If max frequency M > n/2 answer is 2M-n, otherwise n%2."},
                   minLengthAfterRemovalsImpl);
}

int MinimumArrayLengthAfterPairRemovalsSolution::minLengthAfterRemovals(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2856
