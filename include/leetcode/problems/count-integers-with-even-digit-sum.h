#ifndef LEETCODE_PROBLEMS_COUNT_INTEGERS_WITH_EVEN_DIGIT_SUM_H__
#define LEETCODE_PROBLEMS_COUNT_INTEGERS_WITH_EVEN_DIGIT_SUM_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2180 {

using Func = std::function<int(int)>;

class CountIntegersWithEvenDigitSum : public SolutionBase<Func> {
 public:
  CountIntegersWithEvenDigitSum();

  int countEven(int num);
};

}  // namespace leetcode::problem_2180

#endif  // LEETCODE_PROBLEMS_COUNT_INTEGERS_WITH_EVEN_DIGIT_SUM_H__
