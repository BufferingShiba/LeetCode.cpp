#include "leetcode/problems/elimination-game.h"

namespace leetcode {
namespace problem_390 {

static int lastRemainingImpl(int n) {
  int head = 1;
  int step = 1;
  bool fromLeft = true;
  while (n > 1) {
    if (fromLeft || (n & 1)) {
      head += step;
    }
    step <<= 1;
    n >>= 1;
    fromLeft = !fromLeft;
  }
  return head;
}

int EliminationGameSolution::lastRemaining(int n) {
  return getSolution()(n);
}

EliminationGameSolution::EliminationGameSolution() {
  setMetaInfo(
      {.id = 390, .title = "Elimination Game",
       .url = "https://leetcode.com/problems/elimination-game/"});
  registerStrategy(
      {.name = "iterative",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Recursion"}},
      lastRemainingImpl);
  setDefaultStrategy();
}

}  // namespace problem_390
}  // namespace leetcode
