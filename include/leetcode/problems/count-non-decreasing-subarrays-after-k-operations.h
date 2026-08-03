#ifndef LEETCODE_PROBLEMS_COUNT_NON_DECREASING_SUBARRAYS_AFTER_K_OPERATIONS_H__
#define LEETCODE_PROBLEMS_COUNT_NON_DECREASING_SUBARRAYS_AFTER_K_OPERATIONS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3420 {

using Func = std::function<long long(std::vector<int>&, int)>;

class CountNonDecreasingSubarraysAfterKOperationsSolution
    : public SolutionBase<Func> {
 public:
  CountNonDecreasingSubarraysAfterKOperationsSolution();

  long long countNonDecreasingSubarrays(std::vector<int>& nums, int k) {
    return getSolution()(nums, k);
  }
};

}  // namespace problem_3420
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_NON_DECREASING_SUBARRAYS_AFTER_K_OPERATIONS_H__
