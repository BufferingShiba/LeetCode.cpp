#include "leetcode/problems/two-out-of-three.h"

namespace leetcode {
namespace problem_2032 {

namespace {

std::vector<int> twoOutOfThreeImpl(std::vector<int>& nums1, std::vector<int>& nums2,
                                   std::vector<int>& nums3) {
  const int kMaxVal = 100;
  bool in1[kMaxVal + 1] = {false};
  bool in2[kMaxVal + 1] = {false};
  bool in3[kMaxVal + 1] = {false};

  for (int v : nums1) in1[v] = true;
  for (int v : nums2) in2[v] = true;
  for (int v : nums3) in3[v] = true;

  std::vector<int> result;
  for (int v = 1; v <= kMaxVal; ++v) {
    int count = (in1[v] ? 1 : 0) + (in2[v] ? 1 : 0) + (in3[v] ? 1 : 0);
    if (count >= 2) {
      result.push_back(v);
    }
  }
  return result;
}

}  // namespace

TwoOutOfThreeSolution::TwoOutOfThreeSolution() {
  setMetaInfo({.id = 2032,
               .title = "Two Out of Three",
               .url = "https://leetcode.com/problems/two-out-of-three/"});

  registerStrategy(
      {
          .name = "bool flags count",
          .expected = "Accepted",
          .time_complexity = "O(N1 + N2 + N3 + 100)",
          .space_complexity = "O(100)",
          .tags = {"Array", "Hash Table", "Bit Manipulation"},
      },
      twoOutOfThreeImpl);
}

std::vector<int> TwoOutOfThreeSolution::twoOutOfThree(
    std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3) {
  return getSolution()(nums1, nums2, nums3);
}

}  // namespace problem_2032
}  // namespace leetcode
