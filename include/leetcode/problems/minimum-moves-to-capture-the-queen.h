#ifndef LEETCODE_MINIMUM_MOVES_TO_CAPTURE_THE_QUEEN_H__
#define LEETCODE_MINIMUM_MOVES_TO_CAPTURE_THE_QUEEN_H__

#include "leetcode/core.h"

namespace leetcode::problem_3001 {

using Func = std::function<int(int, int, int, int, int, int)>;

class MinimumMovesToCaptureTheQueenSolution : public SolutionBase<Func> {
 public:
  MinimumMovesToCaptureTheQueenSolution();

  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f);
};

}  // namespace leetcode::problem_3001

#endif  // LEETCODE_MINIMUM_MOVES_TO_CAPTURE_THE_QUEEN_H__
