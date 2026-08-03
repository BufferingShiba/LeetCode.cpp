#ifndef LEETCODE_PROBLEM_2304_H_
#define LEETCODE_PROBLEM_2304_H_

#include "leetcode/core.h"

namespace leetcode::problem_2304 {

using Func = std::function<int(std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

class MinimumPathCostInAGridSolution : public SolutionBase<Func> {
 public:
  MinimumPathCostInAGridSolution();

  int minPathCost(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& moveCost);
};

}  // namespace leetcode::problem_2304

#endif  // LEETCODE_PROBLEM_2304_H_
