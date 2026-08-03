#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_TO_MOVE_CHIPS_TO_THE_SAME_POSITION_H__
#define LEETCODE_PROBLEMS_MINIMUM_COST_TO_MOVE_CHIPS_TO_THE_SAME_POSITION_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1217 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumCostToMoveChipsToTheSamePositionSolution
    : public SolutionBase<Func> {
 public:
  int minCostToMoveChips(std::vector<int>& position);

  MinimumCostToMoveChipsToTheSamePositionSolution();
};

}  // namespace leetcode::problem_1217

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_TO_MOVE_CHIPS_TO_THE_SAME_POSITION_H__
