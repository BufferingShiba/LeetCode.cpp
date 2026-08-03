#include "leetcode/problems/circle-and-rectangle-overlapping.h"

namespace leetcode::problem_1401 {

// Find the closest point on/inside the axis-aligned rectangle to the circle
// center. Because the rectangle is axis-aligned and convex, x and y can be
// independently clamped to [x1,x2] and [y1,y2] respectively. If the distance
// from the circle center to that closest point is <= radius, then the circle
// and rectangle overlap (the closest point itself, or a boundary point, lies
// inside the circle).
static bool checkOverlapImpl(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    long long dx = 0, dy = 0;
    long long cx = static_cast<long long>(xCenter);
    long long cy = static_cast<long long>(yCenter);

    long long closestX = (cx < x1) ? x1 : (cx > x2 ? x2 : cx);
    long long closestY = (cy < y1) ? y1 : (cy > y2 ? y2 : cy);

    dx = cx - closestX;
    dy = cy - closestY;
    long long r = static_cast<long long>(radius);
    return dx * dx + dy * dy <= r * r;
}

CircleAndRectangleOverlappingSolution::CircleAndRectangleOverlappingSolution() {
    setMetaInfo({.id = 1401,
                 .title = "Circle and Rectangle Overlapping",
                 .url = "https://leetcode.com/problems/circle-and-rectangle-overlapping/"});
    registerStrategy({.name = "closest-point-clamp",
                      .expected = "Accepted",
                      .time_complexity = "O(1)",
                      .space_complexity = "O(1)",
                      .tags = {"Math", "Geometry"}},
                     checkOverlapImpl);
}

bool CircleAndRectangleOverlappingSolution::checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    return getSolution()(radius, xCenter, yCenter, x1, y1, x2, y2);
}

}  // namespace leetcode::problem_1401
