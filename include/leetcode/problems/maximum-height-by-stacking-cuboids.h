#ifndef LEETCODE_PROBLEMS_MAXIMUM_HEIGHT_BY_STACKING_CUBOIDS_H_
#define LEETCODE_PROBLEMS_MAXIMUM_HEIGHT_BY_STACKING_CUBOIDS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1691 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MaximumHeightByStackingCuboids : public SolutionBase<Func> {
 public:
  MaximumHeightByStackingCuboids();
  int maxHeight(std::vector<std::vector<int>>& cuboids);
};

}  // namespace problem_1691
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_HEIGHT_BY_STACKING_CUBOIDS_H_
