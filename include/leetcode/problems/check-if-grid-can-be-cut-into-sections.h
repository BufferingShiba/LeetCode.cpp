#ifndef LEETCODE_PROBLEMS_CHECK_IF_GRID_CAN_BE_CUT_INTO_SECTIONS_H__
#define LEETCODE_PROBLEMS_CHECK_IF_GRID_CAN_BE_CUT_INTO_SECTIONS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3394 {

using Func = std::function<bool(int, std::vector<std::vector<int>>&)>;

class CheckIfGridCanBeCutIntoSectionsSolution
    : public SolutionBase<Func> {
 public:
  CheckIfGridCanBeCutIntoSectionsSolution();

  bool checkValidCuts(int n, std::vector<std::vector<int>>& rectangles);
};

}  // namespace problem_3394
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_GRID_CAN_BE_CUT_INTO_SECTIONS_H__
