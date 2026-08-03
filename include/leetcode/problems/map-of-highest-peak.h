#ifndef LEETCODE_PROBLEMS_MAP_OF_HIGHEST_PEAK_H__
#define LEETCODE_PROBLEMS_MAP_OF_HIGHEST_PEAK_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1765 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&)>;

class MapOfHighestPeakSolution : public SolutionBase<Func> {
 public:
  MapOfHighestPeakSolution();

  std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater);
};

}  // namespace leetcode::problem_1765

#endif  // LEETCODE_PROBLEMS_MAP_OF_HIGHEST_PEAK_H__
