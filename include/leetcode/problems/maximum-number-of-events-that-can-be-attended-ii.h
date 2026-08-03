#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_EVENTS_THAT_CAN_BE_ATTENDED_II_H
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_EVENTS_THAT_CAN_BE_ATTENDED_II_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1751 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class MaximumNumberOfEventsThatCanBeAttendedIiSolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfEventsThatCanBeAttendedIiSolution();

  int maxValue(std::vector<std::vector<int>>& events, int k);
};

}  // namespace problem_1751
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_EVENTS_THAT_CAN_BE_ATTENDED_II_H
