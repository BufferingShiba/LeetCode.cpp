#include "leetcode/problems/maximum-unique-subarray-sum-after-deletion.h"

#include <unordered_set>

namespace leetcode {
namespace problem_3487 {

namespace {

int maxSumImpl(std::vector<int>& nums) {
  std::unordered_set<int> seen;
  int sum = 0;
  int best = -101;
  bool hasPositive = false;

  for (int x : nums) {
    if (x > best) best = x;
    if (x > 0 && seen.insert(x).second) {
      sum += x;
      hasPositive = true;
    }
  }

  if (hasPositive) return sum;
  // No positive elements: must keep at least one element, pick the largest.
  return best;
}

}  // namespace

MaximumUniqueSubarraySumAfterDeletionSolution::
    MaximumUniqueSubarraySumAfterDeletionSolution() {
  setMetaInfo({.id = 3487,
               .title = "Maximum Unique Subarray Sum After Deletion",
               .url = "https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/"});

  registerStrategy(
      {.name = "greedy_hashset",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Greedy"}},
      maxSumImpl);
}

int MaximumUniqueSubarraySumAfterDeletionSolution::maxSum(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3487
}  // namespace leetcode
