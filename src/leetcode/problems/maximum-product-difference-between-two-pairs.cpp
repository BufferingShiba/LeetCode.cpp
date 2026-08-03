#include "leetcode/problems/maximum-product-difference-between-two-pairs.h"

#include <algorithm>

namespace leetcode {
namespace problem_1913 {

namespace {

int maxProductDifferenceImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  int n = static_cast<int>(nums.size());
  return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
}

}  // namespace

MaximumProductDifferenceBetweenTwoPairsSolution::
    MaximumProductDifferenceBetweenTwoPairsSolution() {
  setMetaInfo({.id = 1913,
               .title = "Maximum Product Difference Between Two Pairs",
               .url = "https://leetcode.com/problems/maximum-product-difference-between-two-pairs/"});

  registerStrategy(
      {.name = "sorting",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sorting"}},
      maxProductDifferenceImpl);
}

int MaximumProductDifferenceBetweenTwoPairsSolution::maxProductDifference(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1913
}  // namespace leetcode
