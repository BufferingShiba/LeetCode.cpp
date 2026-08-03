#ifndef LEETCODE_PROBLEMS_MAXIMUM_UNIQUE_SUBARRAY_SUM_AFTER_DELETION_H__
#define LEETCODE_PROBLEMS_MAXIMUM_UNIQUE_SUBARRAY_SUM_AFTER_DELETION_H__

#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3487 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumUniqueSubarraySumAfterDeletionSolution
    : public SolutionBase<Func> {
 public:
  MaximumUniqueSubarraySumAfterDeletionSolution();

  int maxSum(std::vector<int>& nums);
};

}  // namespace problem_3487
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_UNIQUE_SUBARRAY_SUM_AFTER_DELETION_H__
