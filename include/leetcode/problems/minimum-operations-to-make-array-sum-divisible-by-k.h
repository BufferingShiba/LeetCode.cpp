#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_SUM_DIVISIBLE_BY_K_H__
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_SUM_DIVISIBLE_BY_K_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3512 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumOperationsToMakeArraySumDivisibleByKSolution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToMakeArraySumDivisibleByKSolution();

  int minOperations(std::vector<int>& nums, int k);
};

}  // namespace problem_3512
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_SUM_DIVISIBLE_BY_K_H__
