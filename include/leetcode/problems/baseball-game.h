#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_682 {

using Func = std::function<int(std::vector<std::string>&)>;

class BaseballGameSolution : public SolutionBase<Func> {
 public:
  BaseballGameSolution();

  int calPoints(std::vector<std::string>& operations);
};

}  // namespace leetcode::problem_682
