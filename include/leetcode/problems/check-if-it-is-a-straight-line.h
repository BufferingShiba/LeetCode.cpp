#ifndef LEETCODE_PROBLEMS_CHECK_IF_IT_IS_A_STRAIGHT_LINE_H__
#define LEETCODE_PROBLEMS_CHECK_IF_IT_IS_A_STRAIGHT_LINE_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1232 {

using Func = std::function<bool(std::vector<std::vector<int>>&)>;

class CheckIfItIsAStraightLineSolution
    : public SolutionBase<Func> {
 public:
  CheckIfItIsAStraightLineSolution();

  bool checkStraightLine(std::vector<std::vector<int>>& coordinates);
};

}  // namespace problem_1232
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_IT_IS_A_STRAIGHT_LINE_H__
