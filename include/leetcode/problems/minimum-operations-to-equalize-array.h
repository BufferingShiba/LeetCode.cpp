#ifndef LEETCODE_MINIMUM_OPERATIONS_TO_EQUALIZE_ARRAY_H__
#define LEETCODE_MINIMUM_OPERATIONS_TO_EQUALIZE_ARRAY_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3674 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumOperationsToEqualizeArraySolution : public SolutionBase<Func> {
 public:
  MinimumOperationsToEqualizeArraySolution();

  int minOperations(std::vector<int>& nums);
};

}  // namespace problem_3674
}  // namespace leetcode

#endif  // LEETCODE_MINIMUM_OPERATIONS_TO_EQUALIZE_ARRAY_H__
