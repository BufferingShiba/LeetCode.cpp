#include <algorithm>

#include "leetcode/problems/maximum-difference-between-increasing-elements.h"

namespace leetcode {
namespace problem_2016 {

namespace {

int maximumDifferenceImpl(std::vector<int>& nums) {
  int ans = -1;
  int minPrefix = nums[0];
  for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] > minPrefix) {
      ans = std::max(ans, nums[i] - minPrefix);
    }
    minPrefix = std::min(minPrefix, nums[i]);
  }
  return ans;
}

}  // namespace

MaximumDifferenceBetweenIncreasingElementsSolution::
    MaximumDifferenceBetweenIncreasingElementsSolution() {
  setMetaInfo({.id = 2016,
               .title = "Maximum Difference Between Increasing Elements",
               .url = "https://leetcode.com/problems/maximum-difference-between-increasing-elements/"});
  registerStrategy(
      {.name = "greedy_min_prefix",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"array"}},
      maximumDifferenceImpl);
}

int MaximumDifferenceBetweenIncreasingElementsSolution::maximumDifference(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2016
}  // namespace leetcode
