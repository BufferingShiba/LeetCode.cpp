#include "leetcode/problems/array-with-elements-not-equal-to-average-of-neighbors.h"

#include <algorithm>

namespace leetcode {
namespace problem_1968 {

static std::vector<int> rearrangeArrayImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  int n = static_cast<int>(nums.size());
  std::vector<int> result(n);
  int half = (n + 1) / 2;  // size of the smaller half
  for (int i = 0; i < half; ++i) {
    result[2 * i] = nums[i];
  }
  for (int i = 0; i < n - half; ++i) {
    result[2 * i + 1] = nums[half + i];
  }
  return result;
}

ArrayWithElementsNotEqualToAverageOfNeighborsSolution::
    ArrayWithElementsNotEqualToAverageOfNeighborsSolution() {
  setMetaInfo({.id = 1968,
               .title = "Array With Elements Not Equal to Average of Neighbors",
               .url = "https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/"});
  registerStrategy({.name = "SortAndInterleave",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Greedy", "Sorting"}},
                   rearrangeArrayImpl);
  setDefaultStrategy();
}

std::vector<int> ArrayWithElementsNotEqualToAverageOfNeighborsSolution::rearrangeArray(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1968
}  // namespace leetcode
