#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_844 {

using Func = std::function<bool(std::string, std::string)>;

class BackspaceStringCompareSolution : public SolutionBase<Func> {
 public:
  BackspaceStringCompareSolution();

  bool backspaceCompare(std::string s, std::string t) {
    return getSolution()(std::move(s), std::move(t));
  }
};

}  // namespace leetcode::problem_844
