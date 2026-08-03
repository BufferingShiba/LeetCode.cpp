#ifndef LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_REACH_TARGET_SCORE_H__
#define LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_REACH_TARGET_SCORE_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_2139 {

using Func = std::function<int(int, int)>;

class MinimumMovesToReachTargetScoreSolution
    : public SolutionBase<Func> {
 public:
  int minMoves(int target, int maxDoubles);

  MinimumMovesToReachTargetScoreSolution();
};

}  // namespace leetcode::problem_2139

#endif  // LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_REACH_TARGET_SCORE_H__
