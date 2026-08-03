#ifndef LEETCODE_PROBLEMS_MINIMUM_REMOVALS_TO_ACHIEVE_TARGET_XOR_H__
#define LEETCODE_PROBLEMS_MINIMUM_REMOVALS_TO_ACHIEVE_TARGET_XOR_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3877 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumRemovalsToAchieveTargetXorSolution
    : public SolutionBase<Func> {
 public:
  MinimumRemovalsToAchieveTargetXorSolution();

  int minRemovals(std::vector<int>& nums, int target);
};

}  // namespace leetcode::problem_3877

#endif  // LEETCODE_PROBLEMS_MINIMUM_REMOVALS_TO_ACHIEVE_TARGET_XOR_H__
