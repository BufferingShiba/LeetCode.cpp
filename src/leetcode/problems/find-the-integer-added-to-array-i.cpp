#include "leetcode/problems/find-the-integer-added-to-array-i.h"

#include <algorithm>

namespace leetcode {
namespace problem_3131 {

namespace {

int addedIntegerImpl(std::vector<int>& nums1, std::vector<int>& nums2) {
  return *std::min_element(nums2.begin(), nums2.end()) -
         *std::min_element(nums1.begin(), nums1.end());
}

}  // namespace

FindTheIntegerAddedToArrayISolution::FindTheIntegerAddedToArrayISolution() {
  setMetaInfo({.id = 3131,
               .title = "Find the Integer Added to Array I",
               .url = "https://leetcode.com/problems/find-the-integer-added-to-array-i/"});

  registerStrategy(
      {.name = "Min difference",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      addedIntegerImpl);
}

int FindTheIntegerAddedToArrayISolution::addedInteger(std::vector<int>& nums1,
                                                      std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace problem_3131
}  // namespace leetcode
