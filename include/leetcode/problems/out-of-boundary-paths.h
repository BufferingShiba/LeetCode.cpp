#ifndef LEETCODE_PROBLEMS_OUT_OF_BOUNDARY_PATHS_H_
#define LEETCODE_PROBLEMS_OUT_OF_BOUNDARY_PATHS_H_

#include <functional>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_576 {

using Func = std::function<int(int, int, int, int, int)>;

class OutOfBoundaryPathsSolution : public SolutionBase<Func> {
 public:
  OutOfBoundaryPathsSolution();

  int findPaths(int m, int n, int maxMove, int startRow, int startColumn);
};

}  // namespace problem_576
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_OUT_OF_BOUNDARY_PATHS_H_
