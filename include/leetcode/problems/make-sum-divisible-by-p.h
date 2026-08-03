#ifndef LEETCODE_PROBLEMS_MAKE_SUM_DIVISIBLE_BY_P_H_
#define LEETCODE_PROBLEMS_MAKE_SUM_DIVISIBLE_BY_P_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1590 {

using Func = std::function<int(std::vector<int>&, int)>;

class MakeSumDivisibleByPSolution : public SolutionBase<Func> {
 public:
  int minSubarray(std::vector<int>& nums, int p);

  MakeSumDivisibleByPSolution();
};

}  // namespace leetcode::problem_1590

#endif  // LEETCODE_PROBLEMS_MAKE_SUM_DIVISIBLE_BY_P_H_
