#ifndef LEETCODE_PROBLEMS_1186_MAXIMUM_SUBARRAY_SUM_WITH_ONE_DELETION_H_
#define LEETCODE_PROBLEMS_1186_MAXIMUM_SUBARRAY_SUM_WITH_ONE_DELETION_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1186 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumSubarraySumWithOneDeletionSolution
    : public SolutionBase<Func> {
 public:
  MaximumSubarraySumWithOneDeletionSolution();

  int maximumSum(std::vector<int>& arr);
};

}  // namespace problem_1186
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_1186_MAXIMUM_SUBARRAY_SUM_WITH_ONE_DELETION_H_
