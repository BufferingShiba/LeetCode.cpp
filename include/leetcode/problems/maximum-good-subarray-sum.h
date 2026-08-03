#ifndef LEETCODE_PROBLEMS_MAXIMUM_GOOD_SUBARRAY_SUM_H_
#define LEETCODE_PROBLEMS_MAXIMUM_GOOD_SUBARRAY_SUM_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3026 {

using Func = std::function<long long(std::vector<int>&, int)>;

class MaximumGoodSubarraySumSolution : public SolutionBase<Func> {
 public:
  long long maximumSubarraySum(std::vector<int>& nums, int k);

  MaximumGoodSubarraySumSolution();
};

}  // namespace leetcode::problem_3026

#endif  // LEETCODE_PROBLEMS_MAXIMUM_GOOD_SUBARRAY_SUM_H_
