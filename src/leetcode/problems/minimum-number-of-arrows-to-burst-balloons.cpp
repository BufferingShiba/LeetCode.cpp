#include "leetcode/problems/minimum-number-of-arrows-to-burst-balloons.h"

#include <algorithm>

namespace leetcode {
namespace problem_452 {

// Greedy: sort balloons by their end coordinate, then shoot an arrow at the
// current interval's end whenever the current balloon doesn't overlap with the
// last arrow's position. Each arrow bursts all balloons whose start <= pos.
static int solution1(vector<vector<int>>& points) {
  std::sort(points.begin(), points.end(),
            [](const vector<int>& a, const vector<int>& b) {
              return a[1] < b[1];
            });
  int arrows = 0;
  long long pos = LLONG_MIN;  // last arrow position (use int64 to cover -2^31)
  for (const auto& p : points) {
    if (pos < p[0] || pos > p[1]) {
      ++arrows;
      pos = p[1];
    }
  }
  return arrows;
}

MinimumNumberOfArrowsToBurstBalloonsSolution::MinimumNumberOfArrowsToBurstBalloonsSolution() {
  setMetaInfo({
      .id = 452,
      .title = "Minimum Number of Arrows to Burst Balloons",
      .url = "https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons"
  });
  registerStrategy({.name = "Greedy Sort by End",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Greedy", "Sorting", "Interval"}},
                   solution1);
}

int MinimumNumberOfArrowsToBurstBalloonsSolution::findMinArrowShots(vector<vector<int>>& points) {
  return getSolution()(points);
}

}  // namespace problem_452
}  // namespace leetcode
