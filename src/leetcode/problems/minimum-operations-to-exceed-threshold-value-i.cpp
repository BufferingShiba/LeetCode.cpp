#include "leetcode/problems/minimum-operations-to-exceed-threshold-value-i.h"

namespace leetcode::problem_3065 {

namespace {

int minOperationsImpl(std::vector<int>& nums, int k) {
  int count = 0;
  for (int num : nums) {
    if (num < k) {
      ++count;
    }
  }
  return count;
}

}  // namespace

int MinimumOperationsToExceedThresholdValueISolution::minOperations(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

MinimumOperationsToExceedThresholdValueISolution::
    MinimumOperationsToExceedThresholdValueISolution() {
  setMetaInfo({.id = 3065,
               .title = "Minimum Operations to Exceed Threshold Value I",
               .url = "https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/"});
  registerStrategy(
      {.name = "CountLessThanK",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      minOperationsImpl);
  setDefaultStrategy();
}

}  // namespace leetcode::problem_3065
