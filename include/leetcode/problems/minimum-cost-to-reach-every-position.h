#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_TO_REACH_EVERY_POSITION_H__
#define LEETCODE_PROBLEMS_MINIMUM_COST_TO_REACH_EVERY_POSITION_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3502 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class MinimumCostToReachEveryPositionSolution
    : public SolutionBase<Func> {
 public:
  MinimumCostToReachEveryPositionSolution();

  std::vector<int> minCosts(std::vector<int>& cost);
};

}  // namespace leetcode::problem_3502

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_TO_REACH_EVERY_POSITION_H__
