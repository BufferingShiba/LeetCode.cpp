#ifndef LEETCODE_PROBLEM_486_PREDICT_THE_WINNER_H__
#define LEETCODE_PROBLEM_486_PREDICT_THE_WINNER_H__

#include "leetcode/core.h"

namespace leetcode::problem_486 {

using Func = std::function<bool(std::vector<int>&)>;

class PredictTheWinnerSolution : public SolutionBase<Func> {
 public:
  PredictTheWinnerSolution();

  bool predictTheWinner(std::vector<int>& nums);
};

}  // namespace leetcode::problem_486

#endif  // LEETCODE_PROBLEM_486_PREDICT_THE_WINNER_H__
