#include "leetcode/problems/minimum-total-cost-to-make-arrays-unequal.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_2499 {
namespace {

// Greedy + counting.
// Bad positions (where nums1[i] == nums2[i]) must participate in swaps.
// If some value v occurs more than half of the bad positions, it is
// "dominant": those bad positions need partners. They can be resolved
// internally (pairing among the bad positions) when 2*count(v) <= total.
// Otherwise we must bring in non-bad indices j. A helper j must satisfy
// BOTH nums1[j] != v (so the bad cell receives a usable value) and
// nums2[j] != v (so cell j stays valid after receiving v).
// The answer is the sum of all indices used.
long long minimumTotalCostImpl(std::vector<int>& nums1,
                               std::vector<int>& nums2) {
  const int n = static_cast<int>(nums1.size());

  long long ans = 0;
  int badCount = 0;
  std::unordered_map<int, int> cnt;
  int dominant = 0;

  for (int i = 0; i < n; ++i) {
    if (nums1[i] == nums2[i]) {
      ans += i;
      ++badCount;
      ++cnt[nums1[i]];
      if (cnt[nums1[i]] > cnt[dominant]) {
        dominant = nums1[i];
      }
    }
  }

  if (badCount == 0) return 0;

  int need = 2 * cnt[dominant] - badCount;
  if (need <= 0) return ans;

  // Collect non-bad indices whose nums1 value != dominant AND nums2 value
  // != dominant, as partners.
  std::vector<int> cand;
  cand.reserve(need);
  for (int i = 0; i < n; ++i) {
    if (nums1[i] != nums2[i] && nums1[i] != dominant &&
        nums2[i] != dominant) {
      cand.push_back(i);
    }
  }

  if (static_cast<int>(cand.size()) < need) return -1;

  std::partial_sort(cand.begin(), cand.begin() + need, cand.end());
  for (int i = 0; i < need; ++i) ans += cand[i];
  return ans;
}

}  // namespace

MinimumTotalCostToMakeArraysUnequalSolution::
    MinimumTotalCostToMakeArraysUnequalSolution() {
  setMetaInfo({.id = 2499,
               .title = "Minimum Total Cost to Make Arrays Unequal",
               .url = "https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/"});

  registerStrategy(
      {.name = "GreedyCounting",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Greedy", "Counting"},
       .notes =
           "Bad positions must swap; if a dominant value exceeds half of bad "
           "positions, bring in cheapest non-bad indices that keep the swap "
           "valid on both ends."},
      minimumTotalCostImpl);
}

}  // namespace problem_2499
}  // namespace leetcode
