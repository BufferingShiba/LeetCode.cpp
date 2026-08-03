#ifndef LEETCODE_PROBLEMS_MAXIMUM_SCORE_FROM_GRID_OPERATIONS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_SCORE_FROM_GRID_OPERATIONS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3225 {

using Func = std::function<long long(std::vector<std::vector<int>>&)>;

class MaximumScoreFromGridOperationsSolution : public SolutionBase<Func> {
 public:
  MaximumScoreFromGridOperationsSolution();

  long long maximumScore(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_3225

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SCORE_FROM_GRID_OPERATIONS_H__
