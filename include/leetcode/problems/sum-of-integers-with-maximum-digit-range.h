#ifndef LEETCODE_PROBLEMS_SUM_OF_INTEGERS_WITH_MAXIMUM_DIGIT_RANGE_H__
#define LEETCODE_PROBLEMS_SUM_OF_INTEGERS_WITH_MAXIMUM_DIGIT_RANGE_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_3982 {

using Func = std::function<int(std::vector<int>&)>;

class SumOfIntegersWithMaximumDigitRangeSolution
    : public SolutionBase<Func> {
 public:
  SumOfIntegersWithMaximumDigitRangeSolution();
  int maxDigitRange(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3982

#endif  // LEETCODE_PROBLEMS_SUM_OF_INTEGERS_WITH_MAXIMUM_DIGIT_RANGE_H__
