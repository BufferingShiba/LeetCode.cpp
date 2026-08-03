#ifndef LEETCODE_PROBLEMS_BINARY_SUBARRAYS_WITH_SUM_H_
#define LEETCODE_PROBLEMS_BINARY_SUBARRAYS_WITH_SUM_H_

#include "leetcode/core.h"

namespace leetcode::problem_930 {

using Func = std::function<int(std::vector<int>&, int)>;

class BinarySubarraysWithSumSolution : public SolutionBase<Func> {
 public:
  BinarySubarraysWithSumSolution();

  int numSubarraysWithSum(std::vector<int>& nums, int goal);
};

}  // namespace leetcode::problem_930

#endif  // LEETCODE_PROBLEMS_BINARY_SUBARRAYS_WITH_SUM_H_
