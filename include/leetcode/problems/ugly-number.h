#ifndef LEETCODE_PROBLEMS_UGLY_NUMBER_H_
#define LEETCODE_PROBLEMS_UGLY_NUMBER_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_263 {

using Func = std::function<bool(int)>;

class UglyNumberSolution : public SolutionBase<Func> {
 public:
  UglyNumberSolution();
  bool isUgly(int n);
};

}  // namespace leetcode::problem_263

#endif  // LEETCODE_PROBLEMS_UGLY_NUMBER_H_
