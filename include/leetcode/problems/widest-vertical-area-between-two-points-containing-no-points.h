#ifndef LEETCODE_PROBLEMS_WIDEST_VERTICAL_AREA_BETWEEN_TWO_POINTS_CONTAINING_NO_POINTS_H__
#define LEETCODE_PROBLEMS_WIDEST_VERTICAL_AREA_BETWEEN_TWO_POINTS_CONTAINING_NO_POINTS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1637 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class WidestVerticalAreaBetweenTwoPointsContainingNoPointsSolution
    : public SolutionBase<Func> {
 public:
  int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points);

  WidestVerticalAreaBetweenTwoPointsContainingNoPointsSolution();
};

}  // namespace leetcode::problem_1637

#endif  // LEETCODE_PROBLEMS_WIDEST_VERTICAL_AREA_BETWEEN_TWO_POINTS_CONTAINING_NO_POINTS_H__
