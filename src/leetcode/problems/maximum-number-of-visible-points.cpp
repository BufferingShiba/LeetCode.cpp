#include "leetcode/problems/maximum-number-of-visible-points.h"

#include <algorithm>
#include <cmath>
#include <vector>

namespace leetcode {
namespace problem_1610 {

int MaximumNumberOfVisiblePointsSolution::visiblePointsImpl(
    std::vector<std::vector<int>>& points, int angle, std::vector<int>& location) {
  const double PI = std::acos(-1.0);
  double ang = static_cast<double>(angle);
  int sameLocation = 0;
  std::vector<double> angles;
  angles.reserve(points.size());

  int ox = location[0];
  int oy = location[1];
  for (const auto& p : points) {
    int dx = p[0] - ox;
    int dy = p[1] - oy;
    if (dx == 0 && dy == 0) {
      ++sameLocation;
      continue;
    }
    double deg = std::atan2(static_cast<double>(dy), static_cast<double>(dx)) * 180.0 / PI;
    if (deg < 0) deg += 360.0;
    angles.push_back(deg);
  }

  std::sort(angles.begin(), angles.end());

  int n = angles.size();
  std::vector<double> doubled(n * 2);
  for (int i = 0; i < n; ++i) {
    doubled[i] = angles[i];
    doubled[i + n] = angles[i] + 360.0;
  }

  int best = 0;
  int right = 0;
  for (int left = 0; left < n; ++left) {
    while (right < n * 2 && doubled[right] - doubled[left] <= ang) {
      ++right;
    }
    best = std::max(best, right - left);
  }

  return sameLocation + best;
}

}  // namespace problem_1610
}  // namespace leetcode
