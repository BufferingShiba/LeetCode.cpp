#ifndef LEETCODE_PROBLEMS_CONCATENATE_NON_ZERO_DIGITS_AND_MULTIPLY_BY_SUM_I_H__
#define LEETCODE_PROBLEMS_CONCATENATE_NON_ZERO_DIGITS_AND_MULTIPLY_BY_SUM_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3754 {

using Func = std::function<long long(int)>;

class ConcatenateNonZeroDigitsAndMultiplyBySumISolution
    : public SolutionBase<Func> {
 public:
  ConcatenateNonZeroDigitsAndMultiplyBySumISolution();
  long long sumAndMultiply(int n);
};

}  // namespace leetcode::problem_3754

#endif  // LEETCODE_PROBLEMS_CONCATENATE_NON_ZERO_DIGITS_AND_MULTIPLY_BY_SUM_I_H__
