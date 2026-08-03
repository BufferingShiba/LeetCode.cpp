#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_REDUCE_AN_INTEGER_TO_0_H__
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_REDUCE_AN_INTEGER_TO_0_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2571 {

using Func = std::function<int(int)>;

class MinimumOperationsToReduceAnIntegerTo0Solution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToReduceAnIntegerTo0Solution();

  int minOperations(int n);
};

}  // namespace problem_2571
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_REDUCE_AN_INTEGER_TO_0_H__
