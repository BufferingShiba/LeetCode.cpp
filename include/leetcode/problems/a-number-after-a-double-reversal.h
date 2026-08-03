#ifndef LEETCODE_PROBLEMS_A_NUMBER_AFTER_A_DOUBLE_REVERSAL_H__
#define LEETCODE_PROBLEMS_A_NUMBER_AFTER_A_DOUBLE_REVERSAL_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2119 {

using Func = std::function<bool(int)>;

class ANumberAfterADoubleReversalSolution
    : public SolutionBase<Func> {
 public:
  ANumberAfterADoubleReversalSolution();
  bool isSameAfterReversals(int num);
};

}  // namespace problem_2119
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_A_NUMBER_AFTER_A_DOUBLE_REVERSAL_H__
