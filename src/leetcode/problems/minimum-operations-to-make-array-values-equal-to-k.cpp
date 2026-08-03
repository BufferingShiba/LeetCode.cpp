#include "leetcode/problems/minimum-operations-to-make-array-values-equal-to-k.h"

#include <unordered_set>

namespace leetcode::problem_3375 {
namespace {

int minOperationsImpl(std::vector<int>& nums, int k) {
  std::unordered_set<int> seen;
  for (int v : nums) {
    if (v < k) {
      return -1;
    }
    if (v > k) {
      seen.insert(v);
    }
  }
  return static_cast<int>(seen.size());
}

}  // namespace

MinimumOperationsToMakeArrayValuesEqualToKSolution::
    MinimumOperationsToMakeArrayValuesEqualToKSolution() {
  this->setMetaInfo({.id = 3375,
                     .title = "Minimum Operations to Make Array Values Equal to K",
                     .url = "https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/"});
  this->registerStrategy(
      {.name = "hashset",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      minOperationsImpl);
}

int MinimumOperationsToMakeArrayValuesEqualToKSolution::minOperations(
    std::vector<int>& nums, int k) {
  return this->getSolution()(nums, k);
}

}  // namespace leetcode::problem_3375
