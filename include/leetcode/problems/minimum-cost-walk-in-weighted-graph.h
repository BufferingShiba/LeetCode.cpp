#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_WALK_IN_WEIGHTED_GRAPH_H_
#define LEETCODE_PROBLEMS_MINIMUM_COST_WALK_IN_WEIGHTED_GRAPH_H_

#include "leetcode/core.h"

namespace leetcode::problem_3108 {

using Func = std::function<std::vector<int>(int, std::vector<std::vector<int>>&,
                                            std::vector<std::vector<int>>&)>;

class MinimumCostWalkInWeightedGraphSolution : public SolutionBase<Func> {
 public:
  MinimumCostWalkInWeightedGraphSolution();

  std::vector<int> minimumCost(int n, std::vector<std::vector<int>>& edges,
                               std::vector<std::vector<int>>& query);
};

}  // namespace leetcode::problem_3108

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_WALK_IN_WEIGHTED_GRAPH_H_
