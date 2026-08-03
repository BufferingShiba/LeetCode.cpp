#ifndef LEETCODE_PROBLEMS_CHECK_IF_GRID_SATISFIES_CONDITIONS_H_
#define LEETCODE_PROBLEMS_CHECK_IF_GRID_SATISFIES_CONDITIONS_H_

#include "leetcode/core.h"
#include <vector>

namespace leetcode {
namespace problem_3142 {

using Func = std::function<bool(std::vector<std::vector<int>>&)>;

class CheckIfGridSatisfiesConditionsSolution
    : public SolutionBase<Func> {
 public:
  CheckIfGridSatisfiesConditionsSolution();
};

}  // namespace problem_3142
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_GRID_SATISFIES_CONDITIONS_H_
