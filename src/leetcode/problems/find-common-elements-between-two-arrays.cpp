#include "leetcode/problems/find-common-elements-between-two-arrays.h"

namespace leetcode {
namespace problem_2956 {

namespace {

std::vector<int> findIntersectionValuesImpl(std::vector<int>& nums1,
                                            std::vector<int>& nums2) {
  bool present1[101] = {false};
  bool present2[101] = {false};

  for (int x : nums1) present1[x] = true;
  for (int x : nums2) present2[x] = true;

  int answer1 = 0;
  for (int x : nums1) {
    if (present2[x]) ++answer1;
  }

  int answer2 = 0;
  for (int x : nums2) {
    if (present1[x]) ++answer2;
  }

  return {answer1, answer2};
}

}  // namespace

FindCommonElementsBetweenTwoArraysSolution::
    FindCommonElementsBetweenTwoArraysSolution() {
  setMetaInfo({2956,
               "Find Common Elements Between Two Arrays",
               "https://leetcode.com/problems/find-common-elements-between-two-arrays/"});

  registerStrategy(
      {"Boolean Array",
       "Accepted",
       "O(n + m)",
       "O(1)",
       {"Array", "Hash Table"},
       ""},
      findIntersectionValuesImpl);

  setDefaultStrategy();
}

std::vector<int> FindCommonElementsBetweenTwoArraysSolution::findIntersectionValues(
    std::vector<int>& nums1, std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace problem_2956
}  // namespace leetcode
