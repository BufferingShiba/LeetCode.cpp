#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_3270 {

using Func = std::function<int(int, int, int)>;

class FindTheKeyOfTheNumbersSolution : public SolutionBase<Func> {
 public:
  FindTheKeyOfTheNumbersSolution();

  int generateKey(int num1, int num2, int num3);
};

}  // namespace leetcode::problem_3270
