#ifndef LEETCODE_PROBLEMS_NEXT_GREATER_NUMERICALLY_BALANCED_NUMBER_H__
#define LEETCODE_PROBLEMS_NEXT_GREATER_NUMERICALLY_BALANCED_NUMBER_H__

#include "leetcode/core.h"

namespace leetcode::problem_2048 {

using Func = std::function<int(int)>;

class NextGreaterNumericallyBalancedNumberSolution : public SolutionBase<Func> {
 public:
  NextGreaterNumericallyBalancedNumberSolution();
  int nextBeautifulNumber(int n);
};

}  // namespace leetcode::problem_2048

#endif  // LEETCODE_PROBLEMS_NEXT_GREATER_NUMERICALLY_BALANCED_NUMBER_H__
