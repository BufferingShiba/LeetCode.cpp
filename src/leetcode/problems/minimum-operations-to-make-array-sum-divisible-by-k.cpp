#include <numeric>

#include "leetcode/problems/minimum-operations-to-make-array-sum-divisible-by-k.h"

namespace leetcode {
namespace problem_3512 {

namespace {

int minOperationsImpl(std::vector<int>& nums, int k) {
  long long sum = 0;
  for (int num : nums) {
    sum += num;
  }
  return static_cast<int>(sum % k);
}

}  // namespace

MinimumOperationsToMakeArraySumDivisibleByKSolution::
    MinimumOperationsToMakeArraySumDivisibleByKSolution() {
  setMetaInfo({.id = 3512,
               .title =
                   "Minimum Operations to Make Array Sum Divisible by K",
               .url = "https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/"});
  registerStrategy({.name = "ModuloSum",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math"}},
                   minOperationsImpl);
}

int MinimumOperationsToMakeArraySumDivisibleByKSolution::minOperations(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3512
}  // namespace leetcode
