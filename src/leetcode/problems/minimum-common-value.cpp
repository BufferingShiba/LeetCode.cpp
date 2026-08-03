#include "leetcode/problems/minimum-common-value.h"

namespace leetcode {
namespace problem_2540 {

namespace {

int getCommonImpl(std::vector<int>& nums1, std::vector<int>& nums2) {
  int i = 0;
  int j = 0;
  while (i < static_cast<int>(nums1.size()) &&
         j < static_cast<int>(nums2.size())) {
    if (nums1[i] == nums2[j]) {
      return nums1[i];
    }
    if (nums1[i] < nums2[j]) {
      ++i;
    } else {
      ++j;
    }
  }
  return -1;
}

}  // namespace

MinimumCommonValueSolution::MinimumCommonValueSolution() {
  setMetaInfo({.id = 2540,
               .title = "Minimum Common Value",
               .url = "https://leetcode.com/problems/minimum-common-value/"});
  registerStrategy(
      {.name = "two-pointers",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers"}},
      getCommonImpl);
}

int MinimumCommonValueSolution::getCommon(std::vector<int>& nums1,
                                          std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace problem_2540
}  // namespace leetcode
