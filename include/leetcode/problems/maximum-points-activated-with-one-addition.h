#ifndef LEETCODE_PROBLEMS_MAXIMUM_POINTS_ACTIVATED_WITH_ONE_ADDITION_H__
#define LEETCODE_PROBLEMS_MAXIMUM_POINTS_ACTIVATED_WITH_ONE_ADDITION_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_3873 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MaximumPointsActivatedWithOneAdditionSolution
    : public SolutionBase<Func> {
 public:
  MaximumPointsActivatedWithOneAdditionSolution();

  int maxActivated(std::vector<std::vector<int>>& points);
};

}  // namespace leetcode::problem_3873

#endif  // LEETCODE_PROBLEMS_MAXIMUM_POINTS_ACTIVATED_WITH_ONE_ADDITION_H__
