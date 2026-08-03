#include "leetcode/problems/smallest-range-i.h"

#include <algorithm>

namespace leetcode {
namespace problem_908 {
namespace {

int smallestRangeIImpl(std::vector<int>& nums, int k) {
  int minVal = *std::min_element(nums.begin(), nums.end());
  int maxVal = *std::max_element(nums.begin(), nums.end());
  int diff = maxVal - minVal;
  return std::max(0, diff - 2 * k);
}

}  // namespace

SmallestRangeISolution::SmallestRangeISolution() {
  setMetaInfo({.id = 908,
               .title = "Smallest Range I",
               .url = "https://leetcode.com/problems/smallest-range-i/"});
  registerStrategy({.name = "math",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math"}},  //
                   smallestRangeIImpl);
}

int SmallestRangeISolution::smallestRangeI(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_908
}  // namespace leetcode
