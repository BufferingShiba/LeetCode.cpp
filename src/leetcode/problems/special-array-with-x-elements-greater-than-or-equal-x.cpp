#include "leetcode/problems/special-array-with-x-elements-greater-than-or-equal-x.h"

namespace leetcode {
namespace problem_1608 {

namespace {

int specialArrayImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  for (int x = 0; x <= n; ++x) {
    int count = 0;
    for (int v : nums) {
      if (v >= x) {
        ++count;
      }
    }
    if (count == x) {
      return x;
    }
  }
  return -1;
}

}  // namespace

SpecialArrayWithXElementsGreaterThanOrEqualXSolution::
    SpecialArrayWithXElementsGreaterThanOrEqualXSolution() {
  setMetaInfo(
      {.id = 1608,
       .title = "Special Array With X Elements Greater Than or Equal X",
       .url = "https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/"});
  registerStrategy(
      {.name = "BruteForceCount",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Enumeration"},
       .notes = "For each candidate x in [0, n], count elements >= x."},
      specialArrayImpl);
}

int SpecialArrayWithXElementsGreaterThanOrEqualXSolution::specialArray(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1608
}  // namespace leetcode
