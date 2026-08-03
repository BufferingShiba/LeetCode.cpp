#pragma once

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1413 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumValueToGetPositiveStepByStepSumSolution
    : public SolutionBase<Func> {
 public:
  MinimumValueToGetPositiveStepByStepSumSolution();

  int minStartValue(std::vector<int>& nums);
};

}  // namespace leetcode::problem_1413
