#ifndef LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_WINNING_PLAYERS_H__
#define LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_WINNING_PLAYERS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3238 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class FindTheNumberOfWinningPlayersSolution : public SolutionBase<Func> {
 public:
  FindTheNumberOfWinningPlayersSolution();

  int winningPlayerCount(int n, std::vector<std::vector<int>>& pick);
};

}  // namespace problem_3238
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_NUMBER_OF_WINNING_PLAYERS_H__
