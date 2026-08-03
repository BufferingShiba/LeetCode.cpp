#include "leetcode/problems/smallest-stable-index-ii.h"

namespace leetcode::problem_3904 {

namespace {

int firstStableIndexImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());
  std::vector<int> suf_min(n);
  suf_min[n - 1] = nums[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suf_min[i] = std::min(nums[i], suf_min[i + 1]);
  }
  int pref_max = INT32_MIN;
  for (int i = 0; i < n; ++i) {
    pref_max = std::max(pref_max, nums[i]);
    if (pref_max - suf_min[i] <= k) {
      return i;
    }
  }
  return -1;
}

}  // namespace

int SmallestStableIndexIiSolution::firstStableIndex(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

SmallestStableIndexIiSolution::SmallestStableIndexIiSolution() {
  setMetaInfo({.id = 3904,
               .title = "Smallest Stable Index II",
               .url = "https://leetcode.com/problems/smallest-stable-index-ii/"});
  registerStrategy(
      {.name = "prefix_max_suffix_min",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Prefix Sum"}},
      firstStableIndexImpl);
}

}  // namespace leetcode::problem_3904
