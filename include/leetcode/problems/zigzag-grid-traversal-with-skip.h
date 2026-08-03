#ifndef LEETCODE_PROBLEMS_ZIGZAG_GRID_TRAVERSAL_WITH_SKIP_H_
#define LEETCODE_PROBLEMS_ZIGZAG_GRID_TRAVERSAL_WITH_SKIP_H_

#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3417 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class ZigzagGridTraversalWithSkipSolution
    : public SolutionBase<Func> {
 public:
  ZigzagGridTraversalWithSkipSolution();

  std::vector<int> zigzagTraversal(std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_3417

#endif  // LEETCODE_PROBLEMS_ZIGZAG_GRID_TRAVERSAL_WITH_SKIP_H_
