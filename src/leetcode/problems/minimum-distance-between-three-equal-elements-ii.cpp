#include "leetcode/problems/minimum-distance-between-three-equal-elements-ii.h"

#include <unordered_map>

namespace leetcode::problem_3741 {

namespace {

int minimumDistanceImpl(std::vector<int>& nums) {
  std::unordered_map<int, std::vector<int>> pos;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    pos[nums[i]].push_back(i);
  }

  int best = -1;
  for (const auto& entry : pos) {
    const auto& idx = entry.second;
    if (idx.size() < 3) continue;
    for (int i = 0; i + 2 < static_cast<int>(idx.size()); ++i) {
      int span = idx[i + 2] - idx[i];
      int dist = 2 * span;
      if (best == -1 || dist < best) best = dist;
    }
  }
  return best;
}

}  // namespace

MinimumDistanceBetweenThreeEqualElementsIiSolution::
    MinimumDistanceBetweenThreeEqualElementsIiSolution() {
  setMetaInfo({.id = 3741,
               .title = "Minimum Distance Between Three Equal Elements II",
               .url = "https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/"});
  registerStrategy({.name = "hashmap-sliding-span",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table"}},
                   minimumDistanceImpl);
}

int MinimumDistanceBetweenThreeEqualElementsIiSolution::minimumDistance(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3741
