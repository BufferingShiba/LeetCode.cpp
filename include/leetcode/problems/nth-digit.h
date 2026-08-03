#ifndef LEETCODE_PROBLEMS_NTH_DIGIT_H_
#define LEETCODE_PROBLEMS_NTH_DIGIT_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_400 {

using Func = std::function<int(int)>;

class NthDigitSolution : public SolutionBase<Func> {
 public:
  NthDigitSolution();

  int findNthDigit(int n);
};

}  // namespace leetcode::problem_400

#endif  // LEETCODE_PROBLEMS_NTH_DIGIT_H_
