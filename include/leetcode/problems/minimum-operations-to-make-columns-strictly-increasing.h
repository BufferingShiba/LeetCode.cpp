#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_COLUMNS_STRICTLY_INCREASING_H__
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_COLUMNS_STRICTLY_INCREASING_H__

#include "leetcode/core.h"

namespace leetcode::problem_3402 {

class MinimumOperationsToMakeColumnsStrictlyIncreasingSolution
    : public SolutionBase<std::function<int(std::vector<std::vector<int>>&)>> {
 public:
  int minimumOperations(std::vector<std::vector<int>>& grid);

  MinimumOperationsToMakeColumnsStrictlyIncreasingSolution();
};

}  // namespace leetcode::problem_3402

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_COLUMNS_STRICTLY_INCREASING_H__
