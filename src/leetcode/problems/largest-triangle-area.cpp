#include "leetcode/problems/largest-triangle-area.h"

#include <algorithm>
#include <cmath>
#include <vector>

namespace leetcode {
namespace problem_812 {
namespace {

// Shoelace formula: area of triangle with vertices (x1,y1),(x2,y2),(x3,y3).
double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
  return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

double largestTriangleAreaImpl(std::vector<std::vector<int>>& points) {
  const int n = static_cast<int>(points.size());
  double best = 0.0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        double area = triangleArea(points[i][0], points[i][1],
                                   points[j][0], points[j][1],
                                   points[k][0], points[k][1]);
        best = std::max(best, area);
      }
    }
  }
  return best;
}

}  // namespace

LargestTriangleAreaSolution::LargestTriangleAreaSolution() {
  setMetaInfo({.id = 812,
               .title = "Largest Triangle Area",
               .url = "https://leetcode.com/problems/largest-triangle-area/"});
  registerStrategy(
      {.name = "brute_force",
       .expected = "Accepted",
       .time_complexity = "O(n^3)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Geometry"}},
      largestTriangleAreaImpl);
}

// Re-exported public method that forwards to the registered strategy.
double LargestTriangleAreaSolution::largestTriangleArea(
    std::vector<std::vector<int>>& points) {
  return getSolution()(points);
}

}  // namespace problem_812
}  // namespace leetcode
