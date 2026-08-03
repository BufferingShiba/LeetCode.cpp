#ifndef LEETCODE_PROBLEMS_FIND_PLAYERS_WITH_ZERO_OR_ONE_LOSSES_H_
#define LEETCODE_PROBLEMS_FIND_PLAYERS_WITH_ZERO_OR_ONE_LOSSES_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2225 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&)>;

class FindPlayersWithZeroOrOneLossesSolution : public SolutionBase<Func> {
 public:
  FindPlayersWithZeroOrOneLossesSolution();

  std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches);
};

}  // namespace problem_2225
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_PLAYERS_WITH_ZERO_OR_ONE_LOSSES_H_
