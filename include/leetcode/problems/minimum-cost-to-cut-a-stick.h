#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_TO_CUT_A_STICK_H_
#define LEETCODE_PROBLEMS_MINIMUM_COST_TO_CUT_A_STICK_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1547 {

using Func = std::function<int(int, std::vector<int>&)>;

class MinimumCostToCutAStickSolution : public SolutionBase<Func> {
 public:
  MinimumCostToCutAStickSolution();
  int minCost(int n, std::vector<int>& cuts);
};

}  // namespace problem_1547
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_TO_CUT_A_STICK_H_
