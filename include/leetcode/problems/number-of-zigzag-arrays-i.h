#ifndef LEETCODE_PROBLEMS_NUMBER_OF_ZIGZAG_ARRAYS_I_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_ZIGZAG_ARRAYS_I_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_3699 {

using Func = std::function<int(int, int, int)>;

class NumberOfZigzagArraysISolution : public SolutionBase<Func> {
 public:
  NumberOfZigzagArraysISolution();

  int zigZagArrays(int n, int l, int r);
};

}  // namespace leetcode::problem_3699

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_ZIGZAG_ARRAYS_I_H__
