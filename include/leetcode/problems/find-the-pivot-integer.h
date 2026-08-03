#ifndef LEETCODE_PROBLEMS_FIND_THE_PIVOT_INTEGER_H__
#define LEETCODE_PROBLEMS_FIND_THE_PIVOT_INTEGER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2485 {

using Func = std::function<int(int)>;

class FindThePivotIntegerSolution
    : public SolutionBase<Func> {
 public:
  FindThePivotIntegerSolution();

  int pivotInteger(int n);
};

}  // namespace problem_2485
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_PIVOT_INTEGER_H__
