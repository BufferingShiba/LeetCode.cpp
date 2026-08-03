#ifndef LEETCODE_PROBLEMS_MINIMUM_SUBARRAY_LENGTH_WITH_DISTINCT_SUM_AT_LEAST_K_H_
#define LEETCODE_PROBLEMS_MINIMUM_SUBARRAY_LENGTH_WITH_DISTINCT_SUM_AT_LEAST_K_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3795 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumSubarrayLengthWithDistinctSumAtLeastKSolution : public SolutionBase<Func> {
 public:
  MinimumSubarrayLengthWithDistinctSumAtLeastKSolution();
  int minLength(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3795

#endif  // LEETCODE_PROBLEMS_MINIMUM_SUBARRAY_LENGTH_WITH_DISTINCT_SUM_AT_LEAST_K_H_
