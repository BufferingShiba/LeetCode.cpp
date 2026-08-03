#ifndef LEETCODE_PROBLEMS_DIVISOR_GAME_H_
#define LEETCODE_PROBLEMS_DIVISOR_GAME_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1025 {

using Func = std::function<bool(int)>;

class DivisorGameSolution : public SolutionBase<Func> {
 public:
  DivisorGameSolution();

  bool divisorGame(int n);
};

}  // namespace problem_1025
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DIVISOR_GAME_H_
