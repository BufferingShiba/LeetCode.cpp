#ifndef LEETCODE_PROBLEM_153_H_
#define LEETCODE_PROBLEM_153_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_153 {

using Func = std::function<int(std::vector<int>&)>;

class FindMinimumInRotatedSortedArraySolution : public SolutionBase<Func> {
 public:
  FindMinimumInRotatedSortedArraySolution();

  int findMin(std::vector<int>& nums);
};

}  // namespace leetcode::problem_153

#endif  // LEETCODE_PROBLEM_153_H_
