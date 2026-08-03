#include "leetcode/problems/count-pairs-of-points-with-distance-k.h"

#include <unordered_map>

namespace leetcode {
namespace problem_2857 {

static int solution1(vector<vector<int>>& coordinates, int k) {
  // Distance between (x,y) and (a,b) = (x^a) + (y^b) = k.
  // For a new point (x,y), iterate s in [0,k] so that (x^a)=s and (y^b)=k-s,
  // i.e. target point (a,b) = (x^s, y^(k-s)). Count previously seen points
  // equal to that target. Complexity O(n*k), k <= 100.
  constexpr long long kBase = 1000001LL;
  std::unordered_map<long long, int> seen;
  long long res = 0;
  for (const auto& p : coordinates) {
    long long x = p[0], y = p[1];
    for (int s = 0; s <= k; ++s) {
      long long a = x ^ s;
      long long b = y ^ (k - s);
      auto it = seen.find(a * kBase + b);
      if (it != seen.end()) res += it->second;
    }
    seen[x * kBase + y]++;
  }
  return static_cast<int>(res);
}

CountPairsOfPointsWithDistanceKSolution::CountPairsOfPointsWithDistanceKSolution() {
  setMetaInfo({
      .id = 2857,
      .title = "Count Pairs of Points With Distance k",
      .url = "https://leetcode.com/problems/count-pairs-of-points-with-distance-k"
  });
  registerStrategy({.name = "Hash Map",
                    .expected = "Accepted",
                    .time_complexity = "O(n*k)",
                    .space_complexity = "O(n)",
                    .tags = {"Hash Map", "Hash Table", "Bit Manipulation"}},
                   solution1);
}

int CountPairsOfPointsWithDistanceKSolution::countPairs(vector<vector<int>>& coordinates, int k) {
  return getSolution()(coordinates, k);
}

}  // namespace problem_2857
}  // namespace leetcode
