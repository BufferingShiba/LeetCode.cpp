#ifndef LEETCODE_PROBLEMS_RECTANGLE_AREA_H_
#define LEETCODE_PROBLEMS_RECTANGLE_AREA_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_223 {

using Func = std::function<int(int, int, int, int, int, int, int, int)>;

class RectangleAreaSolution : public SolutionBase<Func> {
public:
    RectangleAreaSolution();
};

}  // namespace leetcode::problem_223

#endif  // LEETCODE_PROBLEMS_RECTANGLE_AREA_H_
