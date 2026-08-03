#ifndef LEETCODE_PROBLEM_2550_H_
#define LEETCODE_PROBLEM_2550_H_

#include "leetcode/core.h"

namespace leetcode::problem_2550 {

using Func = std::function<int(int)>;

class CountCollisionsOfMonkeysOnAPolygonSolution : public SolutionBase<Func> {
 public:
  CountCollisionsOfMonkeysOnAPolygonSolution();

  int monkeyMove(int n);
};

}  // namespace leetcode::problem_2550

#endif  // LEETCODE_PROBLEM_2550_H_
