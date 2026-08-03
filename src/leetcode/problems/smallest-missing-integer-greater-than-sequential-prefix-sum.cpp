#include <unordered_set>

#include "leetcode/problems/smallest-missing-integer-greater-than-sequential-prefix-sum.h"

namespace leetcode {
namespace problem_2996 {

namespace {

int missingIntegerImpl(std::vector<int>& nums) {
  // Compute the sum of the longest sequential prefix starting at nums[0].
  int prefixSum = nums[0];
  int i = 1;
  while (i < static_cast<int>(nums.size()) && nums[i] == nums[i - 1] + 1) {
    prefixSum += nums[i];
    ++i;
  }

  // Record all elements of nums for O(1) membership checks.
  std::unordered_set<int> present(nums.begin(), nums.end());

  // Find the smallest integer >= prefixSum that is missing from nums.
  int x = prefixSum;
  while (present.count(x)) {
    ++x;
  }
  return x;
}

}  // namespace

SmallestMissingIntegerGreaterThanSequentialPrefixSumSolution::
    SmallestMissingIntegerGreaterThanSequentialPrefixSumSolution() {
  setMetaInfo({.id = 2996,
               .title = "Smallest Missing Integer Greater Than Sequential Prefix Sum",
               .url = "https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/"});
  registerStrategy(
      {.name = "SequentialPrefixSum",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      missingIntegerImpl);
}

int SmallestMissingIntegerGreaterThanSequentialPrefixSumSolution::missingInteger(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2996
}  // namespace leetcode
