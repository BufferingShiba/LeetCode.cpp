#ifndef LEETCODE_PROBLEMS_CHECK_IF_THE_RECTANGLE_CORNER_IS_REACHABLE_H_
#define LEETCODE_PROBLEMS_CHECK_IF_THE_RECTANGLE_CORNER_IS_REACHABLE_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3235 {

using Func = std::function<bool(int, int, std::vector<std::vector<int>>&)>;

class CheckIfTheRectangleCornerIsReachableSolution : public SolutionBase<Func> {
 public:
  CheckIfTheRectangleCornerIsReachableSolution();

  bool canReachCorner(int xCorner, int yCorner,
                      std::vector<std::vector<int>>& circles);
};

}  // namespace problem_3235
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_THE_RECTANGLE_CORNER_IS_REACHABLE_H_
