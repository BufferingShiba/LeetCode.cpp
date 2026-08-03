#ifndef LEETCODE_PROBLEMS_MINIMIZE_MAXIMUM_COMPONENT_COST_H__
#define LEETCODE_PROBLEMS_MINIMIZE_MAXIMUM_COMPONENT_COST_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_3613 {

using Func = std::function<int(int, std::vector<std::vector<int>>&, int)>;

class MinimizeMaximumComponentCostSolution : public SolutionBase<Func> {
 public:
  int minCost(int n, std::vector<std::vector<int>>& edges, int k);
  MinimizeMaximumComponentCostSolution();
};

}  // namespace leetcode::problem_3613

#endif  // LEETCODE_PROBLEMS_MINIMIZE_MAXIMUM_COMPONENT_COST_H__
