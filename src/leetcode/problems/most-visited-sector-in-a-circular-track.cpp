#include "leetcode/problems/most-visited-sector-in-a-circular-track.h"

#include <algorithm>

namespace leetcode::problem_1560 {

namespace {

std::vector<int> mostVisitedImpl(int n, std::vector<int>& rounds) {
  std::vector<int> cnt(n + 1, 0);
  // The marathon starts at rounds[0], count it.
  ++cnt[rounds[0]];
  int cur = rounds[0];
  for (std::size_t i = 1; i < rounds.size(); ++i) {
    // Move step by step from cur to rounds[i] (exclusive).
    int target = rounds[i];
    while (cur != target) {
      cur = cur == n ? 1 : cur + 1;
      ++cnt[cur];
    }
    // cur is now equal to target; it remains as the start of next round.
  }

  int best = 0;
  for (int s = 1; s <= n; ++s) {
    best = std::max(best, cnt[s]);
  }

  std::vector<int> result;
  for (int s = 1; s <= n; ++s) {
    if (cnt[s] == best) {
      result.push_back(s);
    }
  }
  return result;
}

}  // namespace

MostVisitedSectorInACircularTrackSolution::
    MostVisitedSectorInACircularTrackSolution() {
  setMetaInfo({.id = 1560,
               .title = "Most Visited Sector in  a Circular Track",
               .url = "https://leetcode.com/problems/most-visited-sector-in-a-circular-track/"});

  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n*m)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Simulation"}},
      mostVisitedImpl);
}

std::vector<int> MostVisitedSectorInACircularTrackSolution::mostVisited(
    int n, std::vector<int>& rounds) {
  return getSolution()(n, rounds);
}

}  // namespace leetcode::problem_1560
