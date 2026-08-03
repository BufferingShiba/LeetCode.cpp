#ifndef LEETCODE_PROBLEMS_SUM_OF_SUBARRAY_MINIMUMS_H__
#define LEETCODE_PROBLEMS_SUM_OF_SUBARRAY_MINIMUMS_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_907 {

using Func = std::function<int(std::vector<int>&)>;

class SumOfSubarrayMinimumsSolution
    : public SolutionBase<Func> {
 public:
  SumOfSubarrayMinimumsSolution();

  int sumSubarrayMins(std::vector<int>& arr);
};

}  // namespace leetcode::problem_907

#endif  // LEETCODE_PROBLEMS_SUM_OF_SUBARRAY_MINIMUMS_H__
