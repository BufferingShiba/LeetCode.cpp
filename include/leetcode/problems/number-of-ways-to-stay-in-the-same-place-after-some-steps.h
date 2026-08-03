#ifndef LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_STAY_IN_THE_SAME_PLACE_AFTER_SOME_STEPS_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_STAY_IN_THE_SAME_PLACE_AFTER_SOME_STEPS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1269 {

using Func = std::function<int(int, int)>;

class NumberOfWaysToStayInTheSamePlaceAfterSomeStepsSolution
    : public SolutionBase<Func> {
 public:
  NumberOfWaysToStayInTheSamePlaceAfterSomeStepsSolution();

  int numWays(int steps, int arrLen);
};

}  // namespace problem_1269
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_STAY_IN_THE_SAME_PLACE_AFTER_SOME_STEPS_H_
