#ifndef LEETCODE_PROBLEMS_FIND_TWO_NON_OVERLAPPING_SUB_ARRAYS_EACH_WITH_TARGET_SUM_H
#define LEETCODE_PROBLEMS_FIND_TWO_NON_OVERLAPPING_SUB_ARRAYS_EACH_WITH_TARGET_SUM_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1477 {

using Func = std::function<int(std::vector<int>&, int)>;

class FindTwoNonOverlappingSubArraysEachWithTargetSumSolution : public SolutionBase<Func> {
 public:
  FindTwoNonOverlappingSubArraysEachWithTargetSumSolution();

  int minSumOfLengths(std::vector<int>& arr, int target);
};

}  // namespace problem_1477
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_TWO_NON_OVERLAPPING_SUB_ARRAYS_EACH_WITH_TARGET_SUM_H