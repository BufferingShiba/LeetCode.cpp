#ifndef LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_FACTOR_SCORE_OF_ARRAY_H__
#define LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_FACTOR_SCORE_OF_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_3334 {

using Func = std::function<long long(std::vector<int>&)>;

class FindTheMaximumFactorScoreOfArraySolution
    : public SolutionBase<Func> {
 public:
  FindTheMaximumFactorScoreOfArraySolution();
  long long maxScore(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3334

#endif  // LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_FACTOR_SCORE_OF_ARRAY_H__
