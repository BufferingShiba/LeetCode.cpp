#ifndef LEETCODE_PROBLEMS_MAXIMUM_AREA_OF_A_PIECE_OF_CAKE_AFTER_HORIZONTAL_AND_VERTICAL_CUTS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_AREA_OF_A_PIECE_OF_CAKE_AFTER_HORIZONTAL_AND_VERTICAL_CUTS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_1465 {

using Func = std::function<int(int, int, std::vector<int>&, std::vector<int>&)>;

class MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsSolution
    : public SolutionBase<Func> {
 public:
  MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsSolution();

  int maxArea(int h, int w, std::vector<int>& horizontalCuts,
              std::vector<int>& verticalCuts);
};

}  // namespace leetcode::problem_1465

#endif
