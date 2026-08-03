#ifndef LEETCODE_PROBLEMS_MAXIMUM_BALANCED_SUBSEQUENCE_SUM_H_
#define LEETCODE_PROBLEMS_MAXIMUM_BALANCED_SUBSEQUENCE_SUM_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2926 {

using Func = std::function<long long(std::vector<int>&)>;

class MaximumBalancedSubsequenceSumSolution
    : public SolutionBase<Func> {
 public:
  MaximumBalancedSubsequenceSumSolution();

  long long maxBalancedSubsequenceSum(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2926

#endif  // LEETCODE_PROBLEMS_MAXIMUM_BALANCED_SUBSEQUENCE_SUM_H_
