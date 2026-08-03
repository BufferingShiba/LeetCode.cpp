#ifndef LEETCODE_PROBLEM_2652_H_
#define LEETCODE_PROBLEM_2652_H_

#include "leetcode/core.h"

namespace leetcode::problem_2652 {

using Func = std::function<int(int)>;

class SumMultiplesSolution : public SolutionBase<Func> {
 public:
  SumMultiplesSolution();
  int sumOfMultiples(int n);
};

}  // namespace leetcode::problem_2652

#endif  // LEETCODE_PROBLEM_2652_H_
