#ifndef LEETCODE_PROBLEM_2089_H
#define LEETCODE_PROBLEM_2089_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2089 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class FindTargetIndicesAfterSortingArraySolution : public SolutionBase<Func> {
 public:
  FindTargetIndicesAfterSortingArraySolution();
  std::vector<int> targetIndices(std::vector<int>& nums, int target);
};

}  // namespace problem_2089
}  // namespace leetcode

#endif
