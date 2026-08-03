#ifndef LEETCODE_PROBLEMS_STONE_GAME_IX_H_
#define LEETCODE_PROBLEMS_STONE_GAME_IX_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2029 {

using Func = std::function<bool(std::vector<int>&)>;

class StoneGameIxSolution : public SolutionBase<Func> {
 public:
  StoneGameIxSolution();

  bool stoneGameIX(std::vector<int>& stones);
};

}  // namespace problem_2029
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_STONE_GAME_IX_H_
