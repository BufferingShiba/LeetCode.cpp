#pragma once

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2367 {

using Func = std::function<int(std::vector<int>&, int)>;

class NumberOfArithmeticTripletsSolution : public SolutionBase<Func> {
 public:
  NumberOfArithmeticTripletsSolution();

  int arithmeticTriplets(std::vector<int>& nums, int diff);
};

}  // namespace leetcode::problem_2367
