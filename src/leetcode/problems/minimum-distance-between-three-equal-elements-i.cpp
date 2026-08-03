#include "leetcode/problems/minimum-distance-between-three-equal-elements-i.h"

namespace leetcode {
namespace problem_3740 {

namespace {

int minimumDistanceImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  std::unordered_map<int, std::vector<int>> pos;
  for (int i = 0; i < n; ++i) {
    pos[nums[i]].push_back(i);
  }

  int best = INT_MAX;
  for (const auto& [val, idx] : pos) {
    (void)val;
    const int m = static_cast<int>(idx.size());
    for (int z = 0; z + 2 < m; ++z) {
      best = std::min(best, 2 * (idx[z + 2] - idx[z]));
    }
  }

  return best == INT_MAX ? -1 : best;
}

}  // namespace

MinimumDistanceBetweenThreeEqualElementsISolution::
    MinimumDistanceBetweenThreeEqualElementsISolution() {
  setMetaInfo({.id = 3740,
               .title = "Minimum Distance Between Three Equal Elements I",
               .url = "https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/"});
  registerStrategy(
      {.name = "HashTable+SlidingWindow",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      minimumDistanceImpl);
}

int MinimumDistanceBetweenThreeEqualElementsISolution::minimumDistance(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3740
}  // namespace leetcode
