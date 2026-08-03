#ifndef LEETCODE_APPLY_OPERATIONS_ON_ARRAY_TO_MAXIMIZE_SUM_OF_SQUARES_H__
#define LEETCODE_APPLY_OPERATIONS_ON_ARRAY_TO_MAXIMIZE_SUM_OF_SQUARES_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_2897 {

using Func = std::function<int(std::vector<int>&, int)>;

class ApplyOperationsOnArrayToMaximizeSumOfSquaresSolution
    : public SolutionBase<Func> {
 public:
  ApplyOperationsOnArrayToMaximizeSumOfSquaresSolution();
  int maxSum(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_2897

#endif  // LEETCODE_APPLY_OPERATIONS_ON_ARRAY_TO_MAXIMIZE_SUM_OF_SQUARES_H__
