#ifndef LEETCODE_PROBLEMS_STONE_REMOVAL_GAME_H_
#define LEETCODE_PROBLEMS_STONE_REMOVAL_GAME_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3360 {

using Func = std::function<bool(int)>;

class StoneRemovalGameSolution : public SolutionBase<Func> {
 public:
  StoneRemovalGameSolution();
  bool canAliceWin(int n);
};

}  // namespace problem_3360
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_STONE_REMOVAL_GAME_H_
