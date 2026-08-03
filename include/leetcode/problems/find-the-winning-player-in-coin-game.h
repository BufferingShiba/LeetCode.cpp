#ifndef LEETCODE_PROBLEMS_FIND_THE_WINNING_PLAYER_IN_COIN_GAME_H__
#define LEETCODE_PROBLEMS_FIND_THE_WINNING_PLAYER_IN_COIN_GAME_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_3222 {

using Func = std::function<std::string(int x, int y)>;

class FindTheWinningPlayerInCoinGameSolution
    : public SolutionBase<Func> {
 public:
  FindTheWinningPlayerInCoinGameSolution();

  std::string winningPlayer(int x, int y);
};

}  // namespace problem_3222
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_WINNING_PLAYER_IN_COIN_GAME_H__
