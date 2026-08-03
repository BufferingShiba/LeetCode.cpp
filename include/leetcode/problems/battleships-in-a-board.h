#ifndef LEETCODE_PROBLEMS_BATTLESHIPS_IN_A_BOARD_H_
#define LEETCODE_PROBLEMS_BATTLESHIPS_IN_A_BOARD_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_419 {

using Func = std::function<int(std::vector<std::vector<char>>&)>;

class BattleshipsInABoardSolution : public SolutionBase<Func> {
 public:
  BattleshipsInABoardSolution();

  int countBattleships(std::vector<std::vector<char>>& board);
};

}  // namespace leetcode::problem_419

#endif  // LEETCODE_PROBLEMS_BATTLESHIPS_IN_A_BOARD_H_
