#ifndef LEETCODE_PROBLEMS_POINTS_THAT_INTERSECT_WITH_CARS_H__
#define LEETCODE_PROBLEMS_POINTS_THAT_INTERSECT_WITH_CARS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2848 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class PointsThatIntersectWithCarsSolution
    : public SolutionBase<Func> {
 public:
  PointsThatIntersectWithCarsSolution();

  int numberOfPoints(std::vector<std::vector<int>>& nums);
};

}  // namespace problem_2848
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_POINTS_THAT_INTERSECT_WITH_CARS_H__
