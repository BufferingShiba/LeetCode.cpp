#ifndef LEETCODE_PROBLEMS_MINIMUM_DISTANCE_TO_THE_TARGET_ELEMENT_H__
#define LEETCODE_PROBLEMS_MINIMUM_DISTANCE_TO_THE_TARGET_ELEMENT_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_1848 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class MinimumDistanceToTheTargetElementSolution
    : public SolutionBase<Func> {
 public:
  MinimumDistanceToTheTargetElementSolution();

  int getMinDistance(std::vector<int>& nums, int target, int start);
};

}  // namespace leetcode::problem_1848

#endif  // LEETCODE_PROBLEMS_MINIMUM_DISTANCE_TO_THE_TARGET_ELEMENT_H__
