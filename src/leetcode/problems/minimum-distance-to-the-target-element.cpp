#include "leetcode/problems/minimum-distance-to-the-target-element.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_1848 {

namespace {

int getMinDistanceImpl(std::vector<int>& nums, int target, int start) {
  int best = static_cast<int>(nums.size());
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] == target) {
      best = std::min(best, std::abs(i - start));
    }
  }
  return best;
}

}  // namespace

MinimumDistanceToTheTargetElementSolution::MinimumDistanceToTheTargetElementSolution() {
  setMetaInfo({.id = 1848,
               .title = "Minimum Distance to the Target Element",
               .url = "https://leetcode.com/problems/minimum-distance-to-the-target-element/"});
  registerStrategy(
      {.name = "LinearScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      getMinDistanceImpl);
}

int MinimumDistanceToTheTargetElementSolution::getMinDistance(
    std::vector<int>& nums, int target, int start) {
  return getSolution()(nums, target, start);
}

}  // namespace leetcode::problem_1848
