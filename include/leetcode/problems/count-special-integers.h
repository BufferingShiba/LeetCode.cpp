#ifndef LEETCODE_PROBLEMS_COUNT_SPECIAL_INTEGERS_H__
#define LEETCODE_PROBLEMS_COUNT_SPECIAL_INTEGERS_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_2376 {

using Func = std::function<int(int)>;

class CountSpecialIntegersSolution : public SolutionBase<Func> {
 public:
  CountSpecialIntegersSolution();

  int countSpecialNumbers(int n);
};

}  // namespace leetcode::problem_2376

#endif  // LEETCODE_PROBLEMS_COUNT_SPECIAL_INTEGERS_H__
