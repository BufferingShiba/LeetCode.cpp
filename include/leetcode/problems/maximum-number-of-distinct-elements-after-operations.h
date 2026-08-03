#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_DISTINCT_ELEMENTS_AFTER_OPERATIONS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_DISTINCT_ELEMENTS_AFTER_OPERATIONS_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_3397 {

using Func = std::function<int(std::vector<int>&, int)>;

class MaximumNumberOfDistinctElementsAfterOperationsSolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfDistinctElementsAfterOperationsSolution();

  int maxDistinctElements(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3397

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_DISTINCT_ELEMENTS_AFTER_OPERATIONS_H__
