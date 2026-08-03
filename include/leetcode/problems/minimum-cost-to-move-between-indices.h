#ifndef LEETCODE_PROBLEMS_3919_MINIMUM_COST_TO_MOVE_BETWEEN_INDICES_H_
#define LEETCODE_PROBLEMS_3919_MINIMUM_COST_TO_MOVE_BETWEEN_INDICES_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3919 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<std::vector<int>>&)>;

class MinimumCostToMoveBetweenIndicesSolution : public SolutionBase<Func> {
 public:
  std::vector<int> minCost(std::vector<int>& nums, std::vector<std::vector<int>>& queries);

  MinimumCostToMoveBetweenIndicesSolution();
};

}  // namespace leetcode::problem_3919

#endif  // LEETCODE_PROBLEMS_3919_MINIMUM_COST_TO_MOVE_BETWEEN_INDICES_H_
