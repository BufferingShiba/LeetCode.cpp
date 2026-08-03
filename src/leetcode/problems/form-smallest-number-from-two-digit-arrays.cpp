#include "leetcode/problems/form-smallest-number-from-two-digit-arrays.h"

#include <algorithm>
#include <unordered_set>

namespace leetcode {
namespace problem_2605 {
namespace {

int minNumberImpl(std::vector<int>& nums1, std::vector<int>& nums2) {
  std::unordered_set<int> s1(nums1.begin(), nums1.end());

  int common = 10;
  for (int d : nums2) {
    if (s1.count(d)) {
      common = std::min(common, d);
    }
  }
  if (common < 10) {
    return common;
  }

  int min1 = *std::min_element(nums1.begin(), nums1.end());
  int min2 = *std::min_element(nums2.begin(), nums2.end());
  int a = std::min(min1, min2);
  int b = std::max(min1, min2);
  return a * 10 + b;
}

}  // namespace

FormSmallestNumberFromTwoDigitArraysSolution::
    FormSmallestNumberFromTwoDigitArraysSolution() {
  setMetaInfo({.id = 2605,
               .title = "Form Smallest Number From Two Digit Arrays",
               .url = "https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/"});
  registerStrategy(
      {"enumeration", "Accepted", "O(9 + m*n)", "O(9)",
       {"Array", "Hash Table", "Enumeration"}},
      minNumberImpl);
}

int FormSmallestNumberFromTwoDigitArraysSolution::minNumber(
    std::vector<int>& nums1, std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace problem_2605
}  // namespace leetcode
