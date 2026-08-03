#ifndef LEETCODE_PROBLEMS_STONE_GAME_VIII_H_
#define LEETCODE_PROBLEMS_STONE_GAME_VIII_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1872 {

using Func = std::function<int(std::vector<int>&)>;

class StoneGameViiiSolution : public SolutionBase<Func> {
 public:
  StoneGameViiiSolution();

  int stoneGameVIII(std::vector<int>& stones);
};

}  // namespace leetcode::problem_1872

#endif  // LEETCODE_PROBLEMS_STONE_GAME_VIII_H_
