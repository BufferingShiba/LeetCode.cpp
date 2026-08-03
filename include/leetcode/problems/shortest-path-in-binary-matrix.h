#ifndef LEETCODE_PROBLEMS_SHORTEST_PATH_IN_BINARY_MATRIX_H__
#define LEETCODE_PROBLEMS_SHORTEST_PATH_IN_BINARY_MATRIX_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1091 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class ShortestPathInBinaryMatrixSolution
    : public SolutionBase<Func> {
 public:
  ShortestPathInBinaryMatrixSolution();

  int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid);

 private:
  // helper declarations if needed
};

}  // namespace problem_1091
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORTEST_PATH_IN_BINARY_MATRIX_H__
