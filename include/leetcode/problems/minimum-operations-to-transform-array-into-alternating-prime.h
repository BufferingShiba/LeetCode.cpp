#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_TRANSFORM_ARRAY_INTO_ALTERNATING_PRIME_H_
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_TRANSFORM_ARRAY_INTO_ALTERNATING_PRIME_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3896 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumOperationsToTransformArrayIntoAlternatingPrimeSolution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToTransformArrayIntoAlternatingPrimeSolution();

  int minOperations(std::vector<int>& nums);
};

}  // namespace problem_3896
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_TRANSFORM_ARRAY_INTO_ALTERNATING_PRIME_H_
