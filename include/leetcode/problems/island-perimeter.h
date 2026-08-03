#ifndef LEETCODE_PROBLEMS_ISLAND_PERIMETER_H_
#define LEETCODE_PROBLEMS_ISLAND_PERIMETER_H_

#include "leetcode/core.h"

namespace leetcode::problem_463 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class IslandPerimeterSolution : public SolutionBase<Func> {
 public:
  IslandPerimeterSolution();

  int islandPerimeter(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_463

#endif  // LEETCODE_PROBLEMS_ISLAND_PERIMETER_H_
