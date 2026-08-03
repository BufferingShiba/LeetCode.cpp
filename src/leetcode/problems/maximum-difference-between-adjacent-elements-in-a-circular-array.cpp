#include "leetcode/problems/maximum-difference-between-adjacent-elements-in-a-circular-array.h"

#include <cstdlib>

namespace leetcode::problem_3423 {

namespace {

int maxAdjacentDistanceImpl(std::vector<int>& nums) {
  int best = 0;
  const int n = static_cast<int>(nums.size());
  for (int i = 0; i < n; ++i) {
    const int diff = std::abs(nums[i] - nums[(i + 1) % n]);
    if (diff > best) best = diff;
  }
  return best;
}

void RegisterStrategy(
    MaximumDifferenceBetweenAdjacentElementsInACircularArraySolution& solution) {
  solution.setMetaInfo({.id = 3423,
                        .title = "Maximum Difference Between Adjacent Elements "
                                 "in a Circular Array",
                        .url = "https://leetcode.com/problems/"
                               "maximum-difference-between-adjacent-elements-in-a-"
                               "circular-array/"});
  solution.registerStrategy(
      {.name = "linear_scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      maxAdjacentDistanceImpl);
}

}  // namespace

MaximumDifferenceBetweenAdjacentElementsInACircularArraySolution::
    MaximumDifferenceBetweenAdjacentElementsInACircularArraySolution() {
  RegisterStrategy(*this);
}

int MaximumDifferenceBetweenAdjacentElementsInACircularArraySolution::
    maxAdjacentDistance(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3423
