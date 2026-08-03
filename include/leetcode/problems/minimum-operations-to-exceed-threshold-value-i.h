#ifndef LEETCODE_PROBLEM_3065_H
#define LEETCODE_PROBLEM_3065_H

#include "leetcode/core.h"

namespace leetcode::problem_3065 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumOperationsToExceedThresholdValueISolution : public SolutionBase<Func> {
 public:
  MinimumOperationsToExceedThresholdValueISolution();
  int minOperations(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3065

#endif  // LEETCODE_PROBLEM_3065_H
