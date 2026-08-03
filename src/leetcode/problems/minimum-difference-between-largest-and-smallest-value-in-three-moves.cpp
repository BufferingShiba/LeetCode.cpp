#include "leetcode/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves.h"

#include <algorithm>

namespace leetcode::problem_1509 {

namespace {

int minDifferenceImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n <= 4) {
    return 0;
  }
  std::sort(nums.begin(), nums.end());
  int ans = nums.back() - nums.front();
  // Remove i smallest and (3 - i) largest elements.
  for (int i = 0; i <= 3; ++i) {
    ans = std::min(ans, nums[n - 1 - (3 - i)] - nums[i]);
  }
  return ans;
}

}  // namespace

MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesSolution::
    MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesSolution() {
  setMetaInfo({.id = 1509,
               .title = "Minimum Difference Between Largest and Smallest Value in "
                        "Three Moves",
               .url = "https://leetcode.com/problems/"
                      "minimum-difference-between-largest-and-smallest-value-in-3-moves/"});
  registerStrategy(
      {.name = "SortAndGreedy",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy", "Sorting"}},
      minDifferenceImpl);
}

int MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesSolution::minDifference(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_1509
