#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_TRANSFORM_ARRAY_H_
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_TRANSFORM_ARRAY_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3724 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&)>;

class MinimumOperationsToTransformArraySolution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToTransformArraySolution();

  long long minOperations(std::vector<int>& nums1, std::vector<int>& nums2);
};

}  // namespace problem_3724
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_TRANSFORM_ARRAY_H_
