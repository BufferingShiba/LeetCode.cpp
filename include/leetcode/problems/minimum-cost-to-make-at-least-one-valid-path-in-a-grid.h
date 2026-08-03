#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_AT_LEAST_ONE_VALID_PATH_IN_A_GRID_H__
#define LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_AT_LEAST_ONE_VALID_PATH_IN_A_GRID_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1368 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MinimumCostToMakeAtLeastOneValidPathInAGridSolution
    : public SolutionBase<Func> {
 public:
  MinimumCostToMakeAtLeastOneValidPathInAGridSolution();

  int minCost(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_1368
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_AT_LEAST_ONE_VALID_PATH_IN_A_GRID_H__
