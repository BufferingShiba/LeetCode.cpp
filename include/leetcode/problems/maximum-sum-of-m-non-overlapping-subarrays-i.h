#ifndef LEETCODE_PROBLEMS_MAXIMUM_SUM_OF_M_NON_OVERLAPPING_SUBARRAYS_I_H
#define LEETCODE_PROBLEMS_MAXIMUM_SUM_OF_M_NON_OVERLAPPING_SUBARRAYS_I_H

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3956 {

using Func = std::function<long long(std::vector<int>&, int, int, int)>;

class MaximumSumOfMNonOverlappingSubarraysISolution
    : public SolutionBase<Func> {
 public:
  MaximumSumOfMNonOverlappingSubarraysISolution();

  long long maximumSum(std::vector<int>& nums, int m, int l, int r);
};

}  // namespace problem_3956
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SUM_OF_M_NON_OVERLAPPING_SUBARRAYS_I_H
