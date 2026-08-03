#ifndef LEETCODE_PROBLEM_2079_WATERING_PLANTS_H_
#define LEETCODE_PROBLEM_2079_WATERING_PLANTS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2079 {

using Func = std::function<int(std::vector<int>&, int)>;

class WateringPlantsSolution : public SolutionBase<Func> {
 public:
  WateringPlantsSolution();

  int wateringPlants(std::vector<int>& plants, int capacity);
};

}  // namespace problem_2079
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2079_WATERING_PLANTS_H_
