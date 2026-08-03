#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_MOVES_IN_A_GRID_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_MOVES_IN_A_GRID_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2684 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MaximumNumberOfMovesInAGrid : public SolutionBase<Func> {
 public:
  MaximumNumberOfMovesInAGrid();

  int maxMoves(std::vector<std::vector<int>>& grid);
};

class MaximumNumberOfMovesInAGridSolution : public MaximumNumberOfMovesInAGrid {
};

}  // namespace problem_2684
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_MOVES_IN_A_GRID_H__
