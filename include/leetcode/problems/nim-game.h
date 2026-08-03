#ifndef LEETCODE_PROBLEMS_NIM_GAME_H__
#define LEETCODE_PROBLEMS_NIM_GAME_H__

#include "leetcode/core.h"

namespace leetcode::problem_292 {

class NimGameSolution : public SolutionBase<std::function<bool(int)>> {
 public:
  NimGameSolution();

  bool canWinNim(int n);
};

}  // namespace leetcode::problem_292

#endif  // LEETCODE_PROBLEMS_NIM_GAME_H__
