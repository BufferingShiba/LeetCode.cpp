#include <vector>

#include "leetcode/problems/count-elements-with-strictly-smaller-and-greater-elements.h"

namespace leetcode::problem_2148 {

namespace {

int countElementsImpl(std::vector<int>& nums) {
  int mn = nums[0];
  int mx = nums[0];
  for (int v : nums) {
    if (v < mn) mn = v;
    if (v > mx) mx = v;
  }
  if (mn == mx) return 0;
  int cnt = 0;
  for (int v : nums) {
    if (v > mn && v < mx) ++cnt;
  }
  return cnt;
}

}  // namespace

int CountElementsWithStrictlySmallerAndGreaterElementsSolution::countElements(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

CountElementsWithStrictlySmallerAndGreaterElementsSolution::
    CountElementsWithStrictlySmallerAndGreaterElementsSolution() {
  setMetaInfo({.id = 2148,
               .title = "Count Elements With Strictly Smaller and Greater Elements",
               .url = "https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/"});
  registerStrategy(
      {.name = "min_max_count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      countElementsImpl);
}

}  // namespace leetcode::problem_2148
