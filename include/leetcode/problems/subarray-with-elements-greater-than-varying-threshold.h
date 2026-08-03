#ifndef LEETCODE_PROBLEMS_SUBARRAY_WITH_ELEMENTS_GREATER_THAN_VARYING_THRESHOLD_H_
#define LEETCODE_PROBLEMS_SUBARRAY_WITH_ELEMENTS_GREATER_THAN_VARYING_THRESHOLD_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2334 {

using Func = std::function<int(std::vector<int>&, int)>;

class SubarrayWithElementsGreaterThanVaryingThresholdSolution
    : public SolutionBase<Func> {
 public:
  SubarrayWithElementsGreaterThanVaryingThresholdSolution();

  int validSubarraySize(std::vector<int>& nums, int threshold);
};

}  // namespace problem_2334
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUBARRAY_WITH_ELEMENTS_GREATER_THAN_VARYING_THRESHOLD_H_
