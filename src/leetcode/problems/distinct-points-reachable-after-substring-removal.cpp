#include "leetcode/problems/distinct-points-reachable-after-substring-removal.h"

#include <string>
#include <unordered_set>
#include <utility>

namespace leetcode {
namespace problem_3694 {
namespace {

using Point = std::pair<int, int>;

Point dir(char c) {
  switch (c) {
    case 'U': return {0, 1};
    case 'D': return {0, -1};
    case 'L': return {-1, 0};
    default: return {1, 0};  // 'R'
  }
}

int distinctPointsImpl(std::string s, int k) {
  const int n = static_cast<int>(s.size());

  // Prefix sum of displacements. P[i] = displacement of first i chars.
  std::vector<Point> P(n + 1, {0, 0});
  for (int i = 0; i < n; ++i) {
    Point d = dir(s[i]);
    P[i + 1] = {P[i].first + d.first, P[i].second + d.second};
  }

  // Each removed window [i, i+k) gives remaining displacement = P[i] + (P[n] - P[i+k]).
  // Since P[n] is constant per string, distinct endpoints correspond to distinct
  // window vectors (P[i+k] - P[i]).
  std::unordered_set<long long> seen;
  for (int i = 0; i + k <= n; ++i) {
    long long dx = P[i + k].first - P[i].first;
    long long dy = P[i + k].second - P[i].second;
    // Encode 2D vector into single 64-bit key.
    seen.insert((dx << 32) ^ (dy & 0xFFFFFFFFLL));
  }

  return static_cast<int>(seen.size());
}

}  // namespace

DistinctPointsReachableAfterSubstringRemovalSolution::
    DistinctPointsReachableAfterSubstringRemovalSolution() {
  setMetaInfo({.id = 3694,
               .title =
                   "Distinct Points Reachable After Substring Removal",
               .url = "https://leetcode.com/problems/distinct-points-reachable-after-substring-removal/"});
  registerStrategy({.name = "SlidingWindowPrefix",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Hash Table", "Sliding Window", "Prefix Sum"}},
                   distinctPointsImpl);
}

int DistinctPointsReachableAfterSubstringRemovalSolution::distinctPoints(
    std::string s, int k) {
  return getSolution()(s, k);
}

}  // namespace problem_3694
}  // namespace leetcode
