#include "leetcode/problems/divisor-game.h"

namespace leetcode {
namespace problem_1025 {

static bool divisorGameImpl(int n) {
  // Even → Alice wins; Odd → Alice loses (optimal play)
  return n % 2 == 0;
}

DivisorGameSolution::DivisorGameSolution() {
  setMetaInfo({.id = 1025,
               .title = "Divisor Game",
               .url = "https://leetcode.com/problems/divisor-game/"});

  registerStrategy(
      {.name = "Math",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Brainteaser", "Game Theory"}},
      divisorGameImpl);

  setDefaultStrategy();
}

bool DivisorGameSolution::divisorGame(int n) {
  return getSolution()(n);
}

}  // namespace problem_1025
}  // namespace leetcode
