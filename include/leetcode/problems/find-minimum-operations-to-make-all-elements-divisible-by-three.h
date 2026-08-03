#ifndef LEETCODE_PROBLEMS_FIND_MINIMUM_OPERATIONS_TO_MAKE_ALL_ELEMENTS_DIVISIBLE_BY_THREE_H_
#define LEETCODE_PROBLEMS_FIND_MINIMUM_OPERATIONS_TO_MAKE_ALL_ELEMENTS_DIVISIBLE_BY_THREE_H_

#include "leetcode/core.h"

namespace leetcode::problem_3190 {

using Func = std::function<int(std::vector<int>&)>;

class FindMinimumOperationsToMakeAllElementsDivisibleByThreeSolution
    : public SolutionBase<Func> {
 public:
  int minimumOperations(std::vector<int>& nums);

  FindMinimumOperationsToMakeAllElementsDivisibleByThreeSolution();
};

}  // namespace leetcode::problem_3190

#endif  // LEETCODE_PROBLEMS_FIND_MINIMUM_OPERATIONS_TO_MAKE_ALL_ELEMENTS_DIVISIBLE_BY_THREE_H_
