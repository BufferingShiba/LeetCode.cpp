#ifndef LEETCODE_PROBLEMS_FROG_JUMP_H_
#define LEETCODE_PROBLEMS_FROG_JUMP_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_403 {

using Func = std::function<bool(std::vector<int>&)>;

class FrogJumpSolution : public SolutionBase<Func> {
 public:
  FrogJumpSolution();

  bool canCross(std::vector<int>& stones);
};

}  // namespace problem_403
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FROG_JUMP_H_
