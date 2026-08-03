#ifndef LEETCODE_PROBLEMS_COUNT_OPERATIONS_TO_OBTAIN_ZERO_H__
#define LEETCODE_PROBLEMS_COUNT_OPERATIONS_TO_OBTAIN_ZERO_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2169 {

using Func = std::function<int(int, int)>;

class CountOperationsToObtainZeroSolution
    : public SolutionBase<Func> {
 public:
  CountOperationsToObtainZeroSolution();

  int countOperations(int num1, int num2);
};

}  // namespace problem_2169
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_OPERATIONS_TO_OBTAIN_ZERO_H__
