#pragma once
#include "leetcode/core.h"
#include <vector>

namespace leetcode::problem_3655 {
using Func = std::function<int(std::vector<int>&, std::vector<std::vector<int>>&)>;

class XorAfterRangeMultiplicationQueriesIiSolution : public SolutionBase<Func> {
 public:
  XorAfterRangeMultiplicationQueriesIiSolution();
  int xorAfterQueries(std::vector<int>& nums, std::vector<std::vector<int>>& queries);
};

}  // namespace leetcode::problem_3655
