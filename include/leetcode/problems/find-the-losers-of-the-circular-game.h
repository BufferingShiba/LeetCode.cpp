#ifndef LEETCODE_PROBLEMS_FIND_THE_LOSERS_OF_THE_CIRCULAR_GAME_H_
#define LEETCODE_PROBLEMS_FIND_THE_LOSERS_OF_THE_CIRCULAR_GAME_H_

#include "leetcode/core.h"

namespace leetcode::problem_2682 {

using Func = std::function<std::vector<int>(int, int)>;

class FindTheLosersOfTheCircularGameSolution : public SolutionBase<Func> {
 public:
  FindTheLosersOfTheCircularGameSolution();

  std::vector<int> circularGameLosers(int n, int k);
};

}  // namespace leetcode::problem_2682

#endif  // LEETCODE_PROBLEMS_FIND_THE_LOSERS_OF_THE_CIRCULAR_GAME_H_
