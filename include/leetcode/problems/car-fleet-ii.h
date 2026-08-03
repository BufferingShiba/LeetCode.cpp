#ifndef LEETCODE_PROBLEMS_CAR_FLEET_II_H__
#define LEETCODE_PROBLEMS_CAR_FLEET_II_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1776 {

using Func = std::function<std::vector<double>(std::vector<std::vector<int>>&)>;

class CarFleetIiSolution : public SolutionBase<Func> {
 public:
  CarFleetIiSolution();

  std::vector<double> getCollisionTimes(std::vector<std::vector<int>>& cars);
};

}  // namespace problem_1776
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CAR_FLEET_II_H__
