#include "leetcode/problems/widest-vertical-area-between-two-points-containing-no-points.h"

#include <algorithm>

namespace leetcode::problem_1637 {

namespace {

int maxWidthOfVerticalAreaImpl(std::vector<std::vector<int>>& points) {
  std::vector<int> xs;
  xs.reserve(points.size());
  for (const auto& p : points) {
    xs.push_back(p[0]);
  }
  std::sort(xs.begin(), xs.end());

  int width = 0;
  for (std::size_t i = 1; i < xs.size(); ++i) {
    width = std::max(width, xs[i] - xs[i - 1]);
  }
  return width;
}

}  // namespace

WidestVerticalAreaBetweenTwoPointsContainingNoPointsSolution::
    WidestVerticalAreaBetweenTwoPointsContainingNoPointsSolution() {
  setMetaInfo({.id = 1637,
               .title = "Widest Vertical Area Between Two Points Containing "
                        "No Points",
               .url = "https://leetcode.com/problems/"
                      "widest-vertical-area-between-two-points-containing-"
                      "no-points/"});

  registerStrategy(
      {.name = "sort-and-diff",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Sorting"}},
      static_cast<Func>(maxWidthOfVerticalAreaImpl));
}

int WidestVerticalAreaBetweenTwoPointsContainingNoPointsSolution::
    maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
  return getSolution()(points);
}

}  // namespace leetcode::problem_1637
