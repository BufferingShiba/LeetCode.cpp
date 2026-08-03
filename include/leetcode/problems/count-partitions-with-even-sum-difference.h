#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_3432 {

using Func = std::function<int(std::vector<int>&)>;

class CountPartitionsWithEvenSumDifferenceSolution : public SolutionBase<Func> {
 public:
  CountPartitionsWithEvenSumDifferenceSolution();
  int countPartitions(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3432
