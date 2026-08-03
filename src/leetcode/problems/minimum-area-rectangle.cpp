#include "leetcode/problems/minimum-area-rectangle.h"

#include <algorithm>
#include <cstdint>
#include <limits>
#include <unordered_map>

namespace leetcode {
namespace problem_939 {
namespace {

constexpr int kInf = std::numeric_limits<int>::max();

// std::hash support for a pair of ints.
struct PairHash {
  std::size_t operator()(const std::pair<int, int>& p) const {
    return static_cast<std::size_t>(p.first) * 1315423911u +
           static_cast<std::size_t>(p.second);
  }
};

// Group points by row (y), then for each pair of x-columns shared by two
// consecutive rows compute a candidate rectangle. Uses a hash table storing the
// most recent row in which a given (x1, x2) column-pair was seen.
int minAreaRectImpl(std::vector<std::vector<int>>& points) {
  // Group x values by their y coordinate.
  std::unordered_map<int, std::vector<int>> rows;
  int min_y = kInf;
  int max_y = -kInf;
  for (const auto& p : points) {
    const int x = p[0];
    const int y = p[1];
    rows[y].push_back(x);
    min_y = std::min(min_y, y);
    max_y = std::max(max_y, y);
  }

  // Sort x lists ascending and collect distinct y values ascending.
  std::vector<int> ys;
  ys.reserve(rows.size());
  for (auto& kv : rows) {
    auto& xs = kv.second;
    std::sort(xs.begin(), xs.end());
    ys.push_back(kv.first);
  }
  std::sort(ys.begin(), ys.end());

  // For each distinct column-pair, track the largest (most recent) y at which
  // both columns were present. Encode (x1, x2) with x1 < x2.
  std::unordered_map<std::pair<int, int>, int, PairHash> last_seen;
  int best = kInf;

  for (const int y : ys) {
    const auto& xs = rows[y];
    const int m = static_cast<int>(xs.size());

    // First, use existing records to form rectangles with this row.
    for (int i = 0; i < m; ++i) {
      const int x1 = xs[i];
      for (int j = i + 1; j < m; ++j) {
        const int x2 = xs[j];
        auto it = last_seen.find({x1, x2});
        if (it != last_seen.end()) {
          const int prev_y = it->second;
          const int area = (x2 - x1) * (y - prev_y);
          if (area < best) best = area;
        }
      }
    }

    // Then publish this row's column-pairs (keep the current row as most
    // recent) so the next row can form rectangles.
    for (int i = 0; i < m; ++i) {
      const int x1 = xs[i];
      for (int j = i + 1; j < m; ++j) {
        const int x2 = xs[j];
        last_seen[{x1, x2}] = y;
      }
    }
  }

  return best == kInf ? 0 : best;
}

}  // namespace

MinimumAreaRectangleSolution::MinimumAreaRectangleSolution() {
  setMetaInfo({.id = 939,
               .title = "Minimum Area Rectangle",
               .url = "https://leetcode.com/problems/minimum-area-rectangle/"});

  registerStrategy(
      {.name = "column-pair-hash",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"Array", "Hash Table", "Sorting"},
       .notes = "Group points by y; track most-recent row for each x-column pair"},
      minAreaRectImpl);
}

int MinimumAreaRectangleSolution::minAreaRect(
    std::vector<std::vector<int>>& points) {
  return getSolution()(points);
}

}  // namespace problem_939
}  // namespace leetcode
