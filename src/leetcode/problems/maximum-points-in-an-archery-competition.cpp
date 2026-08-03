#include "leetcode/problems/maximum-points-in-an-archery-competition.h"

namespace leetcode::problem_2212 {

static std::vector<int> maximumBobPointsImpl(int numArrows,
                                             std::vector<int>& aliceArrows) {
  int bestScore = -1;
  int bestMask = 0;

  for (int mask = 0; mask < (1 << 12); ++mask) {
    int need = 0;
    int score = 0;
    for (int k = 0; k < 12; ++k) {
      if (mask & (1 << k)) {
        need += aliceArrows[k] + 1;
        score += k;
      }
    }
    if (need <= numArrows && score > bestScore) {
      bestScore = score;
      bestMask = mask;
    }
  }

  std::vector<int> bobArrows(12, 0);
  int used = 0;
  for (int k = 0; k < 12; ++k) {
    if (bestMask & (1 << k)) {
      bobArrows[k] = aliceArrows[k] + 1;
      used += bobArrows[k];
    }
  }
  // Dump all remaining arrows into section 0 (score 0, harmless)
  bobArrows[0] += (numArrows - used);

  return bobArrows;
}

MaximumPointsInAnArcheryCompetitionSolution::
    MaximumPointsInAnArcheryCompetitionSolution() {
  setMetaInfo({.id = 2212,
               .title = "Maximum Points in an Archery Competition",
               .url = "https://leetcode.com/problems/maximum-points-in-an-archery-competition/"});
  registerStrategy(
      {.name = "Bitmask Enumeration",
       .expected = "Accepted",
       .time_complexity = "O(2^K * K)",
       .space_complexity = "O(K)",
       .tags = {"Array", "Backtracking", "Bit Manipulation", "Enumeration"}},
      maximumBobPointsImpl);
}

std::vector<int> MaximumPointsInAnArcheryCompetitionSolution::maximumBobPoints(
    int numArrows, std::vector<int>& aliceArrows) {
  return getSolution()(numArrows, aliceArrows);
}

}  // namespace leetcode::problem_2212
