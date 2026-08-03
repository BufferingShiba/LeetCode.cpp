#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_2566 {

using Func = std::function<int(int)>;

class MaximumDifferenceByRemappingADigitSolution : public SolutionBase<Func> {
 public:
  MaximumDifferenceByRemappingADigitSolution();

  int minMaxDifference(int num);
};

}  // namespace leetcode::problem_2566
