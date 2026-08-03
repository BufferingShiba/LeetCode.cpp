#ifndef LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_REACH_TARGET_WITH_ROTATIONS_H_
#define LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_REACH_TARGET_WITH_ROTATIONS_H_

#include "leetcode/core.h"

namespace leetcode::problem_1210 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MinimumMovesToReachTargetWithRotationsSolution : public SolutionBase<Func> {
 public:
  MinimumMovesToReachTargetWithRotationsSolution();

  int minimumMoves(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_1210

#endif  // LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_REACH_TARGET_WITH_ROTATIONS_H_
