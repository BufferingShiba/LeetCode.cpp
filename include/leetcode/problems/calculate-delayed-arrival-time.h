#ifndef LEETCODE_PROBLEMS_CALCULATE_DELAYED_ARRIVAL_TIME_H__
#define LEETCODE_PROBLEMS_CALCULATE_DELAYED_ARRIVAL_TIME_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode::problem_2651 {

using Func = std::function<int(int, int)>;

class CalculateDelayedArrivalTimeSolution
    : public SolutionBase<Func> {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime);

    static CalculateDelayedArrivalTimeSolution& shared();
};

}  // namespace leetcode::problem_2651

#endif  // LEETCODE_PROBLEMS_CALCULATE_DELAYED_ARRIVAL_TIME_H__
