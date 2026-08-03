#ifndef LEETCODE_PROBLEMS_COMBINATION_SUM_III_H_
#define LEETCODE_PROBLEMS_COMBINATION_SUM_III_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_216 {

using Func = std::function<std::vector<std::vector<int>>(int, int)>;

class CombinationSumIiiSolution : public SolutionBase<Func> {
 public:
  CombinationSumIiiSolution();

  std::vector<std::vector<int>> combinationSum3(int k, int n);
};

}  // namespace leetcode::problem_216

#endif  // LEETCODE_PROBLEMS_COMBINATION_SUM_III_H_
