#ifndef LEETCODE_PROBLEMS_DISTANCE_BETWEEN_BUS_STOPS_H__
#define LEETCODE_PROBLEMS_DISTANCE_BETWEEN_BUS_STOPS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1184 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class DistanceBetweenBusStopsSolution
    : public SolutionBase<Func> {
 public:
  DistanceBetweenBusStopsSolution();

  int distanceBetweenBusStops(std::vector<int>& distance, int start,
                              int destination);
};

}  // namespace leetcode::problem_1184

#endif  // LEETCODE_PROBLEMS_DISTANCE_BETWEEN_BUS_STOPS_H__
