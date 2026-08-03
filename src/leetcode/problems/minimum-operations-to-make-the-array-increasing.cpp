#include "leetcode/problems/minimum-operations-to-make-the-array-increasing.h"

namespace leetcode::problem_1827 {

namespace {
int minOperationsImpl(std::vector<int>& nums) {
  int operations = 0;
  int prev = nums[0];
  for (std::size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] <= prev) {
      operations += (prev + 1) - nums[i];
      nums[i] = prev + 1;
    }
    prev = nums[i];
  }
  return operations;
}
}  // namespace

MinimumOperationsToMakeTheArrayIncreasingSolution::
    MinimumOperationsToMakeTheArrayIncreasingSolution() {
  setMetaInfo(
      {.id = 1827,
       .title = "Minimum Operations to Make the Array Increasing",
       .url = "https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/"});

  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      minOperationsImpl);
}

int MinimumOperationsToMakeTheArrayIncreasingSolution::minOperations(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_1827
