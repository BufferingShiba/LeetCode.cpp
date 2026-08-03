#ifndef LEETCODE_PROBLEMS_MAXIMUM_POINTS_IN_AN_ARCHERY_COMPETITION_H_
#define LEETCODE_PROBLEMS_MAXIMUM_POINTS_IN_AN_ARCHERY_COMPETITION_H_

#include "leetcode/core.h"

namespace leetcode::problem_2212 {

using Func = std::function<std::vector<int>(int, std::vector<int>&)>;

class MaximumPointsInAnArcheryCompetitionSolution : public SolutionBase<Func> {
 public:
  MaximumPointsInAnArcheryCompetitionSolution();
  std::vector<int> maximumBobPoints(int numArrows, std::vector<int>& aliceArrows);
};

}  // namespace leetcode::problem_2212

#endif  // LEETCODE_PROBLEMS_MAXIMUM_POINTS_IN_AN_ARCHERY_COMPETITION_H_
