#ifndef LEETCODE_PROBLEMS_SUM_OF_COMPATIBLE_NUMBERS_IN_RANGE_I_H__
#define LEETCODE_PROBLEMS_SUM_OF_COMPATIBLE_NUMBERS_IN_RANGE_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3954 {

using Func = std::function<int(int, int)>;

class SumOfCompatibleNumbersInRangeISolution
    : public SolutionBase<Func> {
 public:
  SumOfCompatibleNumbersInRangeISolution();

  int sumOfGoodIntegers(int n, int k);
};

}  // namespace leetcode::problem_3954

#endif  // LEETCODE_PROBLEMS_SUM_OF_COMPATIBLE_NUMBERS_IN_RANGE_I_H__
