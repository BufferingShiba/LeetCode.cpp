#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_BALLS_IN_A_BOX_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_BALLS_IN_A_BOX_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1742 {

using Func = std::function<int(int, int)>;

class MaximumNumberOfBallsInABoxSolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfBallsInABoxSolution();

  int countBalls(int lowLimit, int highLimit);
};

}  // namespace problem_1742
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_BALLS_IN_A_BOX_H__
