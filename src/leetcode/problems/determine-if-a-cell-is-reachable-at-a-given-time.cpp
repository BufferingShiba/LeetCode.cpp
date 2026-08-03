#include "leetcode/problems/determine-if-a-cell-is-reachable-at-a-given-time.h"

#include <cstdlib>

namespace leetcode {
namespace problem_2849 {

static bool solution1(int sx, int sy, int fx, int fy, int t) {
  if (sx == fx && sy == fy) {
    // Already at target: t == 0 works (stay), t >= 2 works (leave and come back),
    // but t == 1 is impossible because we must move to an adjacent cell.
    return t != 1;
  }
  // Minimum time to move between distinct cells with 8-direction moves is
  // the Chebyshev distance. We can always reach exactly at any t >= that minimum
  // by wasting extra moves with back-and-forth detours.
  int minTime = std::max(std::abs(sx - fx), std::abs(sy - fy));
  return t >= minTime;
}

DetermineIfACellIsReachableAtAGivenTimeSolution::DetermineIfACellIsReachableAtAGivenTimeSolution() {
  setMetaInfo({
      .id = 2849,
      .title = "Determine if a Cell Is Reachable at a Given Time",
      .url = "https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time"
  });
  registerStrategy({.name = "Chebyshev Distance",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math"}},
                   solution1);
}

bool DetermineIfACellIsReachableAtAGivenTimeSolution::isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
  return getSolution()(sx, sy, fx, fy, t);
}

}  // namespace problem_2849
}  // namespace leetcode
