#include "leetcode/problems/minimum-cost-to-equalize-arrays-using-swaps.h"

#include <algorithm>

namespace leetcode {
namespace problem_3868 {
namespace {

int minCostImpl(std::vector<int>& nums1, std::vector<int>& nums2) {
  const int n = static_cast<int>(nums1.size());
  const int kLimit = 80000;

  std::vector<long long> freq(kLimit + 1, 0);
  for (int i = 0; i < n; ++i) {
    ++freq[nums1[i]];
    ++freq[nums2[i]];
  }

  // Any value with odd total count makes it impossible to split into two
  // identical multisets.
  for (int v = 1; v <= kLimit; ++v) {
    if (freq[v] % 2 != 0) {
      return -1;
    }
  }

  // For columns where nums1[i] != nums2[i], a cross-array swap (cost 1) moves
  // the "side1" token from value nums1[i] to value nums2[i]. Within-array swaps
  // are free, so only multisets matter. For each value v define:
  //   s1_v = number of unequal columns whose nums1 side holds v
  //   s2_v = number of unequal columns whose nums2 side holds v
  // We need s1_v to equal (s1_v + s2_v) / 2 for every v. Each flip changes two
  // such contributions by 1, so the minimum number of flips (= cost) equals
  //    (1/4) * sum_v |s1_v - s2_v| = (1/2) * sum_v |s1_v - s2_v| / 2.
  std::vector<long long> s1(kLimit + 1, 0);
  std::vector<long long> s2(kLimit + 1, 0);
  for (int i = 0; i < n; ++i) {
    if (nums1[i] != nums2[i]) {
      ++s1[nums1[i]];
      ++s2[nums2[i]];
    }
  }

  long long total = 0;
  for (int v = 1; v <= kLimit; ++v) {
    total += std::llabs(s1[v] - s2[v]);
  }
  return static_cast<int>(total / 4);
}

}  // namespace

MinimumCostToEqualizeArraysUsingSwapsSolution::
    MinimumCostToEqualizeArraysUsingSwapsSolution() {
  setMetaInfo({.id = 3868,
               .title = "Minimum Cost to Equalize Arrays Using Swaps",
               .url = "https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps/"});
  registerStrategy(
      {.name = "counting-mismatch",
       .expected = "O(n)",
       .space_complexity = "O(V)",
       .tags = {"Array", "Hash Table", "Greedy", "Counting"}},
      minCostImpl);
}

}  // namespace problem_3868
}  // namespace leetcode
