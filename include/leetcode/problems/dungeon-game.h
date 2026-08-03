#ifndef LEETCODE_PROBLEMS_DUNGEON_GAME_H__
#define LEETCODE_PROBLEMS_DUNGEON_GAME_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_174 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class DungeonGameSolution : public SolutionBase<Func> {
 public:
  DungeonGameSolution();

  int calculateMinimumHP(std::vector<std::vector<int>>& dungeon);
};

}  // namespace leetcode::problem_174

#endif  // LEETCODE_PROBLEMS_DUNGEON_GAME_H__
