#ifndef LEETCODE_PROBLEMS_MAXIMUM_COUNT_OF_POSITIVE_INTEGER_AND_NEGATIVE_INTEGER_H_
#define LEETCODE_PROBLEMS_MAXIMUM_COUNT_OF_POSITIVE_INTEGER_AND_NEGATIVE_INTEGER_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2529 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumCountOfPositiveIntegerAndNegativeIntegerSolution
    : public SolutionBase<Func> {
 public:
  int maximumCount(std::vector<int>& nums);

  MaximumCountOfPositiveIntegerAndNegativeIntegerSolution();
};

}  // namespace leetcode::problem_2529

#endif  // LEETCODE_PROBLEMS_MAXIMUM_COUNT_OF_POSITIVE_INTEGER_AND_NEGATIVE_INTEGER_H_
