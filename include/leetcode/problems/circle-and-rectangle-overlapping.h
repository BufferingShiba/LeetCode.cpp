#ifndef LEETCODE_PROBLEMS_CIRCLE_AND_RECTANGLE_OVERLAPPING_H__
#define LEETCODE_PROBLEMS_CIRCLE_AND_RECTANGLE_OVERLAPPING_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_1401 {

using Func = std::function<bool(int, int, int, int, int, int, int)>;

class CircleAndRectangleOverlappingSolution : public SolutionBase<Func> {
public:
    CircleAndRectangleOverlappingSolution();

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2);
};

}  // namespace leetcode::problem_1401

#endif  // LEETCODE_PROBLEMS_CIRCLE_AND_RECTANGLE_OVERLAPPING_H__
