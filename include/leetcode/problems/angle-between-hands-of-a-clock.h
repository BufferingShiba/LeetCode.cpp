#ifndef LEETCODE_PROBLEMS_ANGLE_BETWEEN_HANDS_OF_A_CLOCK_H_
#define LEETCODE_PROBLEMS_ANGLE_BETWEEN_HANDS_OF_A_CLOCK_H_

#include <functional>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_1344 {

using Func = std::function<double(int, int)>;

class AngleBetweenHandsOfAClockSolution : public SolutionBase<Func> {
 public:
  AngleBetweenHandsOfAClockSolution();

  double angleClock(int hour, int minutes) {
    return getSolution()(hour, minutes);
  }
};

}  // namespace problem_1344
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ANGLE_BETWEEN_HANDS_OF_A_CLOCK_H_
