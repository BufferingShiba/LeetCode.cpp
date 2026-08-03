#ifndef LEETCODE_PROBLEM_3171_H
#define LEETCODE_PROBLEM_3171_H

#include "leetcode/core.h"

namespace leetcode::problem_3171 {

using Func = std::function<int(std::vector<int>&, int)>;

class FindSubarrayWithBitwiseOrClosestToKSolution : public SolutionBase<Func> {
 public:
  FindSubarrayWithBitwiseOrClosestToKSolution();

  int minimumDifference(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3171

#endif
