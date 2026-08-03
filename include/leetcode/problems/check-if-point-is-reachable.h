#ifndef LEETCODE_PROBLEMS_CHECK_IF_POINT_IS_REACHABLE_H_
#define LEETCODE_PROBLEMS_CHECK_IF_POINT_IS_REACHABLE_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2543 {

using Func = std::function<bool(int, int)>;

class CheckIfPointIsReachableSolution : public SolutionBase<Func> {
 public:
  CheckIfPointIsReachableSolution();

  bool isReachable(int targetX, int targetY);
};

}  // namespace problem_2543
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_POINT_IS_REACHABLE_H_
