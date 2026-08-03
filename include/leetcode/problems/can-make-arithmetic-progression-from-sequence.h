#pragma once

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1502 {

using Func = std::function<bool(std::vector<int>&)>;

class CanMakeArithmeticProgressionFromSequenceSolution
    : public SolutionBase<Func> {
 public:
  CanMakeArithmeticProgressionFromSequenceSolution();

  bool canMakeArithmeticProgression(std::vector<int>& arr);
};

}  // namespace leetcode::problem_1502
