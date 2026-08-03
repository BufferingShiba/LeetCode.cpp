#ifndef LEETCODE_PROBLEMS_TARGET_SUM_H__
#define LEETCODE_PROBLEMS_TARGET_SUM_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_494 {

using Func = std::function<int(std::vector<int>&, int)>;

class TargetSumSolution : public SolutionBase<Func> {
 public:
  TargetSumSolution();

  int findTargetSumWays(std::vector<int>& nums, int target);
};

}  // namespace leetcode::problem_494

#endif  // LEETCODE_PROBLEMS_TARGET_SUM_H__
