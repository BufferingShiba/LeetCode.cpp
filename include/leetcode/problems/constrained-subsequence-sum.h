#ifndef LEETCODE_PROBLEMS_CONSTRAINED_SUBSEQUENCE_SUM_H_
#define LEETCODE_PROBLEMS_CONSTRAINED_SUBSEQUENCE_SUM_H_

#include "leetcode/core.h"

namespace leetcode::problem_1425 {

using Func = std::function<int(std::vector<int>&, int)>;

class ConstrainedSubsequenceSumSolution : public SolutionBase<Func> {
 public:
  ConstrainedSubsequenceSumSolution();

  int constrainedSubsetSum(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_1425

#endif  // LEETCODE_PROBLEMS_CONSTRAINED_SUBSEQUENCE_SUM_H_
