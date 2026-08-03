#ifndef LEETCODE_PROBLEMS_JUMP_GAME_III_H_
#define LEETCODE_PROBLEMS_JUMP_GAME_III_H_

#include <functional>
#include <vector>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_1306 {

using Func = std::function<bool(std::vector<int>&, int)>;

class JumpGameIiiSolution : public SolutionBase<Func> {
 public:
  bool canReach(std::vector<int>& arr, int start);

  JumpGameIiiSolution();
};

}  // namespace problem_1306
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_JUMP_GAME_III_H_
