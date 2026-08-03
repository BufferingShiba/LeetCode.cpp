#include "leetcode/problems/minimum-operations-to-transform-array.h"

#include <algorithm>
#include <cstdlib>
#include <vector>

namespace leetcode {
namespace problem_3724 {
namespace {

long long minOperationsImpl(std::vector<int>& nums1, std::vector<int>& nums2) {
  const int n = static_cast<int>(nums1.size());
  const long long target = nums2[n];

  long long baseCost = 1;  // the single append operation
  long long bestExtra = llabs(target - nums1[0]);  // best copy->target adjustment

  for (int i = 0; i < n; ++i) {
    baseCost += std::llabs(static_cast<long long>(nums1[i]) - nums2[i]);
    long long lo = static_cast<long long>(std::min(nums1[i], nums2[i]));
    long long hi = static_cast<long long>(std::max(nums1[i], nums2[i]));
    // The copied value (start of the appended element) can be any integer in
    // [lo, hi] reachable while adjusting source i. Pick the closest to target.
    long long extra = 0;
    if (target < lo) extra = lo - target;
    else if (target > hi) extra = target - hi;
    bestExtra = std::min(bestExtra, extra);
  }

  return baseCost + bestExtra;
}

}  // namespace

MinimumOperationsToTransformArraySolution::MinimumOperationsToTransformArraySolution() {
  setMetaInfo({.id = 3724,
               .title = "Minimum Operations to Transform Array",
               .url = "https://leetcode.com/problems/minimum-operations-to-transform-array/"});
  registerStrategy({
      .name = "GreedyInterval",
      .expected = "Accepted",
      .time_complexity = "O(n)",
      .space_complexity = "O(1)",
      .tags = {"Array", "Greedy"},
  }, minOperationsImpl);
}

long long MinimumOperationsToTransformArraySolution::minOperations(
    std::vector<int>& nums1, std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace problem_3724
}  // namespace leetcode
