#ifndef LEETCODE_PROBLEM_1326_MINIMUM_NUMBER_OF_TAPS_TO_OPEN_TO_WATER_A_GARDEN_H__
#define LEETCODE_PROBLEM_1326_MINIMUM_NUMBER_OF_TAPS_TO_OPEN_TO_WATER_A_GARDEN_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1326 {

using Func = std::function<int(int, std::vector<int>&)>;

class MinimumNumberOfTapsToOpenToWaterAGardenSolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfTapsToOpenToWaterAGardenSolution();

  int minTaps(int n, std::vector<int>& ranges) {
    return getSolution()(n, ranges);
  }
};

}  // namespace problem_1326
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1326_MINIMUM_NUMBER_OF_TAPS_TO_OPEN_TO_WATER_A_GARDEN_H__
