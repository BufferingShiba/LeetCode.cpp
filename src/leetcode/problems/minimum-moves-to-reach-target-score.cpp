#include "leetcode/problems/minimum-moves-to-reach-target-score.h"

namespace leetcode::problem_2139 {

namespace {

int minMovesImpl(int target, int maxDoubles) {
  int moves = 0;
  while (target > 1 && maxDoubles > 0) {
    if (target % 2 == 0) {
      target /= 2;
      --maxDoubles;
      ++moves;
    } else {
      --target;
      ++moves;
    }
  }
  // Remaining distance to 1 is covered by increments.
  return moves + (target - 1);
}

}  // namespace

int MinimumMovesToReachTargetScoreSolution::minMoves(int target,
                                                      int maxDoubles) {
  return getSolution()(target, maxDoubles);
}

MinimumMovesToReachTargetScoreSolution::MinimumMovesToReachTargetScoreSolution() {
  setMetaInfo({.id = 2139,
               .title = "Minimum Moves to Reach Target Score",
               .url = "https://leetcode.com/problems/minimum-moves-to-reach-target-score/"});
  registerStrategy({.name = "GreedyReverse",
                    .expected = "Accepted",
                    .time_complexity = "O(log target)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Greedy"}},
                   minMovesImpl);
}

}  // namespace leetcode::problem_2139
