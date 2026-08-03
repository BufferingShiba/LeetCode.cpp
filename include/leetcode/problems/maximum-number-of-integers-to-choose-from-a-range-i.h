#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_INTEGERS_TO_CHOOSE_FROM_A_RANGE_I_H_
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_INTEGERS_TO_CHOOSE_FROM_A_RANGE_I_H_

#include "leetcode/core.h"

namespace leetcode::problem_2554 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class MaximumNumberOfIntegersToChooseFromARangeISolution : public SolutionBase<Func> {
 public:
  MaximumNumberOfIntegersToChooseFromARangeISolution();

  int maxCount(std::vector<int>& banned, int n, int maxSum);
};

}  // namespace leetcode::problem_2554

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_INTEGERS_TO_CHOOSE_FROM_A_RANGE_I_H_
