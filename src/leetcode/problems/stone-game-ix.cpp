#include "leetcode/problems/stone-game-ix.h"

#include <algorithm>
#include <cmath>
#include <vector>

namespace leetcode {
namespace problem_2029 {

static bool stoneGameIXImpl(std::vector<int>& stones) {
  int c0 = 0, c1 = 0, c2 = 0;
  for (int v : stones) {
    int r = v % 3;
    if (r == 0) ++c0;
    else if (r == 1) ++c1;
    else ++c2;
  }

  if (c0 % 2 == 0) {
    // Even number of 0-stones: they cancel out.
    // Alice wins iff both types of non-zero stones exist.
    return c1 >= 1 && c2 >= 1;
  } else {
    // Odd number of 0-stones: one extra pass favours the player
    // who can force a difference > 2 in the non-zero counts.
    return std::abs(c1 - c2) > 2;
  }
}

StoneGameIxSolution::StoneGameIxSolution() {
  setMetaInfo({.id = 2029,
               .title = "Stone Game IX",
               .url = "https://leetcode.com/problems/stone-game-ix/"});

  registerStrategy(
      {.name = "counting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Greedy", "Counting", "Game Theory"}},
      stoneGameIXImpl);
}

bool StoneGameIxSolution::stoneGameIX(std::vector<int>& stones) {
  return getSolution()(stones);
}

}  // namespace problem_2029
}  // namespace leetcode
