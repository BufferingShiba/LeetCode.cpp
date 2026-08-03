#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_1525 {

using Func = std::function<int(std::string)>;

class NumberOfGoodWaysToSplitAStringSolution : public SolutionBase<Func> {
 public:
  NumberOfGoodWaysToSplitAStringSolution();

  int numSplits(std::string s);
};

}  // namespace leetcode::problem_1525
