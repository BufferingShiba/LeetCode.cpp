#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_2507 {

using Func = std::function<int(int)>;

class SmallestValueAfterReplacingWithSumOfPrimeFactorsSolution
    : public SolutionBase<Func> {
 public:
  SmallestValueAfterReplacingWithSumOfPrimeFactorsSolution();

  int smallestValue(int n);
};

}  // namespace leetcode::problem_2507
