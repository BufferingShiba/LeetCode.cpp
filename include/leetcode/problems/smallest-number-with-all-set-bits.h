#ifndef LEETCODE_PROBLEMS_SMALLEST_NUMBER_WITH_ALL_SET_BITS_H__
#define LEETCODE_PROBLEMS_SMALLEST_NUMBER_WITH_ALL_SET_BITS_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_3370 {

using Func = std::function<int(int)>;

class SmallestNumberWithAllSetBitsSolution
    : public SolutionBase<Func> {
 public:
  int smallestNumber(int n);

  SmallestNumberWithAllSetBitsSolution();
};

}  // namespace leetcode::problem_3370

#endif  // LEETCODE_PROBLEMS_SMALLEST_NUMBER_WITH_ALL_SET_BITS_H__
