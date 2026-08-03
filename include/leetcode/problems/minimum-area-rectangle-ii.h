#ifndef LEETCODE_PROBLEMS_MINIMUM_AREA_RECTANGLE_II_H__
#define LEETCODE_PROBLEMS_MINIMUM_AREA_RECTANGLE_II_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_963 {

using Func = std::function<double(std::vector<std::vector<int>>&)>;

class MinimumAreaRectangleIiSolution
    : public SolutionBase<Func> {
 public:
  MinimumAreaRectangleIiSolution();

  double minAreaFreeRect(std::vector<std::vector<int>>& points) {
    return getSolution()(points);
  }
};

}  // namespace leetcode::problem_963

#endif  // LEETCODE_PROBLEMS_MINIMUM_AREA_RECTANGLE_II_H__
