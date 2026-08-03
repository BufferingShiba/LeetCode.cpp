#ifndef LEETCODE_PROBLEMS_REVERSE_BITS_H__
#define LEETCODE_PROBLEMS_REVERSE_BITS_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_190 {

using Func = std::function<int(int)>;

class ReverseBits : public SolutionBase<Func> {
 public:
  ReverseBits();
  int reverseBits(int n);
};

}  // namespace leetcode::problem_190

#endif  // LEETCODE_PROBLEMS_REVERSE_BITS_H__
