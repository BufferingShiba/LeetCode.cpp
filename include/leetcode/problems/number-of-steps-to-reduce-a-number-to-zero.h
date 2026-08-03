#ifndef LEETCODE_NUMBER_OF_STEPS_TO_REDUCE_A_NUMBER_TO_ZERO_H__
#define LEETCODE_NUMBER_OF_STEPS_TO_REDUCE_A_NUMBER_TO_ZERO_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1342 {

using Func = std::function<int(int)>;

class NumberOfStepsToReduceANumberToZeroSolution : public SolutionBase<Func> {
 public:
  NumberOfStepsToReduceANumberToZeroSolution();

  int numberOfSteps(int num);
};

}  // namespace problem_1342
}  // namespace leetcode

#endif  // LEETCODE_NUMBER_OF_STEPS_TO_REDUCE_A_NUMBER_TO_ZERO_H__
