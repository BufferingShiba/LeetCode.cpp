#include "leetcode/problems/minimum-value-to-get-positive-step-by-step-sum.h"

#include <algorithm>

namespace leetcode::problem_1413 {

namespace {

int minStartValueImpl(std::vector<int>& nums) {
  int prefixSum = 0;
  int minPrefixSum = 0;
  for (int num : nums) {
    prefixSum += num;
    minPrefixSum = std::min(minPrefixSum, prefixSum);
  }
  // startValue + minPrefixSum >= 1 => startValue >= 1 - minPrefixSum
  // startValue must be positive.
  return std::max(1, 1 - minPrefixSum);
}

}  // namespace

MinimumValueToGetPositiveStepByStepSumSolution::
    MinimumValueToGetPositiveStepByStepSumSolution() {
  setMetaInfo({.id = 1413,
               .title = "Minimum Value to Get Positive Step by Step Sum",
               .url = "https://leetcode.com/problems/minimum-value-to-get-positi"
                      "ve-step-by-step-sum/"});
  registerStrategy({.name = "prefix_sum_min",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Prefix Sum"},
                    .notes = "Track min prefix sum; answer = max(1, 1 - min)."},
                   minStartValueImpl);
}

int MinimumValueToGetPositiveStepByStepSumSolution::minStartValue(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_1413
