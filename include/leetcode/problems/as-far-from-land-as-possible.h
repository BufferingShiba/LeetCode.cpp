#ifndef LEETCODE_PROBLEMS_AS_FAR_FROM_LAND_AS_POSSIBLE_H__
#define LEETCODE_PROBLEMS_AS_FAR_FROM_LAND_AS_POSSIBLE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_1162 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class AsFarFromLandAsPossibleSolution
    : public SolutionBase<Func> {
 public:
  AsFarFromLandAsPossibleSolution();
  int maxDistance(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_1162

#endif  // LEETCODE_PROBLEMS_AS_FAR_FROM_LAND_AS_POSSIBLE_H__
