#include "leetcode/problems/minimum-generations-to-target-point.h"

#include <cmath>
#include <unordered_set>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3923 {

namespace {

// Encode a 3D point (coords in [0,6]) into an integer for fast dedup.
inline int encode(const std::vector<int>& p) {
  return p[0] * 49 + p[1] * 7 + p[2];
}

int solve(std::vector<std::vector<int>>& points, std::vector<int>& target) {
  // First check whether target is already present in generation 0.
  for (const auto& p : points) {
    if (p == target) return 0;
  }

  // Maintain the full set of generated points (deduped by encoding).
  std::unordered_set<int> all;
  for (const auto& p : points) all.insert(encode(p));

  // Store raw coordinates for midpoint computation.
  std::vector<std::vector<int>> raw(points);

  int generation = 0;
  const int targetCode = encode(target);

  while (true) {
    ++generation;
    std::vector<std::vector<int>> newPoints;
    int n = static_cast<int>(raw.size());

    // Pair every two distinct points (by coordinate) to generate new points.
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        std::vector<int> c(3);
        for (int d = 0; d < 3; ++d) {
          c[d] = static_cast<int>(std::floor((raw[i][d] + raw[j][d]) / 2.0));
        }
        int code = encode(c);
        if (all.insert(code).second) {
          newPoints.push_back(std::move(c));
        }
      }
    }

    if (all.count(targetCode) > 0) return generation;

    if (newPoints.empty()) break;

    for (auto& p : newPoints) raw.push_back(std::move(p));
  }

  return -1;
}

}  // namespace

MinimumGenerationsToTargetPointSolution::MinimumGenerationsToTargetPointSolution() {
  setMetaInfo({.id = 3923,
               .title = "Minimum Generations to Target Point",
               .url = "https://leetcode.com/problems/minimum-generations-to-target-point/"});

  registerStrategy(
      {"Simulation", "Accepted", "O(C^3)", "O(C)",
       {"Array", "Hash Table", "Simulation"},
       "BFS-like simulation over the small point space ([0,6]^3, at most 343 points)."},
      solve);
}

}  // namespace problem_3923
}  // namespace leetcode
