#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_X_AND_Y_EQUAL_H__
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_X_AND_Y_EQUAL_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2998 {

using Func = std::function<int(int, int)>;

class MinimumNumberOfOperationsToMakeXAndYEqualSolution
    : public SolutionBase<Func> {
 public:
  // The original LeetCode method.
  int minimumOperationsToMakeEqual(int x, int y);

  MinimumNumberOfOperationsToMakeXAndYEqualSolution();
};

}  // namespace problem_2998
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_X_AND_Y_EQUAL_H__
