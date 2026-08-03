#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_MEDIAN_OF_ARRAY_EQUAL_TO_K_H_
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_MEDIAN_OF_ARRAY_EQUAL_TO_K_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3107 {

using Func = std::function<long long(std::vector<int>&, int)>;

class MinimumOperationsToMakeMedianOfArrayEqualToKSolution : public SolutionBase<Func> {
 public:
  MinimumOperationsToMakeMedianOfArrayEqualToKSolution();

  long long minOperationsToMakeMedianK(std::vector<int>& nums, int k);
};

}  // namespace problem_3107
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_MEDIAN_OF_ARRAY_EQUAL_TO_K_H_
