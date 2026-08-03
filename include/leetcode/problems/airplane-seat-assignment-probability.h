#ifndef LEETCODE_PROBLEMS_AIRPLANE_SEAT_ASSIGNMENT_PROBABILITY_H__
#define LEETCODE_PROBLEMS_AIRPLANE_SEAT_ASSIGNMENT_PROBABILITY_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1227 {

using Func = std::function<double(int)>;

class AirplaneSeatAssignmentProbabilitySolution
    : public SolutionBase<Func> {
 public:
  AirplaneSeatAssignmentProbabilitySolution();

  double nthPersonGetsNthSeat(int n);
};

}  // namespace problem_1227
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_AIRPLANE_SEAT_ASSIGNMENT_PROBABILITY_H__
