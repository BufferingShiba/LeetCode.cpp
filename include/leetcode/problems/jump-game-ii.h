#ifndef LEETCODE_PROBLEMS_JUMP_GAME_II_H__
#define LEETCODE_PROBLEMS_JUMP_GAME_II_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_45 {

using Func = std::function<int(std::vector<int>&)>;

class JumpGameIiSolution : public SolutionBase<Func> {
 public:
  JumpGameIiSolution();
  int jump(std::vector<int>& nums);
};

}  // namespace problem_45
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_JUMP_GAME_II_H__
