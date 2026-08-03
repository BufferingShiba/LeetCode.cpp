#ifndef LEETCODE_PROBLEMS_SECOND_MINIMUM_TIME_TO_REACH_DESTINATION_H__
#define LEETCODE_PROBLEMS_SECOND_MINIMUM_TIME_TO_REACH_DESTINATION_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2045 {

using Func = std::function<int(int, std::vector<std::vector<int>>&, int, int)>;

class SecondMinimumTimeToReachDestinationSolution
    : public SolutionBase<Func> {
 public:
  SecondMinimumTimeToReachDestinationSolution();

  int secondMinimum(int n, std::vector<std::vector<int>>& edges, int time,
                    int change);
};

}  // namespace problem_2045
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SECOND_MINIMUM_TIME_TO_REACH_DESTINATION_H__
