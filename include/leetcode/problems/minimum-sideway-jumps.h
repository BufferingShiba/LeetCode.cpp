#ifndef LEETCODE_PROBLEMS_MINIMUM_SIDEWAY_JUMPS_H_
#define LEETCODE_PROBLEMS_MINIMUM_SIDEWAY_JUMPS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1824 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumSidewayJumpsSolution
    : public SolutionBase<Func> {
 public:
  MinimumSidewayJumpsSolution();

  int minSideJumps(std::vector<int>& obstacles);
};

}  // namespace problem_1824
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_SIDEWAY_JUMPS_H_
