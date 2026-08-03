#include "leetcode/problems/minimum-area-rectangle-ii.h"

#include <cmath>
#include <unordered_map>
#include <utility>

namespace leetcode::problem_963 {
namespace {

// Stratagy: group point-pairs by (midpoint, diagonal length). Two equal-length
// diagonals sharing the same midpoint form a rectangle whose area is
// |cross(d1, d2)| / 2, where d1/d2 are the two diagonal direction vectors.
// A parallelogram with equal diagonals is a rectangle.
double minAreaFreeRectImpl(std::vector<std::vector<int>>& points) {
  const int n = static_cast<int>(points.size());
  double best = 0.0;
  bool hasRectangle = false;

  // Key: (m1, m2, norm2) where m is the doubled midpoint (integers to stay
  // exact) and norm2 is the squared diagonal length (also doubled int-safe).
  struct Key {
    long long m1, m2, len2;
    bool operator==(const Key&) const = default;
  };
  struct KeyHash {
    size_t operator()(const Key& k) const {
      return std::hash<long long>()(k.m1) ^
             (std::hash<long long>()(k.m2) << 1) ^
             (std::hash<long long>()(k.len2) << 2);
    }
  };

  // Store for each group the diagonal vectors of previously seen segments.
  std::unordered_map<Key, std::vector<std::pair<long long, long long>>,
                     KeyHash> groups;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      const long long x1 = points[i][0], y1 = points[i][1];
      const long long x2 = points[j][0], y2 = points[j][1];

      const long long m1 = x1 + x2;  // doubled midpoint x
      const long long m2 = y1 + y2;  // doubled midpoint y
      const long long dx = x2 - x1;
      const long long dy = y2 - y1;
      const long long len2 = dx * dx + dy * dy;  // squared length (exact)

      const Key key{m1, m2, len2};
      auto& vec = groups[key];

      for (const auto& [ex, ey] : vec) {
        const long long cross = dx * ey - dy * ex;
        if (cross == 0) continue;  // collinear diagonals, degenerate
        const double area = static_cast<double>(std::abs(cross)) / 2.0;
        if (!hasRectangle || area < best) {
          best = area;
          hasRectangle = true;
        }
      }
      vec.emplace_back(dx, dy);
    }
  }

  return best;
}

}  // namespace

MinimumAreaRectangleIiSolution::MinimumAreaRectangleIiSolution() {
  setMetaInfo({.id = 963,
               .title = "Minimum Area Rectangle II",
               .url = "https://leetcode.com/problems/minimum-area-rectangle-ii/"});
  registerStrategy(
      {.name = "diagonal-hash",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"Hash Table", "Math", "Geometry"}},
      static_cast<Func>(minAreaFreeRectImpl));
}

}  // namespace leetcode::problem_963
