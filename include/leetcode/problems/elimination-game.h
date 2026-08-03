#ifndef LEETCODE_PROBLEMS_ELIMINATION_GAME_H__
#define LEETCODE_PROBLEMS_ELIMINATION_GAME_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_390 {

using Func = std::function<int(int)>;

class EliminationGameSolution : public SolutionBase<Func> {
 public:
  int lastRemaining(int n);
  EliminationGameSolution();
};

}  // namespace problem_390
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ELIMINATION_GAME_H__
