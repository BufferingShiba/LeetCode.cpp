#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_EXCEED_THRESHOLD_VALUE_II_H__
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_EXCEED_THRESHOLD_VALUE_II_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3066 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumOperationsToExceedThresholdValueIiSolution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToExceedThresholdValueIiSolution();

  int minOperations(std::vector<int>& nums, int k);
};

}  // namespace problem_3066
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_EXCEED_THRESHOLD_VALUE_II_H__
