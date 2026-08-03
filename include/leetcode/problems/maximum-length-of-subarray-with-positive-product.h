#ifndef LEETCODE_PROBLEMS_MAXIMUM_LENGTH_OF_SUBARRAY_WITH_POSITIVE_PRODUCT_H__
#define LEETCODE_PROBLEMS_MAXIMUM_LENGTH_OF_SUBARRAY_WITH_POSITIVE_PRODUCT_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_1567 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumLengthOfSubarrayWithPositiveProductSolution
    : public SolutionBase<Func> {
 public:
  MaximumLengthOfSubarrayWithPositiveProductSolution();

  int getMaxLen(std::vector<int>& nums);
};

}  // namespace leetcode::problem_1567

#endif  // LEETCODE_PROBLEMS_MAXIMUM_LENGTH_OF_SUBARRAY_WITH_POSITIVE_PRODUCT_H__
