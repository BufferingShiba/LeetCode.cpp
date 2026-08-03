#ifndef LEETCODE_PROBLEMS_COUNT_LATTICE_POINTS_INSIDE_A_CIRCLE_H
#define LEETCODE_PROBLEMS_COUNT_LATTICE_POINTS_INSIDE_A_CIRCLE_H

#include "leetcode/core.h"

namespace leetcode::problem_2249 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class CountLatticePointsInsideACircleSolution : public SolutionBase<Func> {
 public:
  CountLatticePointsInsideACircleSolution();

  int countLatticePoints(std::vector<std::vector<int>>& circles);
};

}  // namespace leetcode::problem_2249

#endif
