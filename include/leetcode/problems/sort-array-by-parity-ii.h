#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_922 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class SortArrayByParityIiSolution : public SolutionBase<Func> {
 public:
  SortArrayByParityIiSolution();

  std::vector<int> sortArrayByParityII(std::vector<int>& nums);
};

}  // namespace leetcode::problem_922
