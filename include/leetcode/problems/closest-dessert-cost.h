#ifndef LEETCODE_PROBLEMS_CLOSEST_DESSERT_COST_H_
#define LEETCODE_PROBLEMS_CLOSEST_DESSERT_COST_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1774 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&, int)>;

class ClosestDessertCostSolution : public SolutionBase<Func> {
 public:
  ClosestDessertCostSolution();

  int closestCost(std::vector<int>& baseCosts, std::vector<int>& toppingCosts,
                  int target);
};

}  // namespace problem_1774
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CLOSEST_DESSERT_COST_H_
