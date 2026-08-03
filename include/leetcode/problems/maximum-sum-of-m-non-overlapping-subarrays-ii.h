#ifndef LEETCODE_PROBLEM_3957_H_
#define LEETCODE_PROBLEM_3957_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3957 {

using Func = std::function<long long(std::vector<int>&, int, int, int)>;

class MaximumSumOfMNonOverlappingSubarraysIiSolution : public SolutionBase<Func> {
 public:
  MaximumSumOfMNonOverlappingSubarraysIiSolution();

  long long maximumSum(std::vector<int>& nums, int m, int l, int r);
};

}  // namespace problem_3957
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3957_H_
