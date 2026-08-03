#ifndef LEETCODE_PROBLEMS_SMALLEST_DIVISIBLE_DIGIT_PRODUCT_I_H_
#define LEETCODE_PROBLEMS_SMALLEST_DIVISIBLE_DIGIT_PRODUCT_I_H_

#include "leetcode/core.h"

namespace leetcode::problem_3345 {

using Func = std::function<int(int, int)>;

class SmallestDivisibleDigitProductISolution : public SolutionBase<Func> {
 public:
  SmallestDivisibleDigitProductISolution();

  int smallestNumber(int n, int t);
};

}  // namespace leetcode::problem_3345

#endif  // LEETCODE_PROBLEMS_SMALLEST_DIVISIBLE_DIGIT_PRODUCT_I_H_
