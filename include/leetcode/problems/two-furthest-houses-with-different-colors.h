#ifndef LEETCODE_PROBLEMS_TWO_FURTHEST_HOUSES_WITH_DIFFERENT_COLORS_H__
#define LEETCODE_PROBLEMS_TWO_FURTHEST_HOUSES_WITH_DIFFERENT_COLORS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2078 {

using Func = std::function<int(std::vector<int>&)>;

class TwoFurthestHousesWithDifferentColorsSolution
    : public SolutionBase<Func> {
 public:
  TwoFurthestHousesWithDifferentColorsSolution();

  int maxDistance(std::vector<int>& colors);
};

}  // namespace leetcode::problem_2078

#endif  // LEETCODE_PROBLEMS_TWO_FURTHEST_HOUSES_WITH_DIFFERENT_COLORS_H__
