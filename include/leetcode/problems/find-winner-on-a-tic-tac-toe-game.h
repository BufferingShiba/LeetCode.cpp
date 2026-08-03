#ifndef LEETCODE_PROBLEMS_FIND_WINNER_ON_A_TIC_TAC_TOE_GAME_H_
#define LEETCODE_PROBLEMS_FIND_WINNER_ON_A_TIC_TAC_TOE_GAME_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1275 {

using Func = std::function<std::string(std::vector<std::vector<int>>&)>;

class FindWinnerOnATicTacToeGameSolution
    : public SolutionBase<Func> {
 public:
  FindWinnerOnATicTacToeGameSolution();

  std::string tictactoe(std::vector<std::vector<int>>& moves);
};

}  // namespace leetcode::problem_1275

#endif  // LEETCODE_PROBLEMS_FIND_WINNER_ON_A_TIC_TAC_TOE_GAME_H_
