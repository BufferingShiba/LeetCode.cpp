#ifndef LEETCODE_PROBLEMS_TRAPPING_RAIN_WATER_II_H_
#define LEETCODE_PROBLEMS_TRAPPING_RAIN_WATER_II_H_

#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_407 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class TrappingRainWaterIiSolution : public SolutionBase<Func> {
 public:
  TrappingRainWaterIiSolution();

  int trapRainWater(std::vector<std::vector<int>>& heightMap);
};

}  // namespace leetcode::problem_407

#endif  // LEETCODE_PROBLEMS_TRAPPING_RAIN_WATER_II_H_
