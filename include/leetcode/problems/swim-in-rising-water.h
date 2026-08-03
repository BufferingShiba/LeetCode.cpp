#ifndef LEETCODE_PROBLEMS_SWIM_IN_RISING_WATER_H__
#define LEETCODE_PROBLEMS_SWIM_IN_RISING_WATER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_778 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class SwimInRisingWaterSolution
    : public SolutionBase<Func> {
 public:
  SwimInRisingWaterSolution();

  int swimInWater(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_778
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SWIM_IN_RISING_WATER_H__
