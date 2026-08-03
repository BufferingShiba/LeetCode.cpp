#include "leetcode/problems/count-lattice-points-inside-a-circle.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode::problem_2249 {

static int countLatticePointsImpl(std::vector<std::vector<int>>& circles) {
  if (circles.empty()) return 0;

  int x_min = INT_MAX, x_max = INT_MIN;
  int y_min = INT_MAX, y_max = INT_MIN;

  for (const auto& c : circles) {
    int cx = c[0], cy = c[1], r = c[2];
    x_min = std::min(x_min, cx - r);
    x_max = std::max(x_max, cx + r);
    y_min = std::min(y_min, cy - r);
    y_max = std::max(y_max, cy + r);
  }

  int count = 0;
  for (int x = x_min; x <= x_max; ++x) {
    for (int y = y_min; y <= y_max; ++y) {
      for (const auto& c : circles) {
        int dx = x - c[0];
        int dy = y - c[1];
        if (dx * dx + dy * dy <= c[2] * c[2]) {
          ++count;
          break;
        }
      }
    }
  }
  return count;
}

CountLatticePointsInsideACircleSolution::CountLatticePointsInsideACircleSolution() {
  setMetaInfo({.id = 2249,
               .title = "Count Lattice Points Inside a Circle",
               .url = "https://leetcode.com/problems/count-lattice-points-inside-a-circle/"});
  registerStrategy(
      {.name = "BruteForce",
       .expected = "Accepted",
       .time_complexity = "O(N * R^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "Math", "Geometry", "Enumeration"}},
      countLatticePointsImpl);
  setDefaultStrategy();
}

int CountLatticePointsInsideACircleSolution::countLatticePoints(
    std::vector<std::vector<int>>& circles) {
  return getSolution()(circles);
}

}  // namespace leetcode::problem_2249
