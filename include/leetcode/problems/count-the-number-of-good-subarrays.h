#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_2537 {

using Func = std::function<long long(std::vector<int>&, int)>;

class CountTheNumberOfGoodSubarraysSolution : public SolutionBase<Func> {
 public:
  CountTheNumberOfGoodSubarraysSolution();

  long long countGood(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_2537
