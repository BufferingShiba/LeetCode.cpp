#ifndef LEETCODE_PROBLEMS_MINIMUM_CUTS_TO_DIVIDE_A_CIRCLE_H__
#define LEETCODE_PROBLEMS_MINIMUM_CUTS_TO_DIVIDE_A_CIRCLE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_2481 {

using Func = std::function<int(int)>;

class MinimumCutsToDivideACircleSolution
    : public SolutionBase<Func> {
 public:
  MinimumCutsToDivideACircleSolution();

  int numberOfCuts(int n) { return getSolution()(n); }
};

}  // namespace leetcode::problem_2481

#endif  // LEETCODE_PROBLEMS_MINIMUM_CUTS_TO_DIVIDE_A_CIRCLE_H__
