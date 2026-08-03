#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_OPERATIONS_TO_MOVE_ONES_TO_THE_END_H_
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_OPERATIONS_TO_MOVE_ONES_TO_THE_END_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3228 {

using Func = std::function<int(std::string)>;

class MaximumNumberOfOperationsToMoveOnesToTheEndSolution
    : public SolutionBase<Func> {
 public:
  int maxOperations(const std::string& s);

  MaximumNumberOfOperationsToMoveOnesToTheEndSolution();
};

}  // namespace leetcode::problem_3228

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_OPERATIONS_TO_MOVE_ONES_TO_THE_END_H_
