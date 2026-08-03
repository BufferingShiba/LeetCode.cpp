#ifndef LEETCODE_PROBLEMS_COMBINATION_SUM_II_H_
#define LEETCODE_PROBLEMS_COMBINATION_SUM_II_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_40 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<int>&, int)>;

class CombinationSumIiSolution : public SolutionBase<Func> {
 public:
  CombinationSumIiSolution();

  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    return getSolution()(candidates, target);
  }
};

}  // namespace leetcode::problem_40

#endif  // LEETCODE_PROBLEMS_COMBINATION_SUM_II_H_
