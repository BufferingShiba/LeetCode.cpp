#include "leetcode/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate.h"

#include <climits>

namespace leetcode {
namespace problem_1779 {

namespace {

int nearestValidPointImpl(int x, int y, std::vector<std::vector<int>>& points) {
  int minDist = INT_MAX;
  int result = -1;
  for (int i = 0; i < static_cast<int>(points.size()); ++i) {
    const int px = points[i][0];
    const int py = points[i][1];
    if (px != x && py != y) {
      continue;
    }
    const int dist = std::abs(x - px) + std::abs(y - py);
    if (dist < minDist) {
      minDist = dist;
      result = i;
    }
  }
  return result;
}

}  // namespace

int FindNearestPointThatHasTheSameXOrYCoordinateSolution::nearestValidPoint(
    int x, int y, std::vector<std::vector<int>>& points) {
  return getSolution()(x, y, points);
}

FindNearestPointThatHasTheSameXOrYCoordinateSolution::
    FindNearestPointThatHasTheSameXOrYCoordinateSolution() {
  setMetaInfo({.id = 1779,
               .title =
                   "Find Nearest Point That Has the Same X or Y Coordinate",
               .url = "https://leetcode.com/problems/"
                      "find-nearest-point-that-has-the-same-x-or-y-"
                      "coordinate/"});
  registerStrategy(
      {.name = "linear-scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      nearestValidPointImpl);
}

}  // namespace problem_1779
}  // namespace leetcode
