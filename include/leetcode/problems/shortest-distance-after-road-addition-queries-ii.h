#ifndef LEETCODE_PROBLEMS_SHORTEST_DISTANCE_AFTER_ROAD_ADDITION_QUERIES_II_H__
#define LEETCODE_PROBLEMS_SHORTEST_DISTANCE_AFTER_ROAD_ADDITION_QUERIES_II_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3244 {

using Func = std::function<std::vector<int>(int, std::vector<std::vector<int>>&)>;

class ShortestDistanceAfterRoadAdditionQueriesIiSolution
    : public SolutionBase<Func> {
 public:
  ShortestDistanceAfterRoadAdditionQueriesIiSolution();
};

}  // namespace problem_3244
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORTEST_DISTANCE_AFTER_ROAD_ADDITION_QUERIES_II_H__
