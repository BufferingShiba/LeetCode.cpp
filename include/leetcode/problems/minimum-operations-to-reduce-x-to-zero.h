#ifndef LEETCODE_PROBLEMS_1658_MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H_
#define LEETCODE_PROBLEMS_1658_MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1658 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumOperationsToReduceXToZeroSolution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToReduceXToZeroSolution();

  int minOperations(std::vector<int>& nums, int x);
};

}  // namespace leetcode::problem_1658

#endif  // LEETCODE_PROBLEMS_1658_MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H_
