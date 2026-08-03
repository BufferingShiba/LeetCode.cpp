#include "leetcode/problems/rectangle-area.h"

#include <algorithm>

namespace leetcode::problem_223 {
namespace {

// Overlapping rectilinear region width/height are positive only if the
// intervals actually overlap on the corresponding axis.
int computeAreaImpl(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {
    int areaA = (ax2 - ax1) * (ay2 - ay1);
    int areaB = (bx2 - bx1) * (by2 - by1);

    int overlapW = std::min(ax2, bx2) - std::max(ax1, bx1);
    int overlapH = std::min(ay2, by2) - std::max(ay1, by1);
    int overlap = (overlapW > 0 && overlapH > 0) ? overlapW * overlapH : 0;

    return areaA + areaB - overlap;
}

}  // namespace

RectangleAreaSolution::RectangleAreaSolution() {
    setMetaInfo({.id = 223,
                 .title = "Rectangle Area",
                 .url = "https://leetcode.com/problems/rectangle-area/"});
    registerStrategy(
        {.name = "areaSumMinusOverlap",
         .expected = "Accepted",
         .time_complexity = "O(1)",
         .space_complexity = "O(1)",
         .tags = {"Math", "Geometry"}},
        computeAreaImpl);
}

}  // namespace leetcode::problem_223
