#ifndef LEETCODE_PROBLEMS_FLOWER_PLANTING_WITH_NO_ADJACENT_H__
#define LEETCODE_PROBLEMS_FLOWER_PLANTING_WITH_NO_ADJACENT_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1042 {

using Func = std::function<std::vector<int>(int, std::vector<std::vector<int>>&)>;

class FlowerPlantingWithNoAdjacentSolution : public SolutionBase<Func> {
 public:
  FlowerPlantingWithNoAdjacentSolution();

  std::vector<int> gardenNoAdj(int n, std::vector<std::vector<int>>& paths);
};

}  // namespace leetcode::problem_1042

#endif  // LEETCODE_PROBLEMS_FLOWER_PLANTING_WITH_NO_ADJACENT_H__
