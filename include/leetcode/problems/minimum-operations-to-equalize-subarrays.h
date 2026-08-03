#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_EQUALIZE_SUBARRAYS_H_
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_EQUALIZE_SUBARRAYS_H_

#include "leetcode/core.h"

namespace leetcode::problem_3762 {

using Func = std::function<std::vector<long long>(std::vector<int>&, int, std::vector<std::vector<int>>&)>;

class MinimumOperationsToEqualizeSubarraysSolution : public SolutionBase<Func> {
 public:
  MinimumOperationsToEqualizeSubarraysSolution();

  std::vector<long long> minOperations(std::vector<int>& nums, int k,
                                       std::vector<std::vector<int>>& queries);
};

}  // namespace leetcode::problem_3762

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_EQUALIZE_SUBARRAYS_H_
