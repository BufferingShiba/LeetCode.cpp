#pragma once
#include "leetcode/core.h"

namespace leetcode::problem_2549 {

using Func = std::function<int(int)>;

class CountDistinctNumbersOnBoardSolution : public SolutionBase<Func> {
 public:
  CountDistinctNumbersOnBoardSolution();

  int distinctIntegers(int n) {
    return getSolution()(n);
  }
};

}  // namespace leetcode::problem_2549
