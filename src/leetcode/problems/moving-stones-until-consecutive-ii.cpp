#include <algorithm>
#include <vector>

#include "leetcode/problems/moving-stones-until-consecutive-ii.h"

namespace leetcode::problem_1040 {

namespace {

std::vector<int> numMovesStonesIIImpl(std::vector<int>& stones) {
  const int n = static_cast<int>(stones.size());
  std::sort(stones.begin(), stones.end());

  // Maximum moves: fix either the two smallest or the two largest endpoints.
  const int maxMoves =
      std::max(stones[n - 2] - stones[0], stones[n - 1] - stones[1]) - (n - 2);

  // Minimum moves: sliding window of width n covering the most stones.
  int minMoves = n;  // at most n-1 steps; start with an upper bound
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j < n && stones[j] - stones[i] + 1 <= n) {
      ++j;
    }
    int stonesInWindow = j - i;      // window [i, j-1]
    int cost = n - stonesInWindow;   // empty slots inside the width-n window
    if (cost == 1 && stonesInWindow == n - 1 &&
        stones[j - 1] - stones[i] + 1 == n - 1) {
      // all but this window fully consecutive -> need 2 moves
      cost = 2;
    }
    minMoves = std::min(minMoves, cost);
  }

  return {minMoves, maxMoves};
}

}  // namespace

MovingStonesUntilConsecutiveIiSolution::MovingStonesUntilConsecutiveIiSolution() {
  setMetaInfo({.id = 1040,
               .title = "Moving Stones Until Consecutive II",
               .url = "https://leetcode.com/problems/moving-stones-until-consecutive-ii/"});
  registerStrategy(
      {.name = "sort",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Sliding Window", "Sorting"}},
      numMovesStonesIIImpl);
}

std::vector<int> MovingStonesUntilConsecutiveIiSolution::numMovesStonesII(
    std::vector<int>& stones) {
  return getSolution()(stones);
}

}  // namespace leetcode::problem_1040
