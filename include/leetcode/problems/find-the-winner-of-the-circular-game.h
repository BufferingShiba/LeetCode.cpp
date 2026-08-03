#ifndef LEETCODE_PROBLEMS_FIND_THE_WINNER_OF_THE_CIRCULAR_GAME_H_
#define LEETCODE_PROBLEMS_FIND_THE_WINNER_OF_THE_CIRCULAR_GAME_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1823 {

using Func = std::function<int(int, int)>;

class FindTheWinnerOfTheCircularGameSolution : public SolutionBase<Func> {
 public:
  int findTheWinner(int n, int k);

  FindTheWinnerOfTheCircularGameSolution();
};

}  // namespace leetcode::problem_1823

#endif  // LEETCODE_PROBLEMS_FIND_THE_WINNER_OF_THE_CIRCULAR_GAME_H_
