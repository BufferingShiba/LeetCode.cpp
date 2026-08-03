#include "leetcode/problems/maximum-product-of-three-numbers.h"

#include <algorithm>

namespace leetcode {
namespace problem_628 {
namespace {

int maximumProductImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  std::sort(nums.begin(), nums.end());
  int cand1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
  int cand2 = nums[0] * nums[1] * nums[n - 1];
  return std::max(cand1, cand2);
}

}  // namespace

MaximumProductOfThreeNumbersSolution::MaximumProductOfThreeNumbersSolution() {
  setMetaInfo({.id = 628,
               .title = "Maximum Product of Three Numbers",
               .url = "https://leetcode.com/problems/maximum-product-of-three-numbers/"});

  registerStrategy({.name = "sort",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math", "Sorting"}},
                   maximumProductImpl);
}

int MaximumProductOfThreeNumbersSolution::maximumProduct(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_628
}  // namespace leetcode
