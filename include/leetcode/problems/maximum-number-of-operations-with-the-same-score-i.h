#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_OPERATIONS_WITH_THE_SAME_SCORE_I_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_OPERATIONS_WITH_THE_SAME_SCORE_I_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3038 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumNumberOfOperationsWithTheSameScoreISolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfOperationsWithTheSameScoreISolution();

  int maxOperations(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3038

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_OPERATIONS_WITH_THE_SAME_SCORE_I_H__
