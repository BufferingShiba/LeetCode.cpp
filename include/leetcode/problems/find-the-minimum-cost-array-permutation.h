#ifndef LEETCODE_PROBLEMS_FIND_THE_MINIMUM_COST_ARRAY_PERMUTATION_H_
#define LEETCODE_PROBLEMS_FIND_THE_MINIMUM_COST_ARRAY_PERMUTATION_H_

#include "leetcode/core.h"

namespace leetcode::problem_3149 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class FindTheMinimumCostArrayPermutationSolution : public SolutionBase<Func> {
 public:
  FindTheMinimumCostArrayPermutationSolution();
  std::vector<int> findPermutation(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3149

#endif  // LEETCODE_PROBLEMS_FIND_THE_MINIMUM_COST_ARRAY_PERMUTATION_H_
