#ifndef LEETCODE_PROBLEMS_MINIMUM_XOR_PATH_IN_A_GRID_H__
#define LEETCODE_PROBLEMS_MINIMUM_XOR_PATH_IN_A_GRID_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_3882 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MinimumXorPathInAGridSolution : public SolutionBase<Func> {
 public:
  MinimumXorPathInAGridSolution();

  int minCost(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_3882

#endif  // LEETCODE_PROBLEMS_MINIMUM_XOR_PATH_IN_A_GRID_H__
