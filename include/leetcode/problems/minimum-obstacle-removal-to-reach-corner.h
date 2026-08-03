#ifndef LEETCODE_PROBLEMS_MINIMUM_OBSTACLE_REMOVAL_TO_REACH_CORNER_H__
#define LEETCODE_PROBLEMS_MINIMUM_OBSTACLE_REMOVAL_TO_REACH_CORNER_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2290 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MinimumObstacleRemovalToReachCornerSolution
    : public SolutionBase<Func> {
 public:
  MinimumObstacleRemovalToReachCornerSolution();

  int minimumObstacles(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_2290

#endif  // LEETCODE_PROBLEMS_MINIMUM_OBSTACLE_REMOVAL_TO_REACH_CORNER_H__
