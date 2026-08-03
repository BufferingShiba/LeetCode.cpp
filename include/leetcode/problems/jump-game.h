#ifndef LEETCODE_PROBLEMS_JUMP_GAME_H__
#define LEETCODE_PROBLEMS_JUMP_GAME_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_55 {

using Func = std::function<bool(std::vector<int>&)>;

class JumpGameSolution : public SolutionBase<Func> {
 public:
  JumpGameSolution();

  bool canJump(std::vector<int>& nums);
};

}  // namespace problem_55
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_JUMP_GAME_H__
