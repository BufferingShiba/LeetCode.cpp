#ifndef LEETCODE_PROBLEMS_MINIMUM_PREFIX_REMOVAL_TO_MAKE_ARRAY_STRICTLY_INCREASING_H_
#define LEETCODE_PROBLEMS_MINIMUM_PREFIX_REMOVAL_TO_MAKE_ARRAY_STRICTLY_INCREASING_H_

#include "leetcode/core.h"

namespace leetcode::problem_3818 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumPrefixRemovalToMakeArrayStrictlyIncreasingSolution : public SolutionBase<Func> {
 public:
  MinimumPrefixRemovalToMakeArrayStrictlyIncreasingSolution();

  int minimumPrefixLength(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3818

#endif  // LEETCODE_PROBLEMS_MINIMUM_PREFIX_REMOVAL_TO_MAKE_ARRAY_STRICTLY_INCREASING_H_
