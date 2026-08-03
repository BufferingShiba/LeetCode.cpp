#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_MOVES_TO_KILL_ALL_PAWNS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_MOVES_TO_KILL_ALL_PAWNS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3283 {

using Func = std::function<int(int, int, std::vector<std::vector<int>>&)>;

class MaximumNumberOfMovesToKillAllPawnsSolution : public SolutionBase<Func> {
 public:
  MaximumNumberOfMovesToKillAllPawnsSolution();

  int maxMoves(int kx, int ky, std::vector<std::vector<int>>& positions);
};

}  // namespace problem_3283
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_MOVES_TO_KILL_ALL_PAWNS_H__
