#ifndef LEETCODE_PROBLEMS_WATERING_PLANTS_II_H_
#define LEETCODE_PROBLEMS_WATERING_PLANTS_II_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2105 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class WateringPlantsIiSolution : public SolutionBase<Func> {
 public:
  WateringPlantsIiSolution();

  int minimumRefill(std::vector<int>& plants, int capacityA, int capacityB);
};

}  // namespace problem_2105
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_WATERING_PLANTS_II_H_
