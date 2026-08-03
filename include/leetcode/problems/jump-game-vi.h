#ifndef LEETCODE_PROBLEMS_JUMP_GAME_VI_H__
#define LEETCODE_PROBLEMS_JUMP_GAME_VI_H__

#include <functional>
#include <vector>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1696 {

using Func = std::function<int(std::vector<int>&, int)>;

class JumpGameViSolution : public SolutionBase<Func> {
 public:
  JumpGameViSolution();
};

}  // namespace problem_1696
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_JUMP_GAME_VI_H__
