#include "leetcode/problems/detect-squares.h"

namespace leetcode {
namespace problem_2013 {

DetectSquares::DetectSquares() {}

void DetectSquares::add(vector<int> point) {
  points[point[0]][point[1]]++;
}

int DetectSquares::count(vector<int> point) {
  int x = point[0];
  int y = point[1];
  int res = 0;

  // For each stored point (x2, y2) that could be the opposite corner
  // (the diagonal) of an axis-aligned square with the query point (x, y),
  // we require |x2 - x| == |y2 - y| and the difference nonzero.
  // The other two corners are then (x2, y) and (x, y2).
  for (const auto& pair : points) {
    int x2 = pair.first;
    if (x2 == x) continue;
    int d = abs(x2 - x);

    auto itX2 = points.find(x2);
    auto itX = points.find(x);
    if (itX2 == points.end() || itX == points.end()) continue;

    for (const auto& entry : pair.second) {
      int y2 = entry.first;
      int cntDiag = entry.second;
      if (abs(y2 - y) != d) continue;

      auto itY = itX2->second.find(y);     // count at (x2, y)
      auto itY2 = itX->second.find(y2);    // count at (x, y2)
      if (itY != itX2->second.end() && itY2 != itX->second.end()) {
        res += cntDiag * itY->second * itY2->second;
      }
    }
  }

  return res;
}

}  // namespace problem_2013
}  // namespace leetcode
