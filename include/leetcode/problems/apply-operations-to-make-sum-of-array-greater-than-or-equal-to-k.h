#ifndef LEETCODE_PROBLEMS_APPLY_OPERATIONS_TO_MAKE_SUM_OF_ARRAY_GREATER_THAN_OR_EQUAL_TO_K_H__
#define LEETCODE_PROBLEMS_APPLY_OPERATIONS_TO_MAKE_SUM_OF_ARRAY_GREATER_THAN_OR_EQUAL_TO_K_H__

#include "leetcode/core.h"

namespace leetcode::problem_3091 {

using Func = std::function<int(int)>;

class ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKSolution
    : public SolutionBase<Func> {
 public:
  ApplyOperationsToMakeSumOfArrayGreaterThanOrEqualToKSolution();

  int minOperations(int k);
};

}  // namespace leetcode::problem_3091

#endif  // LEETCODE_PROBLEMS_APPLY_OPERATIONS_TO_MAKE_SUM_OF_ARRAY_GREATER_THAN_OR_EQUAL_TO_K_H__
