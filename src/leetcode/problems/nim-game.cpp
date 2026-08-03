#include "leetcode/problems/nim-game.h"

namespace leetcode::problem_292 {
namespace {

bool canWinNimImpl(int n) { return n % 4 != 0; }

}  // namespace

NimGameSolution::NimGameSolution() {
  setMetaInfo({.id = 292,
               .title = "Nim Game",
               .url =
                   "https://leetcode.com/problems/nim-game/"});

  registerStrategy(
      {.name = "Modulo",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Game Theory"}},
      std::function<bool(int)>(canWinNimImpl));
}

bool NimGameSolution::canWinNim(int n) { return getSolution()(n); }

}  // namespace leetcode::problem_292
