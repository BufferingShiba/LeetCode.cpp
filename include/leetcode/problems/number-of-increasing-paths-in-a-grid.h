#ifndef LEETCODE_NUMBER_OF_INCREASING_PATHS_IN_A_GRID_H
#define LEETCODE_NUMBER_OF_INCREASING_PATHS_IN_A_GRID_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2328 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class NumberOfIncreasingPathsInAGridSolution : public SolutionBase<Func> {
 public:
  NumberOfIncreasingPathsInAGridSolution();

  int countPaths(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_2328
}  // namespace leetcode

#endif  // LEETCODE_NUMBER_OF_INCREASING_PATHS_IN_A_GRID_H
