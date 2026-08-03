#ifndef LEETCODE_PROBLEM_1671_H__
#define LEETCODE_PROBLEM_1671_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1671 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumNumberOfRemovalsToMakeMountainArraySolution : public SolutionBase<Func> {
 public:
  MinimumNumberOfRemovalsToMakeMountainArraySolution();

  int minimumMountainRemovals(std::vector<int>& nums);
};

}  // namespace problem_1671
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1671_H__
