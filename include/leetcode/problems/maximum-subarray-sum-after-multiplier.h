#ifndef LEETCODE_PROBLEMS_MAXIMUM_SUBARRAY_SUM_AFTER_MULTIPLIER_H_
#define LEETCODE_PROBLEMS_MAXIMUM_SUBARRAY_SUM_AFTER_MULTIPLIER_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3976 {

using Func = std::function<long long(std::vector<int>&, int)>;

class MaximumSubarraySumAfterMultiplierSolution : public SolutionBase<Func> {
 public:
  MaximumSubarraySumAfterMultiplierSolution();

  long long maxSubarraySum(std::vector<int>& nums, int k);
};

}  // namespace problem_3976
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SUBARRAY_SUM_AFTER_MULTIPLIER_H_
