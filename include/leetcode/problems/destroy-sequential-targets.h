#ifndef LEETCODE_PROBLEM_2453_H_
#define LEETCODE_PROBLEM_2453_H_

#include "leetcode/core.h"

namespace leetcode::problem_2453 {

using Func = std::function<int(std::vector<int>&, int)>;

class DestroySequentialTargetsSolution : public SolutionBase<Func> {
 public:
  DestroySequentialTargetsSolution();

  int destroyTargets(std::vector<int>& nums, int space);
};

}  // namespace leetcode::problem_2453

#endif  // LEETCODE_PROBLEM_2453_H_
