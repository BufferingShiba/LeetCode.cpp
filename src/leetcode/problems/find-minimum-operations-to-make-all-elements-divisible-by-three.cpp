#include "leetcode/problems/find-minimum-operations-to-make-all-elements-divisible-by-three.h"

namespace leetcode::problem_3190 {

namespace {

int minimumOperationsImpl(std::vector<int>& nums) {
  int ops = 0;
  for (int x : nums) {
    if (x % 3 != 0) {
      ++ops;
    }
  }
  return ops;
}

}  // namespace

FindMinimumOperationsToMakeAllElementsDivisibleByThreeSolution::
    FindMinimumOperationsToMakeAllElementsDivisibleByThreeSolution() {
  setMetaInfo({
      .id = 3190,
      .title = "Find Minimum Operations to Make All Elements Divisible by Three",
      .url =
          "https://leetcode.com/problems/find-minimum-operations-to-make-all-"
          "elements-divisible-by-three/",
  });
  registerStrategy(
      {.name = "O(n) scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      minimumOperationsImpl);
  setDefaultStrategy();
}

int FindMinimumOperationsToMakeAllElementsDivisibleByThreeSolution::
    minimumOperations(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3190
