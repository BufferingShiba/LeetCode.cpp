#include "leetcode/problems/minimum-average-of-smallest-and-largest-elements.h"

#include <algorithm>

namespace leetcode::problem_3194 {

namespace {

double minimumAverageImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  int n = static_cast<int>(nums.size());
  double result = static_cast<double>(nums[0] + nums[n - 1]) / 2.0;
  for (int i = 1; i < n / 2; ++i) {
    result =
        std::min(result, static_cast<double>(nums[i] + nums[n - 1 - i]) / 2.0);
  }
  return result;
}

}  // namespace

MinimumAverageOfSmallestAndLargestElementsSolution::
    MinimumAverageOfSmallestAndLargestElementsSolution() {
  setMetaInfo({.id = 3194,
               .title = "Minimum Average of Smallest and Largest Elements",
               .url = "https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/"});
  registerStrategy(
      {.name = "sort_and_pair",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Sorting"}},
      minimumAverageImpl);
}

double MinimumAverageOfSmallestAndLargestElementsSolution::minimumAverage(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3194
