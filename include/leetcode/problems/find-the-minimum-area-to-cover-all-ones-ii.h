#ifndef LEETCODE_PROBLEMS_FIND_THE_MINIMUM_AREA_TO_COVER_ALL_ONES_II_H__
#define LEETCODE_PROBLEMS_FIND_THE_MINIMUM_AREA_TO_COVER_ALL_ONES_II_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3197 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class FindTheMinimumAreaToCoverAllOnesIiSolution
    : public SolutionBase<Func> {
 public:
  FindTheMinimumAreaToCoverAllOnesIiSolution();

  int minimumSum(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_3197
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_MINIMUM_AREA_TO_COVER_ALL_ONES_II_H__
