#ifndef LEETCODE_PROBLEMS_MAXIMUM_SWAP_H_
#define LEETCODE_PROBLEMS_MAXIMUM_SWAP_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_670 {

class MaximumSwapSolution : public SolutionBase<std::function<int(int)>> {
 public:
  MaximumSwapSolution();

  int maximumSwap(int num);
};

}  // namespace leetcode::problem_670

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SWAP_H_
