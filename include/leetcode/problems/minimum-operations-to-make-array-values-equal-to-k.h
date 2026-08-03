#pragma once

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3375 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumOperationsToMakeArrayValuesEqualToKSolution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToMakeArrayValuesEqualToKSolution();

  int minOperations(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3375
