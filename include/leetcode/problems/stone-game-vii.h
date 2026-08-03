#ifndef LEETCODE_PROBLEMS_STONE_GAME_VII_H__
#define LEETCODE_PROBLEMS_STONE_GAME_VII_H__

#include "leetcode/core.h"

namespace leetcode::problem_1690 {

using Func = std::function<int(std::vector<int>&)>;

class StoneGameViiSolution : public SolutionBase<Func> {
 public:
  StoneGameViiSolution();

  int stoneGameVII(std::vector<int>& stones);
};

}  // namespace leetcode::problem_1690

#endif  // LEETCODE_PROBLEMS_STONE_GAME_VII_H__
