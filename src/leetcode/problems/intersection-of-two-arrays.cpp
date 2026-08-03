#include "leetcode/problems/intersection-of-two-arrays.h"

#include <unordered_set>

namespace leetcode {
namespace problem_349 {

namespace {

std::vector<int> intersectionHashSet(std::vector<int>& nums1,
                                     std::vector<int>& nums2) {
  std::unordered_set<int> set(nums1.begin(), nums1.end());
  std::vector<int> result;
  for (int num : nums2) {
    if (set.erase(num)) {
      result.push_back(num);
    }
  }
  return result;
}

}  // namespace

IntersectionOfTwoArraysSolution::IntersectionOfTwoArraysSolution() {
  setMetaInfo({.id = 349,
               .title = "Intersection of Two Arrays",
               .url = "https://leetcode.com/problems/intersection-of-two-arrays/"});
  registerStrategy(
      {.name = "HashSet",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "Array"}},
      intersectionHashSet);
}

std::vector<int> IntersectionOfTwoArraysSolution::intersection(
    std::vector<int>& nums1, std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace problem_349
}  // namespace leetcode
