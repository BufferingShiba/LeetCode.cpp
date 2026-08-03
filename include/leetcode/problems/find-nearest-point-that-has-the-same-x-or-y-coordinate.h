#ifndef LEETCODE_PROBLEMS_FIND_NEAREST_POINT_THAT_HAS_THE_SAME_X_OR_Y_COORDINATE_H__
#define LEETCODE_PROBLEMS_FIND_NEAREST_POINT_THAT_HAS_THE_SAME_X_OR_Y_COORDINATE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1779 {

using Func = std::function<int(int, int, std::vector<std::vector<int>>&)>;

class FindNearestPointThatHasTheSameXOrYCoordinateSolution
    : public SolutionBase<Func> {
 public:
  FindNearestPointThatHasTheSameXOrYCoordinateSolution();
  int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points);
};

}  // namespace problem_1779
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_NEAREST_POINT_THAT_HAS_THE_SAME_X_OR_Y_COORDINATE_H__
