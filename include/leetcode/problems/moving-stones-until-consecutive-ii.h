#ifndef LEETCODE_PROBLEMS_MOVING_STONES_UNTIL_CONSECUTIVE_II_H__
#define LEETCODE_PROBLEMS_MOVING_STONES_UNTIL_CONSECUTIVE_II_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1040 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class MovingStonesUntilConsecutiveIiSolution
    : public SolutionBase<Func> {
 public:
  MovingStonesUntilConsecutiveIiSolution();

  std::vector<int> numMovesStonesII(std::vector<int>& stones);
};

}  // namespace leetcode::problem_1040

#endif  // LEETCODE_PROBLEMS_MOVING_STONES_UNTIL_CONSECUTIVE_II_H__
