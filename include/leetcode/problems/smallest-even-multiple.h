#ifndef LEETCODE_PROBLEMS_SMALLEST_EVEN_MULTIPLE_H_
#define LEETCODE_PROBLEMS_SMALLEST_EVEN_MULTIPLE_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_2413 {

using Func = std::function<int(int)>;

class SmallestEvenMultipleSolution : public SolutionBase<Func> {
 public:
  SmallestEvenMultipleSolution();

  int smallestEvenMultiple(int n);
};

}  // namespace leetcode::problem_2413

#endif  // LEETCODE_PROBLEMS_SMALLEST_EVEN_MULTIPLE_H_
