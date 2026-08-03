#ifndef LEETCODE_PROBLEMS_COUNT_SYMMETRIC_INTEGERS_H__
#define LEETCODE_PROBLEMS_COUNT_SYMMETRIC_INTEGERS_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode::problem_2843 {

using Func = std::function<int(int, int)>;

class CountSymmetricIntegersSolution : public SolutionBase<Func> {
 public:
  CountSymmetricIntegersSolution();

  int countSymmetricIntegers(int low, int high);
};

}  // namespace leetcode::problem_2843

#endif  // LEETCODE_PROBLEMS_COUNT_SYMMETRIC_INTEGERS_H__
