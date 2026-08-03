#ifndef LEETCODE_PROBLEMS_SQRTX_H__
#define LEETCODE_PROBLEMS_SQRTX_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode::problem_69 {

using Func = std::function<int(int)>;

class SqrtxSolution : public SolutionBase<Func> {
 public:
  SqrtxSolution();

  int mySqrt(int x);
};

}  // namespace leetcode::problem_69

#endif  // LEETCODE_PROBLEMS_SQRTX_H__
