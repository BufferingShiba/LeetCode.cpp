#include "leetcode/problems/reaching-points.h"

namespace leetcode {
namespace problem_780 {

namespace {

bool reachingPointsImpl(int sx, int sy, int tx, int ty) {
  while (tx >= sx && ty >= sy) {
    if (tx == sx && ty == sy) {
      return true;
    }
    if (tx > ty) {
      if (ty > sy) {
        tx %= ty;
      } else {
        // ty == sy, only reduce tx by ty
        return (tx - sx) % ty == 0;
      }
    } else {
      // ty >= tx
      if (tx > sx) {
        ty %= tx;
      } else {
        // tx == sx, only reduce ty by tx
        return (ty - sy) % tx == 0;
      }
    }
  }
  return false;
}

}  // namespace

ReachingPointsSolution::ReachingPointsSolution() {
  setMetaInfo({.id = 780,
               .title = "Reaching Points",
               .url = "https://leetcode.com/problems/reaching-points/"});
  registerStrategy(
      {.name = "ReverseModulo",
       .expected = "Accepted",
       .time_complexity = "O(log(max(tx,ty)))",
       .space_complexity = "O(1)",
       .tags = {"Math", "Backtracking"}},
      reachingPointsImpl);
}

bool ReachingPointsSolution::reachingPoints(int sx, int sy, int tx, int ty) {
  return getSolution()(sx, sy, tx, ty);
}

}  // namespace problem_780
}  // namespace leetcode
