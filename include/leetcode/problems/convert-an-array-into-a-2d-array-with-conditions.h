#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_2610 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<int>&)>;

class ConvertAnArrayIntoA2dArrayWithConditionsSolution : public SolutionBase<Func> {
 public:
  std::vector<std::vector<int>> findMatrix(std::vector<int>& nums);

  ConvertAnArrayIntoA2dArrayWithConditionsSolution();
};

}  // namespace leetcode::problem_2610
