#ifndef LEETCODE_PROBLEMS_BALANCED_K_FACTOR_DECOMPOSITION_H__
#define LEETCODE_PROBLEMS_BALANCED_K_FACTOR_DECOMPOSITION_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3669 {

using Func = std::function<std::vector<int>(int, int)>;

class BalancedKFactorDecompositionSolution
    : public SolutionBase<Func> {
 public:
  BalancedKFactorDecompositionSolution();

  std::vector<int> minDifference(int n, int k);
};

}  // namespace leetcode::problem_3669

#endif  // LEETCODE_PROBLEMS_BALANCED_K_FACTOR_DECOMPOSITION_H__
