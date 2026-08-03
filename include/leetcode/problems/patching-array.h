#ifndef LEETCODE_PROBLEMS_PATCHING_ARRAY_H_
#define LEETCODE_PROBLEMS_PATCHING_ARRAY_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_330 {

using Func = std::function<int(std::vector<int>&, int)>;

class PatchingArraySolution : public SolutionBase<Func> {
 public:
  PatchingArraySolution();

  int minPatches(std::vector<int>& nums, int n);
};

}  // namespace leetcode::problem_330

#endif  // LEETCODE_PROBLEMS_PATCHING_ARRAY_H_
