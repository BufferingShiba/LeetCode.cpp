#include <vector>

#include "leetcode/problems/minimum-cost-to-move-chips-to-the-same-position.h"

namespace leetcode::problem_1217 {

namespace {

int minCostToMoveChipsImpl(std::vector<int>& position) {
  int odd = 0;
  int even = 0;
  for (int pos : position) {
    if (pos % 2 == 0) {
      ++even;
    } else {
      ++odd;
    }
  }
  return odd < even ? odd : even;
}

}  // namespace

MinimumCostToMoveChipsToTheSamePositionSolution::
    MinimumCostToMoveChipsToTheSamePositionSolution() {
  setMetaInfo({.id = 1217,
               .title = "Minimum Cost to Move Chips to The Same Position",
               .url = "https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/"});
  registerStrategy({.name = "ParityCount",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math", "Greedy"}},
                   minCostToMoveChipsImpl);
}

int MinimumCostToMoveChipsToTheSamePositionSolution::minCostToMoveChips(
    std::vector<int>& position) {
  return getSolution()(position);
}

}  // namespace leetcode::problem_1217
