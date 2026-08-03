#ifndef LEETCODE_PROBLEMS_PATH_WITH_MINIMUM_EFFORT_H_
#define LEETCODE_PROBLEMS_PATH_WITH_MINIMUM_EFFORT_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1631 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class PathWithMinimumEffortSolution : public SolutionBase<Func> {
 public:
  PathWithMinimumEffortSolution();

  int minimumEffortPath(std::vector<std::vector<int>>& heights);
};

}  // namespace problem_1631
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PATH_WITH_MINIMUM_EFFORT_H_
