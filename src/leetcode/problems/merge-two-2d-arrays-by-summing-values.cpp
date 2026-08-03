#include "leetcode/problems/merge-two-2d-arrays-by-summing-values.h"

namespace leetcode {
namespace problem_2570 {

namespace {

std::vector<std::vector<int>> mergeArraysImpl(
    std::vector<std::vector<int>>& nums1,
    std::vector<std::vector<int>>& nums2) {
  std::vector<std::vector<int>> result;
  result.reserve(nums1.size() + nums2.size());
  std::size_t i = 0, j = 0;
  while (i < nums1.size() && j < nums2.size()) {
    if (nums1[i][0] == nums2[j][0]) {
      result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
      ++i;
      ++j;
    } else if (nums1[i][0] < nums2[j][0]) {
      result.push_back(nums1[i]);
      ++i;
    } else {
      result.push_back(nums2[j]);
      ++j;
    }
  }
  while (i < nums1.size()) {
    result.push_back(nums1[i++]);
  }
  while (j < nums2.size()) {
    result.push_back(nums2[j++]);
  }
  return result;
}

}  // namespace

MergeTwo2dArraysBySummingValuesSolution::
    MergeTwo2dArraysBySummingValuesSolution() {
  setMetaInfo({.id = 2570,
               .title = "Merge Two 2D Arrays by Summing Values",
               .url = "https://leetcode.com/problems/merge-two-2d-arrays-by-"
                      "summing-values/"});
  registerStrategy(
      {.name = "TwoPointers",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(1) (excluding output)",
       .tags = {"Array", "Hash Table", "Two Pointers"}},
      mergeArraysImpl);
}

std::vector<std::vector<int>>
MergeTwo2dArraysBySummingValuesSolution::mergeArrays(
    std::vector<std::vector<int>>& nums1,
    std::vector<std::vector<int>>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace problem_2570
}  // namespace leetcode
