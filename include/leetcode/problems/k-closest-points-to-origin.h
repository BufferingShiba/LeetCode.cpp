#ifndef LEETCODE_PROBLEMS_K_CLOSEST_POINTS_TO_ORIGIN_H__
#define LEETCODE_PROBLEMS_K_CLOSEST_POINTS_TO_ORIGIN_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_973 {

using Func = std::function<std::vector<std::vector<int>>(
    std::vector<std::vector<int>>&, int)>;

class KClosestPointsToOriginSolution
    : public SolutionBase<Func> {
 public:
  KClosestPointsToOriginSolution();

  std::vector<std::vector<int>> kClosest(
      std::vector<std::vector<int>>& points, int k);
};

}  // namespace problem_973
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_K_CLOSEST_POINTS_TO_ORIGIN_H__
