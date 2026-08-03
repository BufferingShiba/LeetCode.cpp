#ifndef LEETCODE_PROBLEMS_CHECK_DIVISIBILITY_BY_DIGIT_SUM_AND_PRODUCT_H_
#define LEETCODE_PROBLEMS_CHECK_DIVISIBILITY_BY_DIGIT_SUM_AND_PRODUCT_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_3622 {

using Func = std::function<bool(int)>;

class CheckDivisibilityByDigitSumAndProductSolution
    : public SolutionBase<Func> {
 public:
  CheckDivisibilityByDigitSumAndProductSolution();

  bool checkDivisibility(int n);
};

}  // namespace leetcode::problem_3622

#endif  // LEETCODE_PROBLEMS_CHECK_DIVISIBILITY_BY_DIGIT_SUM_AND_PRODUCT_H_
