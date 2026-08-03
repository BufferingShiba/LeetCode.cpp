#ifndef LEETCODE_PROBLEMS_FIND_NTH_SMALLEST_INTEGER_WITH_K_ONE_BITS_H__
#define LEETCODE_PROBLEMS_FIND_NTH_SMALLEST_INTEGER_WITH_K_ONE_BITS_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_3821 {

using Func = std::function<long long(long long, int)>;

class FindNthSmallestIntegerWithKOneBitsSolution
    : public SolutionBase<Func> {
 public:
  FindNthSmallestIntegerWithKOneBitsSolution();

  long long nthSmallest(long long n, int k);
};

}  // namespace leetcode::problem_3821

#endif  // LEETCODE_PROBLEMS_FIND_NTH_SMALLEST_INTEGER_WITH_K_ONE_BITS_H__
