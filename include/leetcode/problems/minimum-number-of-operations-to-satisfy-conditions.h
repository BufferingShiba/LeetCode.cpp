#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_SATISFY_CONDITIONS_H__
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_SATISFY_CONDITIONS_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_3122 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MinimumNumberOfOperationsToSatisfyConditionsSolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfOperationsToSatisfyConditionsSolution();

  int minimumOperations(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_3122

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_SATISFY_CONDITIONS_H__
