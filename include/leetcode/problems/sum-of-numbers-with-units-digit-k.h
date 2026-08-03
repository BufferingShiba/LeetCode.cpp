#ifndef LEETCODE_PROBLEMS_SUM_OF_NUMBERS_WITH_UNITS_DIGIT_K_H__
#define LEETCODE_PROBLEMS_SUM_OF_NUMBERS_WITH_UNITS_DIGIT_K_H__

#include "leetcode/core.h"

namespace leetcode::problem_2310 {

class SumOfNumbersWithUnitsDigitKSolution
    : public SolutionBase<std::function<int(int, int)>> {
 public:
  using Func = std::function<int(int, int)>;

  SumOfNumbersWithUnitsDigitKSolution();

  int minimumNumbers(int num, int k);
};

}  // namespace leetcode::problem_2310

#endif  // LEETCODE_PROBLEMS_SUM_OF_NUMBERS_WITH_UNITS_DIGIT_K_H__
