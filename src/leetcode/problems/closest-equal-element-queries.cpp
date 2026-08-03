#include "leetcode/problems/closest-equal-element-queries.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_3488 {

namespace {

std::vector<int> SolveClosestEqualElementQueries(std::vector<int>& nums,
                                                 std::vector<int>& queries) {
  const int n = static_cast<int>(nums.size());

  // Group all positions by value.
  std::unordered_map<int, std::vector<int>> positions;
  positions.reserve(n);
  for (int i = 0; i < n; ++i) {
    positions[nums[i]].push_back(i);
  }

  // Precompute the minimum circular distance to the nearest equal value for
  // each index i. Default -1 (value occurs only once).
  std::vector<int> minDist(n, -1);
  for (auto& [value, pos] : positions) {
    const int m = static_cast<int>(pos.size());
    if (m == 1) {
      continue;
    }
    for (int k = 0; k < m; ++k) {
      // Right neighbor in sorted order (with wrap-around).
      int rightDist = pos[(k + 1) % m] - pos[k];
      if (rightDist < 0) {
        rightDist += n;
      }
      if (rightDist == 0) {  // same index, should not happen since positions unique
        rightDist = n;
      }
      // Left neighbor in sorted order (with wrap-around).
      int leftDist = pos[k] - pos[(k - 1 + m) % m];
      if (leftDist < 0) {
        leftDist += n;
      }
      minDist[pos[k]] = std::min(leftDist, rightDist);
    }
  }

  std::vector<int> answer;
  answer.reserve(queries.size());
  for (int q : queries) {
    answer.push_back(minDist[q]);
  }
  return answer;
}

}  // namespace

ClosestEqualElementQueriesSolution::ClosestEqualElementQueriesSolution() {
  setMetaInfo({.id = 3488,
               .title = "Closest Equal Element Queries",
               .url = "https://leetcode.com/problems/closest-equal-element-queries/"});

  registerStrategy(
      {.name = "precompute-groups",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Binary Search"}},
      SolveClosestEqualElementQueries);
}

std::vector<int> ClosestEqualElementQueriesSolution::solveQueries(
    std::vector<int>& nums, std::vector<int>& queries) {
  return getSolution()(nums, queries);
}

}  // namespace problem_3488
}  // namespace leetcode
