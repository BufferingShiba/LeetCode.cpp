#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_1466 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class ReorderRoutesToMakeAllPathsLeadToTheCityZeroSolution : public SolutionBase<Func> {
 public:
  ReorderRoutesToMakeAllPathsLeadToTheCityZeroSolution();

  int minReorder(int n, std::vector<std::vector<int>>& connections);
};

}  // namespace leetcode::problem_1466
