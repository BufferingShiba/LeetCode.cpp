#include "leetcode/problems/make-two-arrays-equal-by-reversing-subarrays.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1460 {
namespace {

bool canBeEqualImpl(std::vector<int>& target, std::vector<int>& arr) {
  std::sort(target.begin(), target.end());
  std::sort(arr.begin(), arr.end());
  return target == arr;
}

}  // namespace

MakeTwoArraysEqualByReversingSubarraysSolution::
    MakeTwoArraysEqualByReversingSubarraysSolution() {
  setMetaInfo({.id = 1460,
               .title = "Make Two Arrays Equal by Reversing Subarrays",
               .url = "https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/"});

  registerStrategy(
      {.name = "sort",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Sorting", "Array"}},
      &canBeEqualImpl);
}

bool MakeTwoArraysEqualByReversingSubarraysSolution::canBeEqual(
    std::vector<int>& target, std::vector<int>& arr) {
  return getSolution()(target, arr);
}

}  // namespace problem_1460
}  // namespace leetcode
