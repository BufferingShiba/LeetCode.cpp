#ifndef LEETCODE_PROBLEMS_MAXIMUM_AVERAGE_SUBARRAY_I_H__
#define LEETCODE_PROBLEMS_MAXIMUM_AVERAGE_SUBARRAY_I_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_643 {

using Func =
    std::function<double(std::vector<int>&, int)>;

class MaximumAverageSubarrayISolution : public SolutionBase<Func> {
 public:
  MaximumAverageSubarrayISolution();

  double findMaxAverage(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_643

#endif  // LEETCODE_PROBLEMS_MAXIMUM_AVERAGE_SUBARRAY_I_H__
