#ifndef LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_REARRANGE_STICKS_WITH_K_STICKS_VISIBLE_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_REARRANGE_STICKS_WITH_K_STICKS_VISIBLE_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_1866 {

using Func = std::function<int(int, int)>;

class NumberOfWaysToRearrangeSticksWithKSticksVisibleSolution : public SolutionBase<Func> {
 public:
  NumberOfWaysToRearrangeSticksWithKSticksVisibleSolution();
  int rearrangeSticks(int n, int k);
};

}  // namespace leetcode::problem_1866

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_REARRANGE_STICKS_WITH_K_STICKS_VISIBLE_H_
