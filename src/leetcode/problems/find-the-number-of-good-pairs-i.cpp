#include "leetcode/problems/find-the-number-of-good-pairs-i.h"

namespace leetcode {
namespace problem_3162 {

namespace {

int numberOfPairsImpl(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
  int count = 0;
  for (int a : nums1) {
    for (int b : nums2) {
      if (a % (b * k) == 0) {
        ++count;
      }
    }
  }
  return count;
}

}  // namespace

FindTheNumberOfGoodPairsISolution::FindTheNumberOfGoodPairsISolution() {
  setMetaInfo({.id = 3162,
               .title = "Find the Number of Good Pairs I",
               .url = "https://leetcode.com/problems/find-the-number-of-good-pairs-i/"});
  registerStrategy(
      {.name = "BruteForce",
       .expected = "Accepted",
       .time_complexity = "O(n*m)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Enumeration"}},
      numberOfPairsImpl);
}

int FindTheNumberOfGoodPairsISolution::numberOfPairs(std::vector<int>& nums1,
                                                     std::vector<int>& nums2,
                                                     int k) {
  return getSolution()(nums1, nums2, k);
}

}  // namespace problem_3162
}  // namespace leetcode
