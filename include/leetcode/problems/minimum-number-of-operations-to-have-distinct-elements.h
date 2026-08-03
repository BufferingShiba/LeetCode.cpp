#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_HAVE_DISTINCT_ELEMENTS_H_
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_HAVE_DISTINCT_ELEMENTS_H_

#include "leetcode/core.h"

namespace leetcode::problem_3779 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumNumberOfOperationsToHaveDistinctElementsSolution
    : public SolutionBase<Func> {
 public:
  int minOperations(std::vector<int>& nums);

  MinimumNumberOfOperationsToHaveDistinctElementsSolution();
};

}  // namespace leetcode::problem_3779

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_HAVE_DISTINCT_ELEMENTS_H_
