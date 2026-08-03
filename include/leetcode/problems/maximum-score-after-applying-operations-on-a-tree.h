#ifndef LEETCODE_PROBLEMS_MAXIMUM_SCORE_AFTER_APPLYING_OPERATIONS_ON_A_TREE_H_
#define LEETCODE_PROBLEMS_MAXIMUM_SCORE_AFTER_APPLYING_OPERATIONS_ON_A_TREE_H_

#include "leetcode/core.h"

namespace leetcode::problem_2925 {

using Func = std::function<long long(std::vector<std::vector<int>>&, std::vector<int>&)>;

class MaximumScoreAfterApplyingOperationsOnATreeSolution : public SolutionBase<Func> {
 public:
  MaximumScoreAfterApplyingOperationsOnATreeSolution();

  long long maximumScoreAfterOperations(std::vector<std::vector<int>>& edges,
                                         std::vector<int>& values) {
    return getSolution()(edges, values);
  }
};

}  // namespace leetcode::problem_2925

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SCORE_AFTER_APPLYING_OPERATIONS_ON_A_TREE_H_
