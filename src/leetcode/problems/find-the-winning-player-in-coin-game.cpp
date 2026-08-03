#include "leetcode/problems/find-the-winning-player-in-coin-game.h"

namespace leetcode {
namespace problem_3222 {
namespace {

std::string winningPlayerImpl(int x, int y) {
  int turns = std::min(x, y / 4);
  // Alice 走奇数次回合（每回合消耗一组），若总回合数为奇数，Alice 走最后一回合后 Bob 输。
  return (turns % 2 == 1) ? "Alice" : "Bob";
}

}  // namespace

FindTheWinningPlayerInCoinGameSolution::FindTheWinningPlayerInCoinGameSolution() {
  setMetaInfo({.id = 3222,
               .title = "Find the Winning Player in Coin Game",
               .url = "https://leetcode.com/problems/find-the-winning-player-in-coin-game/"});

  registerStrategy({.name = "Math_GameTurnCount",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Simulation", "Game Theory"}},
                   winningPlayerImpl);
}

std::string FindTheWinningPlayerInCoinGameSolution::winningPlayer(int x, int y) {
  return getSolution()(x, y);
}

}  // namespace problem_3222
}  // namespace leetcode
